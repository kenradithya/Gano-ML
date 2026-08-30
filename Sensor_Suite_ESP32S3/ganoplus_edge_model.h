#ifndef GANOPLUS_EDGE_MODEL_H
#define GANOPLUS_EDGE_MODEL_H

#include <math.h>
#include <stdint.h>

#define GANOPLUS_EDGE_FEATURE_COUNT 17
#define GANOPLUS_EDGE_CLASS_COUNT 4

typedef enum { GANOPLUS_HEALTHY = 0, GANOPLUS_EARLY = 1, GANOPLUS_MODERATE = 2, GANOPLUS_SEVERE = 3 } ganoplus_risk_class_t;
typedef enum {
    GANOPLUS_REASON_NORMAL_BASELINE = (1u << 0),
    GANOPLUS_REASON_VOC_ELEVATED = (1u << 1),
    GANOPLUS_REASON_NH3_ELEVATED = (1u << 2),
    GANOPLUS_REASON_VOC_AROMATIC_ELEVATED = (1u << 3),
    GANOPLUS_REASON_VOC_SULFUR_ELEVATED = (1u << 4),
    GANOPLUS_REASON_IMPEDANCE_2KHZ_ANOMALY = (1u << 5),
    GANOPLUS_REASON_FERTILIZER_RECENT = (1u << 6),
    GANOPLUS_REASON_CONTACT_QUALITY_LOW = (1u << 7),
    GANOPLUS_REASON_RETEST_REQUIRED = (1u << 8),
    GANOPLUS_REASON_INPUT_IMPUTED = (1u << 9),
    GANOPLUS_REASON_LOW_CONFIDENCE = (1u << 10),
    GANOPLUS_REASON_VOC_SENSOR_INVALID = (1u << 11),
    GANOPLUS_REASON_IMPEDANCE_SENSOR_INVALID = (1u << 12)
} ganoplus_reason_code_t;

typedef enum {
    GANOPLUS_DECISION_VALID = 0,
    GANOPLUS_DECISION_RETEST_REQUIRED = 1,
    GANOPLUS_DECISION_SENSOR_INVALID = 2
} ganoplus_decision_status_t;

typedef struct {
    /* Feature order:
 * 0: voc_aromatic_proxy
 * 1: nh3_ppm
 * 2: voc_index_corrected
 * 3: voc_sulfur_proxy
 * 4: fertilizer_recent_flag
 * 5: x_2khz_ohm
 * 6: r_2khz_ohm
 * 7: co2_ppm
 * 8: measurement_quality_score
 * 9: electrode_contact_quality
 * 10: voc_valid
 * 11: impedance_valid
 * 12: voc_index_corrected_delta_from_reference_baseline
 * 13: nh3_ppm_delta_from_reference_baseline
 * 14: reactance_abs_2khz_ohm_delta_from_reference_baseline
 * 15: reactance_abs_2khz_ohm_pct_drop_from_reference_baseline
 * 16: r_2khz_temp_diam_corrected_pct_drop_from_reference_baseline
     */
    float features[GANOPLUS_EDGE_FEATURE_COUNT];
} ganoplus_edge_input_t;

typedef struct {
    float risk_score;
    ganoplus_risk_class_t risk_class;
    float confidence;
    float measurement_quality;
    uint32_t reason_codes;
    ganoplus_decision_status_t decision_status;
    uint8_t alarm_active;
    float class_probabilities[GANOPLUS_EDGE_CLASS_COUNT];
} ganoplus_edge_output_t;

static const float GANOPLUS_EDGE_MEDIAN[GANOPLUS_EDGE_FEATURE_COUNT] = {0.447115f, 2.137699f, 0.53124207f, 0.117928f, 0.0f, -34.785891f, 76.275283f, 639.253308f, 0.805538f, 0.817775f, 1.0f, 1.0f, 0.000819986143f, 0.01686425f, -0.001298f, 3.74395393e-05f, 0.00184524211f};
static const float GANOPLUS_EDGE_MEAN[GANOPLUS_EDGE_FEATURE_COUNT] = {0.478717559f, 3.36586285f, 0.550294409f, 0.140260515f, 0.0603778097f, -32.1600643f, 80.1907254f, 645.774222f, 0.772635334f, 0.775626619f, 0.954328073f, 0.984696318f, 0.0202625586f, 1.24341551f, -2.58062029f, 0.0741657479f, 0.0434848994f};
static const float GANOPLUS_EDGE_SCALE[GANOPLUS_EDGE_FEATURE_COUNT] = {0.263894238f, 3.3546802f, 0.238497092f, 0.11168325f, 0.238185494f, 14.2984185f, 47.1775999f, 137.441289f, 0.146250681f, 0.180241358f, 0.208772609f, 0.122757809f, 0.236674011f, 3.35630395f, 14.1041177f, 0.405267842f, 0.445898502f};
static const float GANOPLUS_EDGE_COEF[GANOPLUS_EDGE_CLASS_COUNT][GANOPLUS_EDGE_FEATURE_COUNT] = {
    {-2.64576694f, -1.23364359f, -0.811450401f, -0.97785877f, 0.667723331f, 0.748517591f, 0.184156615f, 0.251548088f, -0.171307062f, 0.0839152726f, -0.0172038383f, 0.0495871458f, -0.576006225f, -0.909626903f, 1.49391553f, -1.47911654f, -1.17270336f},
    {0.259844382f, 0.169726821f, -0.391101739f, -0.776115208f, 0.188610378f, 0.480098703f, 0.0575415726f, 0.133624125f, -0.0493349994f, 0.0206438681f, 0.283385269f, 0.0587202187f, 0.0192553779f, -0.949094495f, 0.984730532f, -1.02440736f, -0.765136946f},
    {1.06045861f, 0.198493529f, 0.620673786f, 0.303804606f, -0.373454608f, -0.757370544f, 0.0136961899f, -0.232857974f, 0.0887586865f, -0.0477919221f, 0.0293214917f, 0.0751107626f, 0.337060457f, 0.877146952f, -0.456094641f, 0.400331416f, 0.550676575f},
    {1.32546395f, 0.865423242f, 0.581878354f, 1.45016937f, -0.482879101f, -0.471245751f, -0.255394377f, -0.152314239f, 0.131883375f, -0.0567672186f, -0.295502923f, -0.183418127f, 0.21969039f, 0.981574446f, -2.02255142f, 2.10319249f, 1.38716374f}
};
static const float GANOPLUS_EDGE_INTERCEPT[GANOPLUS_EDGE_CLASS_COUNT] = {-0.397185555f, 3.12857787f, 2.38381168f, -5.115204f};
static const float GANOPLUS_EDGE_ALARM_THRESHOLD = 0.21f;

static inline float ganoplus_voc_index_corrected(float voc_index, float gas_rh_pct, float gas_temp_c) {
    float rh_delta = fmaxf(-30.0f, fminf(25.0f, gas_rh_pct - 80.0f));
    float temp_delta = fmaxf(-8.0f, fminf(10.0f, gas_temp_c - 28.0f));
    return fmaxf(0.0f, fminf(1.0f, voc_index / ((1.0f + 0.006f * rh_delta) * (1.0f + 0.012f * temp_delta))));
}

static inline ganoplus_edge_output_t ganoplus_edge_predict(ganoplus_edge_input_t input) {
    ganoplus_edge_output_t out = {0};
    float x[GANOPLUS_EDGE_FEATURE_COUNT];
    float logits[GANOPLUS_EDGE_CLASS_COUNT];
    float max_logit = -INFINITY;
    float probability_sum = 0.0f;
    int any_imputed = 0;
    for (int i = 0; i < GANOPLUS_EDGE_FEATURE_COUNT; ++i) {
        x[i] = input.features[i];
        if (!isfinite(x[i])) {
            x[i] = GANOPLUS_EDGE_MEDIAN[i];
            any_imputed = 1;
        }
    }
    for (int c = 0; c < GANOPLUS_EDGE_CLASS_COUNT; ++c) {
        logits[c] = GANOPLUS_EDGE_INTERCEPT[c];
        for (int i = 0; i < GANOPLUS_EDGE_FEATURE_COUNT; ++i) {
            logits[c] += GANOPLUS_EDGE_COEF[c][i]
                * ((x[i] - GANOPLUS_EDGE_MEAN[i]) / GANOPLUS_EDGE_SCALE[i]);
        }
        if (logits[c] > max_logit) max_logit = logits[c];
    }
    for (int c = 0; c < GANOPLUS_EDGE_CLASS_COUNT; ++c) {
        out.class_probabilities[c] = expf(logits[c] - max_logit);
        probability_sum += out.class_probabilities[c];
    }
    out.risk_class = GANOPLUS_HEALTHY;
    float max_probability = 0.0f;
    for (int c = 0; c < GANOPLUS_EDGE_CLASS_COUNT; ++c) {
        out.class_probabilities[c] /= probability_sum;
        if (out.class_probabilities[c] > max_probability) {
            max_probability = out.class_probabilities[c];
            out.risk_class = (ganoplus_risk_class_t)c;
        }
    }
    out.risk_score = fmaxf(0.0f, fminf(1.0f,
        1.0f - out.class_probabilities[GANOPLUS_HEALTHY]));
    out.measurement_quality = fmaxf(0.0f, fminf(1.0f, x[8]));
    out.confidence = max_probability * (0.5f + 0.5f * out.measurement_quality);
    if (x[8] < 0.45f)
        out.reason_codes |= (1u << 8);
    if (x[9] < 0.5f)
        out.reason_codes |= (1u << 7);
    if (x[10] < 0.5f)
        out.reason_codes |= (1u << 11);
    if (x[11] < 0.5f)
        out.reason_codes |= (1u << 12);
    if (any_imputed) out.reason_codes |= (1u << 9);
    if (out.risk_score >= GANOPLUS_EDGE_ALARM_THRESHOLD) {
        if (x[2] >= 0.483826992f) out.reason_codes |= (1u << 1);
        if (x[1] >= 1.6213273f) out.reason_codes |= (1u << 2);
        if (x[0] >= 0.3303492f) out.reason_codes |= (1u << 3);
        if (x[3] >= 0.1496123f) out.reason_codes |= (1u << 4);
        if (x[5] >= -34.0725025f) out.reason_codes |= (1u << 5);
        if (x[6] <= 67.1891153f) out.reason_codes |= (1u << 5);
        if (x[4] >= 0.5f) out.reason_codes |= (1u << 6);
    }
    if (out.confidence < 0.55f)
        out.reason_codes |= (1u << 10);
    if (out.reason_codes == 0u && out.risk_score < GANOPLUS_EDGE_ALARM_THRESHOLD)
        out.reason_codes |= 1u;
    if (out.reason_codes & ((1u << 11) | (1u << 12))) {
        out.decision_status = GANOPLUS_DECISION_SENSOR_INVALID;
    } else if (out.reason_codes & ((1u << 7) | (1u << 8) | (1u << 9) | (1u << 10))) {
        out.decision_status = GANOPLUS_DECISION_RETEST_REQUIRED;
    } else {
        out.decision_status = GANOPLUS_DECISION_VALID;
    }
    out.alarm_active = (uint8_t)(
        out.decision_status == GANOPLUS_DECISION_VALID
        && out.risk_score >= GANOPLUS_EDGE_ALARM_THRESHOLD
    );
    return out;
}

#endif
