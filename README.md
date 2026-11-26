# IV Drip Depletion Estimation System (IV_DripEstimationElect)
**CpE-ELECT 3: Major Laboratory 1 — AI Model Development and Evaluation**  
**Pampanga State University — College of Engineering and Architecture (CEA)**  
*Department of Computer Engineering*

---

## 1. Project Overview & System Architecture

This project implements an IoT-enabled TinyML monitoring system for gravity-fed IV therapy containers (1,000 mL D5W). In clinical settings, fluid containers running dry leave unmonitored intervals that risk blood backflow, line clotting, and air embolisms.

The system combines:
1. **Physical Sensing**: 1 kg load cell with an HX711 ADC operating with a 10-sample moving average and 0.40 g deadband filter.
2. **Embedded Machine Learning (TinyML)**: A 100-tree Scikit-Learn `GradientBoostingRegressor` transpiled into a static, deterministic C header (`best_iv_model_20261125_020948_539740.h`) running directly on an ESP32 microcontroller without dynamic heap allocations or heavy runtime libraries.
3. **Hardware UI & Telemetry**: 16×2 I2C LCD, 3-tier status LEDs (Normal, Warning, Critical), active buzzer alerts, and an embedded Wi-Fi Access Point Web Dashboard (`IV-Monitor-AI` at `192.168.4.1`).

---

## 2. Repository Structure

```text
IV_DripEstimationElect/
├── README.md                                # Project overview, setup, evaluation results, wiring diagram
├── requirements.txt                         # Python dependencies (scikit-learn, pandas, numpy, matplotlib, etc.)
│
├── Converter/                               # Joblib-to-C Transpilation Utility
│   ├── joblib_to_h.py                       # Tkinter GUI & CLI transpiler (joblib -> ESP32 .h header)
│   └── requirements_joblib_to_h.txt         # Dependencies for converter tool
│
├── data/                                    # Datasets & Acquisition
│   ├── logger.py                            # CSVElectLogger serial acquisition script
│   ├── raw/
│   │   ├── iv_drip_12hr_run1.csv            # Independent 12-hr runs 1 to 5
│   │   ├── iv_drip_12hr_run2.csv
│   │   ├── iv_drip_12hr_run3.csv
│   │   ├── iv_drip_12hr_run4.csv
│   │   ├── iv_drip_12hr_run5.csv
│   │   └── iv_drip_dataset8hrs.csv          # 8-hr full drip test dataset
│   └── processed/                           # Normalized sliding window arrays & scaler parameters
│
├── notebooks_and_scripts/                   # AI/ML pipeline scripts
│   ├── 01_data_preprocessing.py             # Median filter (k=3), 10Hz->1Hz resampling, dW/dt, sliding window
│   ├── 02_train_and_evaluate.py             # Baseline (V/R) vs. GBDT & ML models training & cross-validation
│   ├── 03_export_to_c_header.py             # Invokes Converter/joblib_to_h.py to transpile model to C header (.h)
│   └── evaluate_8hr_test.py                 # Evaluates 8-hr test (MAE: 495.99s, RMSE: 506.20s, R²: 0.948)
│
├── models/                                  # Exported artifacts and trained weights
│   ├── baseline_eval_results.json           # Physics baseline evaluation results
│   ├── winning_model.joblib                 # Trained Scikit-Learn model binary
│   └── best_iv_model_20261125_020948_539740.h  # Transpiled C header for ESP32
│
├── firmware/                                # ESP32 Arduino/PlatformIO source code
│   └── Elect_System/
│       ├── Elect_System.ino                 # Main ESP32 sketch (Load cell, TTE inference, LCD, Wi-Fi alerts)
│       └── best_iv_model_20261125_020948_539740.h # Locally included C header
│
└── results/                                 # Verification graphs & evidence figures
    ├── weight_vs_time_depletion.png
    ├── actual_vs_predicted_tte.png
    └── baseline_vs_model_comparison.png
```

---

## 3. Hardware Pin Mapping & Wiring

| Component | ESP32 Pin | Function |
| :--- | :--- | :--- |
| **HX711 DOUT** | GPIO 16 | Serial data from load cell amplifier |
| **HX711 SCK** | GPIO 17 | Serial clock for load cell amplifier |
| **I2C LCD SDA** | GPIO 21 | LiquidCrystal_I2C data line |
| **I2C LCD SCL** | GPIO 22 | LiquidCrystal_I2C clock line |
| **Green LED** | GPIO 14 | Normal status indicator |
| **Yellow LED** | GPIO 27 | Warning status indicator ($\le 15$ mins remaining) |
| **Red LED** | GPIO 26 | Critical alert indicator ($\le 5$ mins or $\le 50$ g) |
| **Buzzer** | GPIO 25 | Pulsed acoustic alert during critical depletion |

---

## 4. Evaluation Results (8-Hour Full Drip Test)

| Metric | Target / Benchmark | Actual Result | Status |
| :--- | :--- | :--- | :--- |
| **Mean Absolute Error (MAE)** | $\le 600\,\text{s}$ ($10.0\,\text{min}$) | **$495.99\,\text{s}$** ($8.27\,\text{min}$, $1.72\%$ of 8-hr infusion) | **PASSED** |
| **Root Mean Squared Error (RMSE)**| $\le 600\,\text{s}$ ($10.0\,\text{min}$) | **$506.20\,\text{s}$** ($8.44\,\text{min}$) | **PASSED** |
| **$R^2$ Variance Score** | $\ge 0.900$ | **$0.948$** | **PASSED** |
| **Physics Baseline Error** | Lower than Baseline | Baseline MAE: $9826.92\,\text{s}$ ($163.78\,\text{min}$) | **PASSED** |

---

## 5. Reproduction & Execution Instructions

### A. Environment Setup
```powershell
pip install -r requirements.txt
```

### B. Run Full Machine Learning Pipeline
```powershell
# 1. Preprocessing (3-sample median filter k=3, 10Hz->1Hz resampling, sliding window)
python notebooks_and_scripts/01_data_preprocessing.py

# 2. Train and cross-validate baseline & candidate regressors
python notebooks_and_scripts/02_train_and_evaluate.py

# 3. Transpile winning .joblib model into ESP32 C header via Converter
python notebooks_and_scripts/03_export_to_c_header.py

# 4. Evaluate on 8-hour test dataset and generate verification graphs
python notebooks_and_scripts/evaluate_8hr_test.py
```

### C. GUI Model Converter
To visually inspect any `.joblib` model and transpile it to `.h`:
```powershell
python Converter/joblib_to_h.py
```
