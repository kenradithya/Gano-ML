#include <Arduino.h>
#include "config.h"
#include "GasSensors.h"
#include "DHTManager.h"
#include "GanoMLManager.h"
#include "ImpedanceProbe.h"
#include "OLEDDisplay.h"
#include "DisplayFormatter.h"

// Inisialisasi modul dan driver instrumen GanoPlus
GasSensorManager gasSensors;
DHTManager       dht(PIN_DHT22);
GanoMLManager    ganoML;
ImpedanceProbe   impProbe(PIN_IMPEDANCE_TX, PIN_IMPEDANCE_RX);
OLEDDisplay      oled(PIN_OLED_SDA, PIN_OLED_SCL);
DisplayFormatter display(gasSensors, dht, ganoML, impProbe);

uint32_t bootTimestamp   = 0;
uint32_t lastGasReadTime = 0;
uint32_t lastDhtReadTime = 0;
uint32_t lastDisplayTime = 0;
bool     warmupCompleted = false;

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    
    // Tunggu koneksi serial aktif (maksimal 2.5 detik)
    uint32_t waitSerial = millis();
    while (!Serial && (millis() - waitSerial < 2500)) {
        delay(10);
    }
    
    bootTimestamp = millis();

    // Inisialisasi perangkat keras
    gasSensors.begin();
    dht.begin();
    impProbe.begin();
    oled.begin();
    ganoML.begin();
    display.begin();

    display.printWelcomeHeader();
    ganoML.runSelfTest(Serial);
}

void loop() {
    uint32_t currentMillis = millis();
    uint32_t uptimeSec = (currentMillis - bootTimestamp) / 1000;

    // Cek input perintah dari serial monitor
    display.processSerialCommands();

    // Pembacaan sensor suhu dan kelembaban DHT22 (tiap 2 detik)
    if (currentMillis - lastDhtReadTime >= DHT_READ_INTERVAL_MS) {
        lastDhtReadTime = currentMillis;
        dht.update();
    }

    // Pembacaan sensor gas, bio-impedansi, dan inferensi ML (tiap 1 detik)
    if (currentMillis - lastGasReadTime >= SENSOR_READ_INTERVAL_MS) {
        lastGasReadTime = currentMillis;
        float currentTemp = dht.isValid() ? dht.getTemperatureC() : 28.0f;
        float currentHum  = dht.isValid() ? dht.getHumidity() : 80.0f;
        
        // Sampling bio-impedansi 2 kHz
        impProbe.update();
        if (impProbe.isConnected()) {
            ganoML.setImpedanceProbe(impProbe.getResistance(), impProbe.getReactance(), impProbe.getContactQuality());
        } else {
            ganoML.clearImpedanceProbe();
        }

        // Update pembacaan gas dan eksekusi model XGBoost
        gasSensors.update(currentTemp, currentHum);
        ganoML.update(gasSensors, dht, uptimeSec);
        oled.update(gasSensors, dht, ganoML, impProbe, uptimeSec);
    }

    // Kalibrasi baseline otomatis setelah masa pemanasan 45 detik selesai
    if (!warmupCompleted && uptimeSec >= WARMUP_TIME_SECONDS) {
        warmupCompleted = true;
        Serial.println(F("\n[SISTEM] Pemanasan awal selesai. Mengkalibrasi baseline udara bersih..."));
        gasSensors.calibrate(CALIBRATION_SAMPLES);
        ganoML.captureBaseline(gasSensors, dht);
        Serial.println(F("[SISTEM] Baseline pohon referensi berhasil disimpan.\n"));
    }

    // Cetak dashboard ke serial monitor
    if (currentMillis - lastDisplayTime >= SENSOR_READ_INTERVAL_MS) {
        lastDisplayTime = currentMillis;
        display.printOutput(display.getMode(), uptimeSec);
    }

    delay(5);
}
