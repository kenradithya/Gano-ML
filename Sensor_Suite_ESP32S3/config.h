#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Konfigurasi pin sensor gas dan iklim (ESP32-S3)
#define PIN_DHT22         4
#define PIN_TGS2600       1
#define PIN_MQ3           2
#define PIN_MQ4           5
#define PIN_MQ9           9
#define PIN_MQ135         10
#define PIN_ALT_GAS       7

// Pin dan parameter bio-impedansi 2 kHz (Front-End LM358)
#define PIN_IMPEDANCE_TX        38   // Generator gelombang kotak PWM
#define PIN_IMPEDANCE_RX        12   // Input ADC dari output op-amp LM358
#define IMPEDANCE_FREQ_HZ       2000 // Frekuensi eksitasi 2 kHz
#define IMPEDANCE_R_REF_OHM     100.0f
#define IMPEDANCE_SAMPLE_COUNT  64   // Jumlah sampel per siklus gelombang

// Pin I2C layar OLED SSD1306 (128x64)
#define PIN_OLED_SDA            42
#define PIN_OLED_SCL            41
#define OLED_SCREEN_WIDTH       128
#define OLED_SCREEN_HEIGHT      64
#define OLED_RESET_PIN          -1

// Parameter konversi ADC dan filter sinyal
#define BOARD_VCC_MV      3300.0f
#define SENSOR_VCC_MV     5000.0f
#define ADC_MAX_VALUE     4095.0f
#define ADC_OVERSAMPLES   64
#define EMA_ALPHA         0.20f

// Nilai resistor beban (RL) pada modul sensor gas (kOhm)
#define RL_TGS2600_KOHM   10.0f
#define RL_MQ3_KOHM       10.0f
#define RL_MQ4_KOHM       20.0f
#define RL_MQ9_KOHM       10.0f
#define RL_MQ135_KOHM     10.0f

// Rasio dasar udara bersih (Rs/R0) dari datasheet pabrikan
#define CLEAN_AIR_RATIO_TGS2600   1.00f
#define CLEAN_AIR_RATIO_MQ3       60.0f
#define CLEAN_AIR_RATIO_MQ4       4.40f
#define CLEAN_AIR_RATIO_MQ9       9.80f
#define CLEAN_AIR_RATIO_MQ135     3.60f

// Koefisien kurva gas: ppm = a * (Rs/R0)^b
#define MQ3_A_ALCOHOL     0.3934f
#define MQ3_B_ALCOHOL    -1.504f

#define MQ4_A_CH4         1012.7f
#define MQ4_B_CH4        -2.786f

#define MQ9_A_CO          599.65f
#define MQ9_B_CO         -2.244f

#define MQ135_A_CO2       110.47f
#define MQ135_B_CO2      -2.862f

#define MQ135_A_NH3       102.20f
#define MQ135_B_NH3      -2.473f

// Interval waktu sampling & pemanasan awal
#define SERIAL_BAUD_RATE        115200
#define SENSOR_READ_INTERVAL_MS 1000
#define DHT_READ_INTERVAL_MS    2000
#define ML_INFERENCE_INTERVAL_MS 1000
#define WARMUP_TIME_SECONDS     45
#define CALIBRATION_SAMPLES     100

// Parameter default fisik pohon sawit
#define DEFAULT_TREE_DIAMETER_CM  50.0f
#define DEFAULT_TREE_AGE_YEARS    10.0f

// Mode tampilan serial
enum OutputMode {
    OUTPUT_MODE_DASHBOARD = 0,
    OUTPUT_MODE_JSON      = 1,
    OUTPUT_MODE_PLOTTER   = 2,
    OUTPUT_MODE_PROBE     = 3
};

#define DEFAULT_OUTPUT_MODE OUTPUT_MODE_DASHBOARD

#endif
