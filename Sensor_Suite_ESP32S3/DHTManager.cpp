#include "DHTManager.h"
#include <math.h>

DHTManager::DHTManager(uint8_t pin) 
    : _pin(pin), _dht(pin, DHT22), _reading({}), _lastAttemptTime(0) {
    _reading.errorMsg = "Initializing";
}

void DHTManager::begin() {
    pinMode(_pin, INPUT_PULLUP);
    _dht.begin();
    _lastAttemptTime = millis() - DHT_READ_INTERVAL_MS;
}

float DHTManager::computeDewPoint(float tempC, float humidity) {
    if (humidity <= 0.0f || humidity > 100.0f) return tempC;
    const float a = 17.27f;
    const float b = 237.7f;
    float alpha = ((a * tempC) / (b + tempC)) + logf(humidity / 100.0f);
    return (b * alpha) / (a - alpha);
}

float DHTManager::computeHeatIndex(float tempC, float humidity) {
    float T = (tempC * 1.8f) + 32.0f;
    float R = humidity;
    float hi = 0.5f * (T + 61.0f + ((T - 68.0f) * 1.2f) + (R * 0.094f));

    if (hi >= 80.0f) {
        hi = -42.379f + 2.04901523f * T + 10.14333127f * R
             - 0.22475541f * T * R - 0.00683783f * T * T
             - 0.05481717f * R * R + 0.00122874f * T * T * R
             + 0.00085282f * T * R * R - 0.00000199f * T * T * R * R;
    }
    return (hi - 32.0f) / 1.8f;
}

bool DHTManager::readSensorDirect(float &outTemp, float &outHum, const char* &outErr) {
    uint8_t data[5] = {0, 0, 0, 0, 0};
    
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delay(20);
    
    noInterrupts();
    digitalWrite(_pin, HIGH);
    delayMicroseconds(2);
    pinMode(_pin, INPUT_PULLUP);

    uint32_t timeout = micros();
    while (digitalRead(_pin) == HIGH) {
        if (micros() - timeout > 100) {
            interrupts();
            outErr = "Bus stuck HIGH";
            return false;
        }
    }

    timeout = micros();
    while (digitalRead(_pin) == LOW) {
        if (micros() - timeout > 120) {
            interrupts();
            outErr = "Sensor response LOW timeout";
            return false;
        }
    }

    timeout = micros();
    while (digitalRead(_pin) == HIGH) {
        if (micros() - timeout > 120) {
            interrupts();
            outErr = "Sensor response HIGH timeout";
            return false;
        }
    }

    for (int bitIdx = 0; bitIdx < 40; bitIdx++) {
        uint32_t lowStart = micros();
        while (digitalRead(_pin) == LOW) {
            if (micros() - lowStart > 200) {
                interrupts();
                outErr = "Bit LOW timeout";
                return false;
            }
        }

        uint32_t highStart = micros();
        while (digitalRead(_pin) == HIGH) {
            if (micros() - highStart > 200) {
                interrupts();
                outErr = "Bit HIGH timeout";
                return false;
            }
        }
        uint32_t highDuration = micros() - highStart;

        uint8_t byteIndex = bitIdx / 8;
        data[byteIndex] <<= 1;
        if (highDuration > 45) {
            data[byteIndex] |= 1;
        }
    }
    interrupts();

    uint8_t expectedChecksum = (data[0] + data[1] + data[2] + data[3]) & 0xFF;
    if (data[4] != expectedChecksum) {
        outErr = "Checksum mismatch";
        return false;
    }

    uint16_t rawHum = (data[0] << 8) | data[1];
    uint16_t rawTemp = ((data[2] & 0x7F) << 8) | data[3];

    float hum = (float)rawHum / 10.0f;
    float temp = (float)rawTemp / 10.0f;
    if (data[2] & 0x80) {
        temp = -temp;
    }

    if (hum < 0.0f || hum > 100.0f || temp < -40.0f || temp > 80.0f) {
        outErr = "Out of range";
        return false;
    }

    outHum = hum;
    outTemp = temp;
    outErr = "OK";
    return true;
}

bool DHTManager::update(bool force) {
    uint32_t now = millis();
    if (!force && (now - _lastAttemptTime < DHT_READ_INTERVAL_MS)) {
        return false;
    }
    _lastAttemptTime = now;

    float libH = _dht.readHumidity();
    float libT = _dht.readTemperature();
    if (!isnan(libH) && !isnan(libT) && libH >= 1.0f && libH <= 100.0f && libT >= -20.0f && libT <= 80.0f) {
        _reading.humidity          = libH;
        _reading.temperatureC      = libT;
        _reading.temperatureF      = (libT * 1.8f) + 32.0f;
        _reading.heatIndexC        = computeHeatIndex(libT, libH);
        _reading.dewPointC         = computeDewPoint(libT, libH);
        _reading.isValid           = true;
        _reading.errorMsg          = "OK";
        _reading.lastReadTimestamp = now;
        _reading.successCount++;
        return true;
    }

    float t = 0.0f, h = 0.0f;
    const char* err = nullptr;
    if (readSensorDirect(t, h, err)) {
        _reading.humidity          = h;
        _reading.temperatureC      = t;
        _reading.temperatureF      = (t * 1.8f) + 32.0f;
        _reading.heatIndexC        = computeHeatIndex(t, h);
        _reading.dewPointC         = computeDewPoint(t, h);
        _reading.isValid           = true;
        _reading.errorMsg          = "OK";
        _reading.lastReadTimestamp = now;
        _reading.successCount++;
        return true;
    }

    _reading.isValid  = false;
    _reading.errorMsg = err ? err : "Read timeout";
    _reading.errorCount++;
    return false;
}
