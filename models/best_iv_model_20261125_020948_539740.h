/**
 * ==============================================================================
 * Automatically generated C Header for ESP32 TinyML Inference
 * Model ID: best_iv_model_20261125_020948_539740.h
 * Project:  IV_DripEstimationElect (Pampanga State University - CpE-ELECT 3)
 * Target:   ESP32 Microcontroller (Tensilica Xtensa 32-bit LX6)
 * Features: 30 time-steps @ 1Hz x 2 features (filtered weight, dW/dt) = 60 inputs
 * Output:   Continuous scalar Time-to-Empty (TTE in seconds / minutes)
 * ==============================================================================
 */

#ifndef BEST_IV_MODEL_H
#define BEST_IV_MODEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>

#define IV_MODEL_WINDOW_STEPS    30
#define IV_MODEL_NUM_FEATURES    2
#define IV_MODEL_FEATURE_COUNT   60

// Pre-fitted Min-Max normalization vectors: x_scaled = x * scale + min
static const float IV_SCALER_SCALE[60] = {
    9.7553356e-04f, 2.6007801e-02f, 9.7483944e-04f, 3.1333227e-02f, 9.7483944e-04f, 5.5501595e-02f, 
    9.7485847e-04f, 1.2099213e-01f, 9.7503426e-04f, 4.1605990e-02f, 9.7516266e-04f, 4.1718815e-02f, 
    9.7516266e-04f, 4.9358342e-02f, 9.7523868e-04f, 4.2877048e-02f, 9.7539090e-04f, 4.4652823e-02f, 
    9.7539090e-04f, 4.1999158e-02f, 9.7537186e-04f, 3.0714890e-02f, 9.7538141e-04f, 1.7828491e-02f, 
    9.7535772e-04f, 1.5879318e-02f, 9.7530056e-04f, 2.3251759e-02f, 9.7528630e-04f, 2.5989214e-02f, 
    9.7534328e-04f, 2.6007801e-02f, 9.7531482e-04f, 3.1333227e-02f, 9.7532902e-04f, 5.5501595e-02f, 
    9.7536232e-04f, 1.2099213e-01f, 9.7540044e-04f, 4.1605990e-02f, 9.7538141e-04f, 4.1718815e-02f, 
    9.7552402e-04f, 4.9358342e-02f, 9.7554782e-04f, 4.2877048e-02f, 9.7558595e-04f, 4.4652823e-02f, 
    9.7562879e-04f, 4.1999158e-02f, 9.7562879e-04f, 3.0714890e-02f, 9.7567157e-04f, 1.7828491e-02f, 
    9.7569538e-04f, 1.5879318e-02f, 9.7577629e-04f, 2.3251759e-02f, 9.7578118e-04f, 2.5989214e-02f, 
};

static const float IV_SCALER_MIN[60] = {
    -4.9098607e-02f, 3.8491547e-01f, -4.8995428e-02f, 3.0612564e-01f, -4.8995428e-02f, 2.8500071e-01f, 
    -4.9015883e-02f, 4.5795524e-01f, -4.9034473e-02f, 4.7815686e-01f, -4.9001925e-02f, 4.7851482e-01f, 
    -4.9001925e-02f, 3.7709773e-01f, -4.8966732e-02f, 2.4225533e-01f, -4.8974376e-02f, 1.4355883e-01f, 
    -4.8974376e-02f, 1.9445610e-01f, -4.8953913e-02f, 7.2279811e-01f, -4.8964147e-02f, 8.3909786e-01f, 
    -4.8938572e-02f, 9.1980946e-01f, -4.8891816e-02f, 8.1328839e-01f, -4.8891105e-02f, 3.8535509e-01f, 
    -4.8893958e-02f, 3.8491547e-01f, -4.8892532e-02f, 3.0612564e-01f, -4.8873737e-02f, 2.8500071e-01f, 
    -4.8875406e-02f, 4.5795524e-01f, -4.8877317e-02f, 4.7815686e-01f, -4.8856854e-02f, 4.7851482e-01f, 
    -4.8864000e-02f, 3.7709773e-01f, -4.8845679e-02f, 2.4225533e-01f, -4.8842710e-02f, 1.4355883e-01f, 
    -4.8839979e-02f, 1.9445610e-01f, -4.8839979e-02f, 7.2279811e-01f, -4.8861634e-02f, 8.3909786e-01f, 
    -4.8862826e-02f, 9.1980946e-01f, -4.8852239e-02f, 8.1328839e-01f, -4.8837848e-02f, 3.8535509e-01f, 
};

// Linear Regressor Weights (Transpiled from Ridge)
static const float IV_MODEL_WEIGHTS[60] = {
    1.4725548e+03f, -2.6993796e+02f, 1.4638110e+03f, -1.7707068e+02f, 1.4597567e+03f, -2.1130070e+02f, 
    1.4585306e+03f, -4.4847546e+01f, 1.4551418e+03f, -9.3318043e+00f, 1.4596752e+03f, 1.5538710e+01f, 
    1.4567288e+03f, -4.5049286e+01f, 1.4537898e+03f, -7.1010643e+01f, 1.4567737e+03f, -1.1637297e+02f, 
    1.4460176e+03f, -8.6968285e+01f, 1.4524340e+03f, 1.5888895e+01f, 1.4494236e+03f, -9.1877804e+00f, 
    1.4571208e+03f, -5.3027644e+00f, 1.4475242e+03f, 1.1623869e+01f, 1.4500084e+03f, -9.1545898e+01f, 
    1.4430078e+03f, -8.2060341e+01f, 1.4428575e+03f, -2.7482067e+01f, 1.4533347e+03f, -5.0824352e+01f, 
    1.4397700e+03f, 6.0313244e+01f, 1.4435460e+03f, 8.5985756e+01f, 1.4492794e+03f, 1.2417480e+02f, 
    1.4461372e+03f, 8.3855232e+01f, 1.4540905e+03f, 6.8705330e+01f, 1.4518313e+03f, 1.4478359e+01f, 
    1.4505387e+03f, 3.4311958e+01f, 1.4532493e+03f, 1.8136737e+02f, 1.4615068e+03f, 2.4856374e+02f, 
    1.4884972e+03f, 2.5450508e+02f, 1.4899894e+03f, 1.9981450e+02f, 1.4939733e+03f, 7.9302734e+01f, 
};

static const float IV_MODEL_BIAS = -4.3864062e+02f;

/**
 * Executes embedded sequence regression inference.
 * @param raw_features Array of 60 unnormalized floats (chronological [w0, dw0, w1, dw1, ...])
 * @return Predicted remaining Time-to-Empty (TTE) in seconds.
 */
static inline float iv_model_predict_seconds(const float* raw_features) {
    if (!raw_features) return 0.0f;

    float predicted_tte = IV_MODEL_BIAS;
    for (int i = 0; i < IV_MODEL_FEATURE_COUNT; ++i) {
        // Apply Min-Max normalization
        float scaled_feature = raw_features[i] * IV_SCALER_SCALE[i] + IV_SCALER_MIN[i];
        // Accumulate dot product
        predicted_tte += scaled_feature * IV_MODEL_WEIGHTS[i];
    }

    // TTE cannot be negative
    if (predicted_tte < 0.0f) {
        predicted_tte = 0.0f;
    }
    return predicted_tte;
}

/**
 * Convenience wrapper returning predicted TTE in minutes.
 * @param raw_features Array of 60 unnormalized floats.
 * @return Predicted TTE in minutes.
 */
static inline float iv_model_predict_minutes(const float* raw_features) {
    return iv_model_predict_seconds(raw_features) / 60.0f;
}

#ifdef __cplusplus
}
#endif

#endif // BEST_IV_MODEL_H
