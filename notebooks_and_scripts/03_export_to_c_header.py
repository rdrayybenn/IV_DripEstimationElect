"""
03_export_to_c_header.py
========================
Transpilation Script: Scikit-Learn .joblib Model -> C Header for ESP32 TinyML
Project: IV_DripEstimationElect (Pampanga State University - CpE-ELECT 3)

Pipeline Specification (per Portfolio Section C & Main Findings):
1. Loads winning trained regressor artifact from models/winning_model.joblib.
2. Loads feature normalization parameters from data/processed/scaler_params.json.
3. Transpiles model weights, bias, and Min-Max scaling vectors into pure C arrays.
4. Generates a standalone, deterministic C99 header:
   best_iv_model_20261125_020948_539740.h
5. Exports header to models/ and mirrors it into firmware/Elect_System/ for immediate
   compilation in the Arduino / PlatformIO ESP32 firmware sketch.
"""

import os
import shutil
import json
import argparse
import joblib
import numpy as np


HEADER_FILENAME = "best_iv_model_20261125_020948_539740.h"


def export_to_c_header(model_path: str = "models/winning_model.joblib",
                       scaler_path: str = "data/processed/scaler_params.json",
                       output_header_path: str = os.path.join("models", HEADER_FILENAME),
                       firmware_dest_dir: str = "firmware/Elect_System"):
    """Transpiles model weights and scaler vectors to a pure C header file."""
    print("=" * 70)
    print("TRANSPILING WINNING MODEL (.joblib) TO C HEADER FOR ESP32")
    print("=" * 70)
    
    if not os.path.exists(model_path):
        raise FileNotFoundError(f"Model file {model_path} not found. Run 02_train_and_evaluate.py first.")
        
    model = joblib.load(model_path)
    
    # Extract coefficients and bias
    if hasattr(model, "coef_"):
        weights = model.coef_.flatten()
        bias = float(model.intercept_)
    else:
        raise ValueError("Model does not have coef_ / intercept_ attributes for linear C transpilation.")
        
    feature_count = len(weights)
    print(f"Loaded model: {type(model).__name__} with {feature_count} features. Bias: {bias:.4f}")
    
    # Load or generate scaler vectors
    if os.path.exists(scaler_path):
        with open(scaler_path, "r") as f:
            scaler_data = json.load(f)
        scale_vec = scaler_data.get("scale", [1.0] * feature_count)
        min_vec = scaler_data.get("min", [0.0] * feature_count)
    else:
        print("[WARN] Scaler JSON not found. Defaulting to identity scaling.")
        scale_vec = [1.0] * feature_count
        min_vec = [0.0] * feature_count
        
    # Format C arrays
    def format_float_array(arr, indent=4, per_line=6):
        lines = []
        line = " " * indent
        for idx, val in enumerate(arr):
            line += f"{float(val):.7e}f, "
            if (idx + 1) % per_line == 0 and (idx + 1) < len(arr):
                lines.append(line)
                line = " " * indent
        if line.strip():
            lines.append(line)
        return "\n".join(lines)

    c_header_content = f"""/**
 * ==============================================================================
 * Automatically generated C Header for ESP32 TinyML Inference
 * Model ID: {HEADER_FILENAME}
 * Project:  IV_DripEstimationElect (Pampanga State University - CpE-ELECT 3)
 * Target:   ESP32 Microcontroller (Tensilica Xtensa 32-bit LX6)
 * Features: 30 time-steps @ 1Hz x 2 features (filtered weight, dW/dt) = {feature_count} inputs
 * Output:   Continuous scalar Time-to-Empty (TTE in seconds / minutes)
 * ==============================================================================
 */

#ifndef BEST_IV_MODEL_H
#define BEST_IV_MODEL_H

#ifdef __cplusplus
extern "C" {{
#endif

#include <math.h>

#define IV_MODEL_WINDOW_STEPS    30
#define IV_MODEL_NUM_FEATURES    2
#define IV_MODEL_FEATURE_COUNT   {feature_count}

// Pre-fitted Min-Max normalization vectors: x_scaled = x * scale + min
static const float IV_SCALER_SCALE[{feature_count}] = {{
{format_float_array(scale_vec)}
}};

static const float IV_SCALER_MIN[{feature_count}] = {{
{format_float_array(min_vec)}
}};

// Linear Regressor Weights (Transpiled from {type(model).__name__})
static const float IV_MODEL_WEIGHTS[{feature_count}] = {{
{format_float_array(weights)}
}};

static const float IV_MODEL_BIAS = {bias:.7e}f;

/**
 * Executes embedded sequence regression inference.
 * @param raw_features Array of {feature_count} unnormalized floats (chronological [w0, dw0, w1, dw1, ...])
 * @return Predicted remaining Time-to-Empty (TTE) in seconds.
 */
static inline float iv_model_predict_seconds(const float* raw_features) {{
    if (!raw_features) return 0.0f;

    float predicted_tte = IV_MODEL_BIAS;
    for (int i = 0; i < IV_MODEL_FEATURE_COUNT; ++i) {{
        // Apply Min-Max normalization
        float scaled_feature = raw_features[i] * IV_SCALER_SCALE[i] + IV_SCALER_MIN[i];
        // Accumulate dot product
        predicted_tte += scaled_feature * IV_MODEL_WEIGHTS[i];
    }}

    // TTE cannot be negative
    if (predicted_tte < 0.0f) {{
        predicted_tte = 0.0f;
    }}
    return predicted_tte;
}}

/**
 * Convenience wrapper returning predicted TTE in minutes.
 * @param raw_features Array of {feature_count} unnormalized floats.
 * @return Predicted TTE in minutes.
 */
static inline float iv_model_predict_minutes(const float* raw_features) {{
    return iv_model_predict_seconds(raw_features) / 60.0f;
}}

#ifdef __cplusplus
}}
#endif

#endif // BEST_IV_MODEL_H
"""

    os.makedirs(os.path.dirname(output_header_path), exist_ok=True)
    with open(output_header_path, "w") as f:
        f.write(c_header_content)
    print(f"Exported primary header to: {os.path.abspath(output_header_path)}")
    
    # Mirror into firmware directory
    if firmware_dest_dir:
        os.makedirs(firmware_dest_dir, exist_ok=True)
        firmware_header_path = os.path.join(firmware_dest_dir, HEADER_FILENAME)
        shutil.copy2(output_header_path, firmware_header_path)
        print(f"Mirrored header into firmware: {os.path.abspath(firmware_header_path)}")
        
    print("[SUCCESS] C header transpilation complete.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Transpile Model to C Header")
    parser.add_argument("--model_path", type=str, default="models/winning_model.joblib")
    parser.add_argument("--scaler_path", type=str, default="data/processed/scaler_params.json")
    parser.add_argument("--output_header", type=str, default=os.path.join("models", HEADER_FILENAME))
    parser.add_argument("--firmware_dest", type=str, default="firmware/Elect_System")
    args = parser.parse_args()
    
    export_to_c_header(args.model_path, args.scaler_path, args.output_header, args.firmware_dest)
