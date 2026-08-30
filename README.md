# Gano-ML: Firmware Sensor Suite ESP32-S3

Repositori ini berisi kode sumber firmware untuk unit instrumentasi akuisisi sensor dan inferensi on-device pada mikrokontroler ESP32-S3. Sistem mengintegrasikan larik sensor gas volatil (VOC/gas metabolit), sensor iklim mikro, dan spektroskopi bio-impedansi jaringan.

## Struktur Berkas

```
Sensor_Suite_ESP32S3/
├── Sensor_Suite_ESP32S3.ino    # Program utama (setup dan loop sistem)
├── config.h                    # Konfigurasi pinout, konstanta gas, dan parameter sampling
├── GasSensors.h / .cpp         # Driver larik sensor gas (TGS2600, MQ-3, MQ-4, MQ-9, MQ-135)
├── DHTManager.h / .cpp         # Driver pembacaan suhu dan kelembapan udara (DHT22)
├── ImpedanceProbe.h / .cpp     # Pengukuran bio-resistansi (R) dan bio-reaktansi (X) 2 kHz
├── OLEDDisplay.h / .cpp        # Tampilan layar OLED SSD1306 128x64
├── DisplayFormatter.h / .cpp   # Pengolah keluaran serial (Dashboard, JSON, Plotter)
├── GanoMLManager.h / .cpp      # Pengelola ekstraksi fitur dan eksekusi inferensi
├── XGBoostGano.h               # Implementasi C++ ensemble pohon keputusan XGBoost
└── ganoplus_edge_model.h       # Model klasifikasi terkompresi untuk komputasi edge
```

## Konfigurasi Pinout Perangkat Keras

| Komponen / Sensor | Tipe / Fungsi | Pin ESP32-S3 | Keterangan |
| :--- | :--- | :---: | :--- |
| **TGS2600** | Sensor VOC / Aromatic | `GPIO 1` | Input ADC1 |
| **MQ-3** | Sensor Alkohol / VOC | `GPIO 2` | Input ADC1 |
| **MQ-4** | Sensor Metana ($CH_4$) | `GPIO 5` | Input ADC1 |
| **MQ-9** | Sensor Karbon Monoksida ($CO$) | `GPIO 9` | Input ADC1 |
| **MQ-135** | Sensor Amonia ($NH_3$) / $CO_2$ | `GPIO 10` | Input ADC1 |
| **DHT22** | Suhu dan Kelembapan Relatif | `GPIO 4` | Digital I/O (Pull-up 4.7kΩ) |
| **Bio-Impedance TX** | Eksitasi Gelombang Kotak 2 kHz | `GPIO 38` | Sinyal PWM AC |
| **Bio-Impedance RX** | Pembacaan Respons Tegangan | `GPIO 12` | Input ADC dari pengondisi LM358 |
| **OLED SDA** | Komunikasi I2C Data | `GPIO 42` | I2C Bus |
| **OLED SCL** | Komunikasi I2C Clock | `GPIO 41` | I2C Bus |

## Kebutuhan Lingkungan & Pustaka
- **Board:** ESP32-S3 Dev Module / ESP32-S3-DevKitC-1
- **Core:** `esp32` by Espressif Systems (versi 2.0.x atau 3.x)
- **Pustaka Arduino yang Diperlukan:**
  - `Adafruit SSD1306` & `Adafruit GFX Library`
  - `DHT sensor library` (Adafruit)

## Panduan Penggunaan

1. Buka berkas `Sensor_Suite_ESP32S3/Sensor_Suite_ESP32S3.ino` di Arduino IDE atau VS Code (PlatformIO).
2. Pilih board **ESP32S3 Dev Module** dengan konfigurasi:
   - *USB CDC On Boot:* Enabled
   - *CPU Frequency:* 240MHz
   - *Flash Size:* 8MB / 16MB
   - *PSRAM:* OPI PSRAM (jika modul mendukung)
3. Lakukan kompilasi dan unggah program ke mikrokontroler.
4. Buka Serial Monitor pada baud rate `115200`.

### Perintah Serial Monitor yang Tersedia
Saat perangkat menyala, Anda dapat mengirimkan perintah berikut melalui terminal serial:

- `mode dashboard` : Menampilkan ringkasan pengukuran tabel lengkap (Default).
- `mode json` : Menampilkan data mentah dalam format JSON per detik.
- `mode plotter` : Format keluaran numerik ringkas untuk Arduino Serial Plotter.
- `cal` : Memicu kalibrasi ulang udara bersih secara manual.
- `baseline` : Merekam kondisi baseline pohon uji.
- `ml selftest` : Menjalankan uji verifikasi mandiri inferensi model.
