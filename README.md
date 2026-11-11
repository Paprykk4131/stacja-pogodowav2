# 🌤️ Autonomiczna Stacja Pogodowa IoT

> **Projekt Akademicki** | System wbudowany do ciągłego monitorowania parametrów atmosferycznych.

![Licencja](https://img.shields.io/badge/License-MIT-blue.svg)
![Hardware](https://img.shields.io/badge/Hardware-Arduino_/_Raspberry_Pi-orange)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

---

## 📌 OPIS PROJEKTU
Projekt stacji pogodowej realizowany w ramach studiów. Urządzenie dokonuje ciągłych pomiarów temperatury, wilgotności względnej powietrza oraz prędkości wiatru, a następnie przetwarza i prezentuje dane w czasie rzeczywistym.

---

## 🛠️ ELEMENTY SYSTEMU (BOM)

### Sprzęt (Hardware)
- **Mikrokontroler:** Arduino UNO / ESP32 *lub* Raspberry Pi 4B
- **Czujnik temperatury i wilgotności:** DHT22 (AM2302)
- **Czujnik prędkości wiatru:** Anemometr impulsowy (kontaktronowy) / napięciowy (0.4V - 2.0V)
- **Pozostałe:** Rezystory (10kΩ, 4.7kΩ), płytka stykowa, przewody połączeniowe, obudowa drukowana 3D (osłona antyradiacyjna).

### Oprogramowanie (Software)
- C++ (Arduino IDE) / Python 3 (Raspberry Pi)
- Biblioteki: `DHT sensor library`, `Adafruit Unified Sensor`

---

## 🔌 SCHEMAT POŁĄCZEŃ

| Czujnik | Pin Czujnika | Pin Mikrokontrolera | Uwagi |
| :--- | :--- | :--- | :--- |
| **DHT22** | VCC | 5V / 3.3V | Zasilanie |
| **DHT22** | DATA | Digital Pin 2 / GPIO4 | Pull-up rezystor 10kΩ |
| **DHT22** | GND | GND | Masa |
| **Anemometr** | Signal | Digital Pin 3 / GPIO17 | Obsługa przerwań (Interrupt) |
| **Anemometr** | GND | GND | Masa |

---

## 💻 KOD (Quick Start)

### Wariant A: Arduino (C++)
Kod źródłowy znajduje się w katalogu `src/main.ino`.

```cpp
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22
#define ANEMOMETER_PIN 3

DHT dht(DHTPIN, DHTTYPE);
volatile unsigned int pulseCount = 0;

void countPulse() {
  pulseCount++;
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ANEMOMETER_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ANEMOMETER_PIN), countPulse, RISING);
}

void loop() {
  delay(2000);
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  
  // Obliczanie prędkości wiatru (1 impuls/sek = 2.4 km/h dla standardowych anemometrów)
  float windSpeed = (pulseCount / 2.0) * 2.4; 
  pulseCount = 0;

  Serial.print("Temp: "); Serial.print(temp); Serial.print(" °C | ");
  Serial.print("Wilgotność: "); Serial.print(humidity); Serial.print(" % | ");
  Serial.print("Wiatr: "); Serial.print(windSpeed); Serial.println(" km/h");
}
