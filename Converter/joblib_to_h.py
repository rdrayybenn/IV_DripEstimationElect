import os
import re
import tkinter as tk
from tkinter import filedialog, messagebox, scrolledtext, ttk

import joblib
import numpy as np

try:
    import m2cgen as m2c
except ImportError:
    m2c = None


# ============================================================
# MODEL DETECTION
# ============================================================

def is_estimator(obj):
    """Check whether an object is a fitted scikit-learn estimator."""

    if obj is None:
        return False

    if not type(obj).__module__.startswith("sklearn"):
        return False

    if not callable(getattr(obj, "predict", None)):
        return False

    attributes = [
        "n_features_in_",
        "estimators_",
        "coef_",
        "tree_",
        "support_vectors_",
        "classes_"
    ]

    return any(hasattr(obj, attr) for attr in attributes)


def inspect_object(obj, path="root", results=None, visited=None, depth=0):
    """Find estimators inside dictionaries, lists, and tuples."""

    if results is None:
        results = []

    if visited is None:
        visited = set()

    if depth > 20 or id(obj) in visited:
        return results

    visited.add(id(obj))

    if is_estimator(obj):
        results.append({
            "path": path,
            "model": obj,
            "type": type(obj).__name__
        })
        return results

    if isinstance(obj, dict):
        for key, value in obj.items():
            inspect_object(
                value,
                f"{path} -> [{key!r}]",
                results,
                visited,
                depth + 1
            )

    elif isinstance(obj, (list, tuple)):
        for index, value in enumerate(obj):
            inspect_object(
                value,
                f"{path} -> [{index}]",
                results,
                visited,
                depth + 1
            )

    return results


# ============================================================
# MODEL INFORMATION
# ============================================================

def describe_model(model):

    lines = [
        f"Model type: {type(model).__name__}",
        f"Module: {type(model).__module__}",
        f"Input features: {getattr(model, 'n_features_in_', 'Unknown')}"
    ]

    if hasattr(model, "estimators_"):
        lines.append(
            f"Number of estimators: {len(model.estimators_)}"
        )

    if hasattr(model, "learning_rate"):
        lines.append(
            f"Learning rate: {model.learning_rate}"
        )

    if hasattr(model, "feature_importances_"):
        lines.append("Feature importances: Available")

    if hasattr(model, "classes_"):
        lines.append(
            f"Classes: {model.classes_}"
        )

    if hasattr(model, "steps"):
        lines.append("\nPipeline steps:")

        for name, step in model.steps:
            lines.append(
                f"  {name}: {type(step).__name__}"
            )

        lines.append(
            "\nPipeline preprocessing must be implemented separately."
        )

    return "\n".join(lines)


# ============================================================
# C CODE FORMATTING
# ============================================================

def c_double(value):

    value = float(value)

    if np.isnan(value):
        return "NAN"

    if np.isposinf(value):
        return "INFINITY"

    if np.isneginf(value):
        return "(-INFINITY)"

    return format(value, ".17g")


def c_int(value):
    return str(int(value))


def safe_guard(filename):

    name = os.path.basename(filename).upper()
    name = re.sub(r"[^A-Z0-9]", "_", name)

    if name[0].isdigit():
        name = "MODEL_" + name

    return name + "_"


# ============================================================
# GRADIENT BOOSTING REGRESSOR EXPORTER
# ============================================================

def export_gradient_boosting_regressor(
    model,
    output_path,
    function_name="predict_model"
):

    from sklearn.ensemble import GradientBoostingRegressor

    if not isinstance(model, GradientBoostingRegressor):
        raise TypeError(
            "Model must be GradientBoostingRegressor."
        )

    if not hasattr(model, "estimators_"):
        raise ValueError("Model has not been trained.")

    if getattr(model, "n_outputs_", 1) != 1:
        raise ValueError(
            "Only single-output regression is supported."
        )

    if model.init_ is None:
        initial_value = 0.0

    elif hasattr(model.init_, "constant_"):
        initial_value = float(
            np.asarray(model.init_.constant_).ravel()[0]
        )

    else:
        raise ValueError(
            "Custom initial estimators are not supported. "
            "Only built-in constant initialization or init='zero' "
            "can be exported."
        )

    learning_rate = float(model.learning_rate)
    n_features = int(model.n_features_in_)

    estimators = model.estimators_

    if estimators.ndim != 2 or estimators.shape[1] != 1:
        raise ValueError(
            "Unexpected estimator array shape."
        )

    tree_count = len(estimators)

    if tree_count == 0:
        raise ValueError("No trained trees found.")

    guard = safe_guard(output_path)

    lines = [
        "/* Generated GradientBoostingRegressor C model */",
        "",
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#include <math.h>",
        "",
        "#ifdef __cplusplus",
        'extern "C" {',
        "#endif",
        "",
        f"#define GB_N_FEATURES {n_features}",
        f"#define GB_N_ESTIMATORS {tree_count}",
        f"#define GB_LEARNING_RATE ({c_double(learning_rate)})",
        f"#define GB_INITIAL_VALUE ({c_double(initial_value)})",
        ""
    ]

    # Generate every decision tree.

    for tree_index in range(tree_count):

        estimator = estimators[tree_index, 0]
        tree = estimator.tree_

        left = tree.children_left
        right = tree.children_right
        feature = tree.feature
        threshold = tree.threshold
        values = tree.value[:, 0, 0]

        node_count = tree.node_count

        arrays = [
            ("left", "int", left, c_int),
            ("right", "int", right, c_int),
            ("feature", "int", feature, c_int),
            ("threshold", "double", threshold, c_double),
            ("value", "double", values, c_double)
        ]

        for name, c_type, data, formatter in arrays:

            formatted = ", ".join(
                formatter(value) for value in data
            )

            lines.append(
                f"static const {c_type} "
                f"gb_tree_{tree_index}_{name}"
                f"[{node_count}] = {{{formatted}}};"
            )

        lines.extend([
            "",
            f"static double gb_tree_{tree_index}_predict("
            "const double *x)",
            "{",
            "    int node = 0;",
            f"    while (gb_tree_{tree_index}_left[node] != -1) {{",
            f"        int f = gb_tree_{tree_index}_feature[node];",
            f"        if (x[f] <= gb_tree_{tree_index}_threshold[node])",
            f"            node = gb_tree_{tree_index}_left[node];",
            "        else",
            f"            node = gb_tree_{tree_index}_right[node];",
            "    }",
            f"    return gb_tree_{tree_index}_value[node];",
            "}",
            ""
        ])

    # Generate the final prediction function.

    lines.extend([
        f"static inline double {function_name}("
        "const double *features)",
        "{",
        "    if (features == NULL) return NAN;",
        "    double prediction = GB_INITIAL_VALUE;"
    ])

    for tree_index in range(tree_count):

        lines.append(
            f"    prediction += GB_LEARNING_RATE * "
            f"gb_tree_{tree_index}_predict(features);"
        )

    lines.extend([
        "    return prediction;",
        "}",
        "",
        "#ifdef __cplusplus",
        "}",
        "#endif",
        "",
        f"#endif /* {guard} */",
        ""
    ])

    with open(output_path, "w", encoding="utf-8") as file:
        file.write("\n".join(lines))


# ============================================================
# GENERAL MODEL EXPORTER
# ============================================================

def export_header(model, output_path, function_name):

    from sklearn.ensemble import GradientBoostingRegressor

    if not re.fullmatch(
        r"[A-Za-z_][A-Za-z0-9_]*",
        function_name
    ):
        raise ValueError("Invalid C function name.")

    # Direct Gradient Boosting export.

    if isinstance(model, GradientBoostingRegressor):

        export_gradient_boosting_regressor(
            model,
            output_path,
            function_name
        )

        return "GradientBoostingRegressor C exporter"

    # Pipelines need separate preprocessing implementation.

    if hasattr(model, "steps"):
        raise TypeError(
            "Pipeline export is not supported. "
            "Preprocessing steps must be implemented separately."
        )

    # Other models use m2cgen.

    if m2c is None:
        raise RuntimeError(
            "m2cgen is not installed. Run:\n"
            "python -m pip install m2cgen"
        )

    if not is_estimator(model):
        raise TypeError("Unsupported model.")

    generated_code = m2c.export_to_c(
        model,
        function_name=function_name
    )

    guard = safe_guard(output_path)

    header = f"""
/* Generated using m2cgen */

#ifndef {guard}
#define {guard}

#ifdef __cplusplus
extern "C" {{
#endif

{generated_code}

#ifdef __cplusplus
}}
#endif

#endif /* {guard} */
"""

    with open(output_path, "w", encoding="utf-8") as file:
        file.write(header)

    return "m2cgen exporter"


# ============================================================
# TKINTER GUI
# ============================================================

class JoblibToHApp:

    def __init__(self, root):

        self.root = root

        self.root.title("Joblib to C Header Converter")
        self.root.geometry("850x680")
        self.root.minsize(700, 550)

        self.loaded_object = None
        self.models = []
        self.selected_model = None
        self.model_path = None

        self.create_interface()

    def create_interface(self):

        container = tk.Frame(
            self.root,
            padx=20,
            pady=15
        )

        container.pack(fill="both", expand=True)

        tk.Label(
            container,
            text="Joblib to C Header Converter",
            font=("Segoe UI", 18, "bold")
        ).pack(anchor="w")

        tk.Label(
            container,
            text="Load, inspect, and export trained machine learning models."
        ).pack(anchor="w", pady=(3, 15))

        # File selection.

        file_frame = tk.Frame(container)
        file_frame.pack(fill="x")

        self.path_var = tk.StringVar(
            value="No model selected"
        )

        tk.Entry(
            file_frame,
            textvariable=self.path_var,
            state="readonly"
        ).pack(side="left", fill="x", expand=True)

        tk.Button(
            file_frame,
            text="Browse",
            command=self.load_model
        ).pack(side="left", padx=(8, 0))

        # Model selection.

        tk.Label(
            container,
            text="Detected Models",
            font=("Segoe UI", 10, "bold")
        ).pack(anchor="w", pady=(15, 5))

        self.model_var = tk.StringVar()

        self.model_combo = ttk.Combobox(
            container,
            textvariable=self.model_var,
            state="readonly"
        )

        self.model_combo.pack(fill="x")

        self.model_combo.bind(
            "<<ComboboxSelected>>",
            self.select_model
        )

        # Model information.

        tk.Label(
            container,
            text="Model Information",
            font=("Segoe UI", 10, "bold")
        ).pack(anchor="w", pady=(15, 5))

        self.info = scrolledtext.ScrolledText(
            container,
            height=17,
            wrap="word",
            font=("Consolas", 9)
        )

        self.info.pack(fill="both", expand=True)

        self.info.insert(
            "end",
            "Load a .joblib file to inspect its contents."
        )

        self.info.configure(state="disabled")

        # C function name.

        function_frame = tk.Frame(container)
        function_frame.pack(fill="x", pady=(12, 5))

        tk.Label(
            function_frame,
            text="C Function Name:"
        ).pack(side="left")

        self.function_var = tk.StringVar(
            value="predict_model"
        )

        tk.Entry(
            function_frame,
            textvariable=self.function_var,
            width=25
        ).pack(side="left", padx=8)

        # Export button.

        self.export_btn = tk.Button(
            container,
            text="Export C Header (.h)",
            command=self.export,
            state="disabled",
            height=2,
            font=("Segoe UI", 10, "bold")
        )

        self.export_btn.pack(fill="x", pady=(10, 8))

        self.status = tk.StringVar(
            value="Ready"
        )

        tk.Label(
            container,
            textvariable=self.status,
            anchor="w"
        ).pack(fill="x")

    def set_info(self, content):

        self.info.configure(state="normal")

        self.info.delete("1.0", "end")
        self.info.insert("end", content)

        self.info.configure(state="disabled")

    # --------------------------------------------------------
    # LOAD JOBLIB FILE
    # --------------------------------------------------------

    def load_model(self):

        path = filedialog.askopenfilename(
            title="Select Joblib Model",
            filetypes=[
                ("Joblib Files", "*.joblib"),
                ("Pickle Files", "*.pkl"),
                ("All Files", "*.*")
            ]
        )

        if not path:
            return

        try:

            self.status.set("Loading model...")
            self.root.update_idletasks()

            loaded = joblib.load(path)

            self.loaded_object = loaded
            self.model_path = path

            self.path_var.set(path)

            self.models = inspect_object(loaded)

            self.model_combo["values"] = []
            self.model_var.set("")

            self.selected_model = None

            self.export_btn.configure(
                state="disabled"
            )

            if not self.models:

                self.set_info(
                    f"Root object type: {type(loaded).__name__}\n\n"
                    "No trained scikit-learn estimator was detected "
                    "inside the supported dictionaries, lists, or tuples."
                )

                self.status.set("No model detected.")

                messagebox.showwarning(
                    "No Model Found",
                    "The Joblib file loaded, but no trained "
                    "scikit-learn estimator was detected."
                )

                return

            choices = [
                f"{i + 1}. {item['type']} | {item['path']}"
                for i, item in enumerate(self.models)
            ]

            self.model_combo["values"] = choices
            self.model_combo.current(0)

            self.select_model()

            self.status.set(
                f"{len(self.models)} model(s) detected."
            )

        except Exception as error:

            self.status.set("Loading failed.")

            messagebox.showerror(
                "Loading Error",
                str(error)
            )

    # --------------------------------------------------------
    # SELECT MODEL
    # --------------------------------------------------------

    def select_model(self, event=None):

        index = self.model_combo.current()

        if index < 0:
            return

        item = self.models[index]

        self.selected_model = item["model"]

        information = (
            f"MODEL LOCATION:\n"
            f"{item['path']}\n\n"
            f"{describe_model(self.selected_model)}"
        )

        self.set_info(information)

        self.export_btn.configure(
            state="normal"
        )

    # --------------------------------------------------------
    # EXPORT HEADER
    # --------------------------------------------------------

    def export(self):

        if self.selected_model is None:
            return

        function_name = self.function_var.get().strip()

        if not re.fullmatch(
            r"[A-Za-z_][A-Za-z0-9_]*",
            function_name
        ):
            messagebox.showerror(
                "Invalid Function Name",
                "Use a valid C function name, such as predict_model."
            )
            return

        default_name = (
            os.path.splitext(
                os.path.basename(self.model_path)
            )[0] + ".h"
        )

        output_path = filedialog.asksaveasfilename(
            title="Save C Header",
            defaultextension=".h",
            initialfile=default_name,
            filetypes=[
                ("C Header", "*.h"),
                ("All Files", "*.*")
            ]
        )

        if not output_path:
            return

        try:

            self.status.set("Generating C header...")
            self.root.update_idletasks()

            exporter = export_header(
                self.selected_model,
                output_path,
                function_name
            )

            self.status.set("Export successful.")

            messagebox.showinfo(
                "Export Complete",
                f"C header generated successfully.\n\n"
                f"Exporter: {exporter}\n"
                f"Output: {output_path}\n\n"
                "Compare the generated C predictions with "
                "the original Python model before deployment."
            )

        except Exception as error:

            self.status.set("Export failed.")

            messagebox.showerror(
                "Export Error",
                str(error)
            )


# ============================================================
# APPLICATION ENTRY POINT
# ============================================================

def main():

    root = tk.Tk()

    app = JoblibToHApp(root)

    root.mainloop()


if __name__ == "__main__":
    main()