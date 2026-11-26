"""
03_export_to_c_header.py
========================
Transpilation Script: Scikit-Learn .joblib -> ESP32 C Header (.h)
Project: IV_DripEstimationElect (Pampanga State University - CpE-ELECT 3)

Integrates directly with Converter/joblib_to_h.py:
1. Loads models/winning_model.joblib.
2. Invokes export_header() from Converter/joblib_to_h.py to transpile the model.
3. Exports C header: best_iv_model_20261125_020948_539740.h to models/.
4. Mirrors header to firmware/Elect_System/ for compilation with Elect_System.ino.
"""

import os
import sys
import shutil
import argparse
import joblib

# Add project root to sys.path to import Converter
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))
try:
    from Converter.joblib_to_h import export_header
except ImportError:
    export_header = None


HEADER_FILENAME = "best_iv_model_20261125_020948_539740.h"


def run_export(model_path: str = "models/winning_model.joblib",
               output_path: str = os.path.join("models", HEADER_FILENAME),
               firmware_dir: str = "firmware/Elect_System"):
    """Transpiles the winning model using Converter/joblib_to_h.py."""
    print("=" * 70)
    print("TRANSPILING WINNING MODEL VIA CONVERTER (joblib_to_h.py)")
    print("=" * 70)
    
    if not os.path.exists(model_path):
        print(f"[WARN] {model_path} not found. Keeping existing C header.")
        return
        
    model = joblib.load(model_path)
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    
    if export_header is not None:
        exporter_used = export_header(model, output_path, function_name="predict_model")
        print(f"[SUCCESS] Exported using {exporter_used} to: {os.path.abspath(output_path)}")
    else:
        print("[WARN] Could not import export_header from Converter.joblib_to_h. Keeping verified header.")
        
    # Synchronize to firmware folder
    if os.path.exists(output_path):
        os.makedirs(firmware_dir, exist_ok=True)
        fw_target = os.path.join(firmware_dir, HEADER_FILENAME)
        shutil.copy2(output_path, fw_target)
        print(f"[MIRRORED] Synchronized into firmware: {os.path.abspath(fw_target)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Transpile Model to C Header")
    parser.add_argument("--model_path", type=str, default="models/winning_model.joblib")
    parser.add_argument("--output_path", type=str, default=os.path.join("models", HEADER_FILENAME))
    parser.add_argument("--firmware_dir", type=str, default="firmware/Elect_System")
    args = parser.parse_args()
    
    run_export(args.model_path, args.output_path, args.firmware_dir)
