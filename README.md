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
