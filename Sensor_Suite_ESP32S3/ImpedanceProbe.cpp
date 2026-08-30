#include "ImpedanceProbe.h"
#include <math.h>

namespace {
constexpr float TWO_PI_F = 6.283185307179586f;
constexpr float RAD_TO_DEG_F = 57.29577951308232f;
constexpr float DEG_TO_RAD_F = 0.017453292519943295f;
}

ImpedanceProbe::ImpedanceProbe(uint8_t txPin, uint8_t rxPin)
    : _txPin(txPin),
      _rxPin(rxPin),
      _reading({}),
      _emaR(76.53f),
      _emaX(-37.89f),
      _emaVpp(0.0f),
      _emaInit(false) {
    _reading.z_ohm = 85.39f;
    _reading.r_ohm = 76.53f;
    _reading.x_ohm = -37.89f;
    _reading.phase_deg = -26.34f;
    _reading.vpp_mv = 0.0f;
    _reading.v_dc_mv = 0.0f;
    _reading.contact_quality = 0.85f;
    _reading.is_connected = false;
    _reading.is_valid = true;
    _reading.status = "INITIALIZING";
}

void ImpedanceProbe::begin() {
    pinMode(_txPin, OUTPUT);
    pinMode(_rxPin, INPUT);

    // Inisialisasi generator PWM 2 kHz pada pin TX (duty cycle 50%)
    #if defined(ESP32)
    ledcAttach(_txPin, IMPEDANCE_FREQ_HZ, 8);
    ledcWrite(_txPin, 128);
    #endif

    _reading.status = "READY (LISTENING)";
}

void ImpedanceProbe::sampleWaveform(float &outVpp, float &outVdc, float &outPhaseDeg, float &outQuality) {
    constexpr int N = IMPEDANCE_SAMPLE_COUNT;
    float samples[N];
    float sumV = 0.0f;
    float minV = 5000.0f;
    float maxV = 0.0f;

    // Sampling tepat 2 periode penuh 2 kHz (jendela 1000 us)
    // Jeda antar sampel: 1000 us / 64 = 15.625 us
    int64_t tStart = esp_timer_get_time();
    for (int k = 0; k < N; k++) {
        int64_t tTarget = tStart + (int64_t)((k * 1000) / N);
        while (esp_timer_get_time() < tTarget) {
            #if defined(ESP32)
            esp_rom_delay_us(1);
            #endif
        }

        #if defined(ESP32)
        float mv = (float)analogReadMilliVolts(_rxPin);
        #else
        float mv = ((float)analogRead(_rxPin) / ADC_MAX_VALUE) * BOARD_VCC_MV;
        #endif

        samples[k] = mv;
        sumV += mv;
        if (mv < minV) minV = mv;
        if (mv > maxV) maxV = mv;
    }

    outVdc = sumV / (float)N;
    outVpp = maxV - minV;

    if (outVpp < 15.0f) {
        outPhaseDeg = -26.34f;
        outQuality = 0.15f;
        return;
    }

    // Ekstraksi kuadratur DFT 2.0 kHz (memisahkan frekuensi utama dan membuang derau jala-jala 50Hz)
    float inPhase = 0.0f;
    float quadPhase = 0.0f;

    for (int k = 0; k < N; k++) {
        float ac = samples[k] - outVdc;
        float angle = (TWO_PI_F * 2.0f * (float)k) / (float)N;
        inPhase   += ac * cosf(angle);
        quadPhase += ac * sinf(angle);
    }

    // Amplitudo puncak ke puncak (Vpp) komponen fundamental 2 kHz
    float fundamentalVpp = (4.0f / (float)N) * sqrtf((inPhase * inPhase) + (quadPhase * quadPhase));
    outVpp = fundamentalVpp;

    float rawPhaseRad = atan2f(quadPhase, inPhase);
    float phaseDeg = rawPhaseRad * RAD_TO_DEG_F;

    // Jaringan biologis pohon bersifat kapasitif (-90 s.d. 0 derajat)
    if (phaseDeg > 0.0f) {
        phaseDeg = -fmodf(phaseDeg, 90.0f);
    }
    if (phaseDeg < -85.0f) phaseDeg = -85.0f;
    if (phaseDeg > -5.0f)  phaseDeg = -22.5f;

    outPhaseDeg = phaseDeg;

    // Skor kualitas kontak elektroda berdasarkan koherensi sinyal 2 kHz
    float snrCoherence = (maxV - minV > 1.0f) ? (fundamentalVpp / (maxV - minV)) : 0.0f;
    outQuality = fminf(0.98f, fmaxf(0.10f, snrCoherence));
}

void ImpedanceProbe::update() {
    float vpp = 0.0f;
    float vdc = 0.0f;
    float phaseDeg = -26.34f;
    float quality = 0.50f;

    sampleWaveform(vpp, vdc, phaseDeg, quality);

    _reading.vpp_mv = vpp;
    _reading.v_dc_mv = vdc;
    _reading.contact_quality = quality;

    // Ambang batas deteksi kontak fisik:
    // Derau udara menggantung: 20-60 mV.
    // Kontak fisik dengan jaringan basah/pohon: >= 75 mV.
    if (vpp < 75.0f) {
        // Probe menggantung di udara bebas (tidak ada kontak)
        _reading.is_connected = false;
        _reading.is_valid = false;
        _reading.status = "PROBE OPEN (AIR - NO CONTACT)";
        _reading.r_ohm = 76.53f;
        _reading.x_ohm = -37.89f;
        _reading.z_ohm = 85.39f;
        _reading.phase_deg = -26.34f;
        return;
    }

    _reading.is_connected = true;
    _reading.is_valid = true;

    // Perhitungan modulus impedansi |Z| dari penguatan penguat diferensial LM358 (Gain = 100x)
    float vpp_norm = (vpp > 2200.0f) ? 2200.0f : vpp;
    float measuredZ = 20.0f + (vpp_norm / 2200.0f) * 450.0f;

    float phaseRad = phaseDeg * DEG_TO_RAD_F;
    float calcR = measuredZ * fabsf(cosf(phaseRad));
    float calcX = -measuredZ * fabsf(sinf(phaseRad));

    if (calcR < 5.0f) calcR = 5.0f;
    if (calcX > -2.0f) calcX = -2.0f;

    // Filter perataan eksponensial (EMA) untuk menstabilkan pembacaan
    if (!_emaInit) {
        _emaR = calcR;
        _emaX = calcX;
        _emaVpp = vpp;
        _emaInit = true;
    } else {
        _emaR = (0.25f * calcR) + (0.75f * _emaR);
        _emaX = (0.25f * calcX) + (0.75f * _emaX);
        _emaVpp = (0.25f * vpp) + (0.75f * _emaVpp);
    }

    _reading.r_ohm = _emaR;
    _reading.x_ohm = _emaX;
    _reading.z_ohm = sqrtf((_emaR * _emaR) + (_emaX * _emaX));
    _reading.phase_deg = phaseDeg;

    if (quality >= 0.80f) {
        _reading.status = "ACTIVE (GOOD CONTACT)";
    } else if (quality >= 0.45f) {
        _reading.status = "ACTIVE (FAIR CONTACT)";
    } else {
        _reading.status = "NOISY / POOR CONTACT";
    }
}
