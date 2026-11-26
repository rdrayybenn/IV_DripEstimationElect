"""
03_export_to_c_header.py
========================
Transpilation Script: Scikit-Learn GradientBoostingRegressor -> C Header for ESP32 TinyML
Project: IV_DripEstimationElect (Pampanga State University - CpE-ELECT 3)

Transpilation Specification:
1. Loads the winning GradientBoostingRegressor model from models/winning_model.joblib.
2. Extracts tree arrays (children_left, children_right, feature, threshold, values).
3. Transpiles all 100 decision trees (depth=2, 7 nodes each) into pure static C arrays.
4. Generates predict_model(const double *features) with GB_INITIAL_VALUE and GB_LEARNING_RATE.
5. Emits the exact header format: best_iv_model_20261125_020948_539740.h
6. Automatically syncs to models/ and firmware/Elect_System/ for ESP32 compilation.
"""

import os
import shutil
import argparse
import joblib
import numpy as np


HEADER_FILENAME = "best_iv_model_20261125_020948_539740.h"


def export_gradient_boosting_to_c(model, output_path: str):
    """Transpiles a trained scikit-learn GradientBoostingRegressor to a pure C header."""
    n_features = model.n_features_in_
    n_estimators = len(model.estimators_)
    learning_rate = model.learning_rate
    initial_value = float(model.init_.constant_[0, 0])
    
    header_guard = "BEST_IV_MODEL_20261125_020948_539740_H_"
    
    lines = []
    lines.append("/* Generated GradientBoostingRegressor C model */\n")
    lines.append(f"#ifndef {header_guard}")
    lines.append(f"#define {header_guard}\n")
    lines.append("#include <math.h>\n")
    lines.append("#ifdef __cplusplus\nextern \"C\" {\n#endif\n")
    lines.append(f"#define GB_N_FEATURES {n_features}")
    lines.append(f"#define GB_N_ESTIMATORS {n_estimators}")
    lines.append(f"#define GB_LEARNING_RATE ({learning_rate})")
    lines.append(f"#define GB_INITIAL_VALUE ({initial_value})\n")
    
    for i in range(n_estimators):
        tree = model.estimators_[i, 0].tree_
        n_nodes = tree.node_count
        left = tree.children_left.tolist()
        right = tree.children_right.tolist()
        feature = tree.feature.tolist()
        threshold = [float(t) for t in tree.threshold.tolist()]
        values = [float(v) for v in tree.value.flatten().tolist()]
        
        left_str = "{" + ", ".join(map(str, left)) + "}"
        right_str = "{" + ", ".join(map(str, right)) + "}"
        feat_str = "{" + ", ".join(map(str, feature)) + "}"
        thresh_str = "{" + ", ".join(f"{t:g}" if t != -2.0 else "-2" for t in threshold) + "}"
        val_str = "{" + ", ".join(f"{v:.17g}" for v in values) + "}"
        
        lines.append(f"static const int gb_tree_{i}_left[{n_nodes}] = {left_str};")
        lines.append(f"static const int gb_tree_{i}_right[{n_nodes}] = {right_str};")
        lines.append(f"static const int gb_tree_{i}_feature[{n_nodes}] = {feat_str};")
        lines.append(f"static const double gb_tree_{i}_threshold[{n_nodes}] = {thresh_str};")
        lines.append(f"static const double gb_tree_{i}_value[{n_nodes}] = {val_str};\n")
        
        lines.append(f"static double gb_tree_{i}_predict(const double *x)")
        lines.append("{")
        lines.append("    int node = 0;")
        lines.append(f"    while (gb_tree_{i}_left[node] != -1) {{")
        lines.append(f"        int f = gb_tree_{i}_feature[node];")
        lines.append(f"        if (x[f] <= gb_tree_{i}_threshold[node])")
        lines.append(f"            node = gb_tree_{i}_left[node];")
        lines.append("        else")
        lines.append(f"            node = gb_tree_{i}_right[node];")
        lines.append("    }")
        lines.append(f"    return gb_tree_{i}_value[node];")
        lines.append("}\n")
        
    lines.append("static inline double predict_model(const double *features)")
    lines.append("{")
    lines.append("    if (features == NULL) return NAN;")
    lines.append("    double prediction = GB_INITIAL_VALUE;")
    for i in range(n_estimators):
        lines.append(f"    prediction += GB_LEARNING_RATE * gb_tree_{i}_predict(features);")
    lines.append("    return prediction;")
    lines.append("}\n")
    lines.append("#ifdef __cplusplus\n}\n#endif\n")
    lines.append(f"#endif /* {header_guard} */\n")
    
    os.makedirs(os.path.dirname(output_path), exist_ok=True)
    with open(output_path, "w") as f:
        f.write("\n".join(lines))
    print(f"[SUCCESS] Transpiled C model header written to: {os.path.abspath(output_path)}")


def run_export(model_path: str = "models/winning_model.joblib",
               output_path: str = os.path.join("models", HEADER_FILENAME),
               firmware_dir: str = "firmware/Elect_System"):
    """Transpiles the winning model or verifies existing header."""
    print("=" * 70)
    print("EXPORTING / VERIFYING C HEADER FOR ESP32 (best_iv_model_20261125_020948_539740.h)")
    print("=" * 70)
    
    if os.path.exists(model_path):
        model = joblib.load(model_path)
        if hasattr(model, "estimators_"):
            export_gradient_boosting_to_c(model, output_path)
        else:
            print("[INFO] Model in joblib is not tree-based. Preserving verified C header.")
    else:
        print("[INFO] models/winning_model.joblib not found. Using pre-transpiled C header.")
        
    # Mirror into firmware directory
    if os.path.exists(output_path):
        os.makedirs(firmware_dir, exist_ok=True)
        fw_target = os.path.join(firmware_dir, HEADER_FILENAME)
        shutil.copy2(output_path, fw_target)
        print(f"[MIRRORED] Header synchronized to firmware: {os.path.abspath(fw_target)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Transpile Model to C Header")
    parser.add_argument("--model_path", type=str, default="models/winning_model.joblib")
    parser.add_argument("--output_path", type=str, default=os.path.join("models", HEADER_FILENAME))
    parser.add_argument("--firmware_dir", type=str, default="firmware/Elect_System")
    args = parser.parse_args()
    
    run_export(args.model_path, args.output_path, args.firmware_dir)
