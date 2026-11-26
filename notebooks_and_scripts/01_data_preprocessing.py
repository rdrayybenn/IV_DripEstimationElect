"""
01_data_preprocessing.py
========================
IV Drip Depletion Forecasting Preprocessing Pipeline
Project: IV_DripEstimationElect (Pampanga State University - CpE-ELECT 3)

Pipeline Specification (per Portfolio Section B):
1. Load raw numerical time-series CSVs ([timestamp, elapsed_time, current_weight, ...]).
2. 3-sample moving median filter (k=3) to suppress transient HX711 load-cell spikes.
3. Resample/align to uniform 1 Hz time grid.
4. Calculate rate of mass change dW/dt (g/s).
5. Segment into 30-second sliding windows with 15-second step size (output window shape: (30, 2)).
6. Strictly partition by complete independent physical drainage runs (Runs 1-4: Train, Run 5: Val, 8-hr: Test).
7. Min-Max normalization fitted strictly on training data to prevent temporal data leakage.
8. Export processed arrays (.npz) and scaler parameters to data/processed/.
"""

import os
import glob
import json
import argparse
import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler


def apply_median_filter(series: pd.Series, kernel_size: int = 3) -> np.ndarray:
    """Applies a moving median filter (k=3) to suppress transient spikes."""
    return series.rolling(window=kernel_size, center=True, min_periods=1).median().values


def resample_to_1hz(df: pd.DataFrame, max_duration: int = None):
    """
    Interpolates and aligns non-uniform sensor readings to a strictly uniform 1 Hz grid
    based on elapsed_time (seconds).
    """
    df = df.drop_duplicates(subset=['elapsed_time']).sort_values('elapsed_time')
    
    max_t = int(df['elapsed_time'].max())
    if max_duration is not None:
        max_t = min(max_t, max_duration)
        df = df[df['elapsed_time'] <= max_duration]
        
    grid_t = np.arange(0, max_t + 1, dtype=np.int32)
    
    # 3-sample median filtered weight
    filtered_w = apply_median_filter(df['current_weight'], kernel_size=3)
    
    # Linear interpolation onto uniform 1 Hz grid
    interp_weight = np.interp(grid_t, df['elapsed_time'], filtered_w)
    interp_target = np.interp(grid_t, df['elapsed_time'], df['remaining_time'])
    
    # Rate of mass change dW/dt (finite gradient in g/s)
    dw_dt = np.gradient(interp_weight, grid_t)
    
    return grid_t, interp_weight, dw_dt, interp_target


def extract_sliding_windows(weight_arr: np.ndarray, dw_arr: np.ndarray, target_arr: np.ndarray,
                           window_size: int = 30, step_size: int = 15):
    """
    Segments 1 Hz sequences into sliding temporal windows of shape (window_size, 2)
    where features are [filtered_weight, dW_dt] and target is Remaining Time-to-Empty (TTE).
    """
    n_samples = len(weight_arr)
    windows = []
    targets = []
    
    for start in range(0, n_samples - window_size + 1, step_size):
        end = start + window_size
        # (30, 2) window
        feat_window = np.column_stack([weight_arr[start:end], dw_arr[start:end]])
        windows.append(feat_window)
        # Target evaluated at the latest time step of the window
        targets.append(target_arr[end - 1])
        
    return np.array(windows, dtype=np.float32), np.array(targets, dtype=np.float32)


def process_dataset(raw_dir: str, processed_dir: str, window_size: int = 30, step_size: int = 15):
    """Executes the full preprocessing pipeline across all runs and splits."""
    os.makedirs(processed_dir, exist_ok=True)
    print("=" * 70)
    print("IV DRIP PREPROCESSING PIPELINE (Median Filter k=3, 10Hz->1Hz, (30,2) Windows)")
    print("=" * 70)
    
    # Locate run files
    run_files = sorted(glob.glob(os.path.join(raw_dir, "iv_drip_12hr_run*.csv")))
    test_8hr_file = os.path.join(raw_dir, "iv_drip_dataset8hrs.csv")
    
    if not run_files:
        # Fallback to alternate directory if not found in data/raw
        run_files = sorted(glob.glob("CSVElectLogger/official_testRuns/iv_drip_12hr_run*.csv"))
        test_8hr_file = "CSVElectLogger/iv_drip_dataset8hrs.csv"
        
    print(f"Found {len(run_files)} training/validation runs.")
    print(f"8-hr test file: {test_8hr_file}")
    
    train_windows, train_targets = [], []
    val_windows, val_targets = [], []
    
    # Runs 1 to 4: Training split; Run 5: Validation split
    for i, path in enumerate(run_files, 1):
        run_name = os.path.basename(path)
        print(f"Processing {run_name} ...")
        df = pd.read_csv(path)
        t, w, dw, target = resample_to_1hz(df)
        X_win, y_win = extract_sliding_windows(w, dw, target, window_size, step_size)
        
        if i < 5:  # Runs 1 to 4
            train_windows.append(X_win)
            train_targets.append(y_win)
        else:      # Run 5
            val_windows.append(X_win)
            val_targets.append(y_win)
            
    X_train = np.concatenate(train_windows, axis=0)
    y_train = np.concatenate(train_targets, axis=0)
    
    if val_windows:
        X_val = np.concatenate(val_windows, axis=0)
        y_val = np.concatenate(val_targets, axis=0)
    else:
        # If run 5 wasn't present, slice last 20% of train
        split_idx = int(0.8 * len(X_train))
        X_val, y_val = X_train[split_idx:], y_train[split_idx:]
        X_train, y_train = X_train[:split_idx], y_train[:split_idx]
        
    print(f"Extraction complete:")
    print(f"  X_train shape: {X_train.shape}, y_train shape: {y_train.shape}")
    print(f"  X_val shape:   {X_val.shape}, y_val shape:   {y_val.shape}")
    
    # Process 8-hour independent test run
    if os.path.exists(test_8hr_file):
        print(f"Processing 8-hour test dataset: {test_8hr_file} ...")
        df_8hr = pd.read_csv(test_8hr_file)
        t_8, w_8, dw_8, target_8 = resample_to_1hz(df_8hr, max_duration=28800)
        X_8hr, y_8hr = extract_sliding_windows(w_8, dw_8, target_8, window_size, step_size)
        print(f"  X_8hr shape:   {X_8hr.shape}, y_8hr shape:   {y_8hr.shape}")
    else:
        X_8hr, y_8hr = None, None
        
    # Min-Max Normalization fitted strictly on training data
    # Flatten (N, 30, 2) -> (N, 60) for scaler fitting
    scaler = MinMaxScaler(feature_range=(0.0, 1.0))
    X_train_flat = X_train.reshape(len(X_train), -1)
    scaler.fit(X_train_flat)
    
    X_train_scaled = scaler.transform(X_train_flat).reshape(X_train.shape)
    X_val_scaled = scaler.transform(X_val.reshape(len(X_val), -1)).reshape(X_val.shape)
    
    if X_8hr is not None:
        X_8hr_scaled = scaler.transform(X_8hr.reshape(len(X_8hr), -1)).reshape(X_8hr.shape)
    else:
        X_8hr_scaled = None
        
    # Save processed .npz files
    np.savez_compressed(
        os.path.join(processed_dir, "train_windows.npz"),
        X_raw=X_train,
        X_scaled=X_train_scaled,
        y=y_train
    )
    np.savez_compressed(
        os.path.join(processed_dir, "val_windows.npz"),
        X_raw=X_val,
        X_scaled=X_val_scaled,
        y=y_val
    )
    if X_8hr is not None:
        np.savez_compressed(
            os.path.join(processed_dir, "8hr_test_windows.npz"),
            X_raw=X_8hr,
            X_scaled=X_8hr_scaled,
            y=y_8hr
        )
        
    # Save scaler parameters as JSON for C header export / ESP32 deployment
    scaler_params = {
        "data_min": scaler.data_min_.tolist(),
        "data_max": scaler.data_max_.tolist(),
        "scale": scaler.scale_.tolist(),
        "min": scaler.min_.tolist(),
        "window_size": window_size,
        "step_size": step_size,
        "n_features": 2
    }
    with open(os.path.join(processed_dir, "scaler_params.json"), "w") as f:
        json.dump(scaler_params, f, indent=4)
        
    print(f"\n[SUCCESS] Preprocessing completed successfully.")
    print(f"Artifacts saved in: {os.path.abspath(processed_dir)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="IV Drip Preprocessing Pipeline")
    parser.add_argument("--raw_dir", type=str, default="data/raw", help="Path to raw CSV directory")
    parser.add_argument("--processed_dir", type=str, default="data/processed", help="Path to output processed directory")
    parser.add_argument("--window_size", type=int, default=30, help="Sliding window size (seconds)")
    parser.add_argument("--step_size", type=int, default=15, help="Window step size (seconds)")
    args = parser.parse_args()
    
    process_dataset(args.raw_dir, args.processed_dir, args.window_size, args.step_size)
