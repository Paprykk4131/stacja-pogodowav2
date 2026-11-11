#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// --- KONFIGURACJA WI-FI ---
const char* ssid = "TUTAJ_WPISZ_NAZWE_WIFI";
const char* password = "TUTAJ_WPISZ_HASLO_WIFI";

// Inicjalizacja czujnika BME280 po I2C (piny domyślne dla ESP32: SDA = GPIO 21, SCL = GPIO 22)
Adafruit_BME280 bme; 

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Inicjalizacja czujnika BME280 (domyślny adres I2C to zazwyczaj 0x76 lub 0x77)
  if (!bme.begin(0x76)) {
    Serial.println("Nie znaleziono czujnika BME280! Sprawdź poprawność podłączenia pinów.");
    while (1);
  }

  Serial.println("Czujnik BME280 gotowy do pracy!");

  // Łączenie z siecią Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Łączenie z Wi-Fi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nPołączono z Wi-Fi!");
  Serial.print("Adres IP układu: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Odczyt danych z czujnika BME280
  float temperatura = bme.readTemperature();
  float cisnienie = bme.readPressure() / 100.0F; // Przeliczenie Pa na hPa
  float wilgotnosc = bme.readHumidity();

  // Wypisanie pomiarów w Monitorze Szeregowym (Serial Monitor)
  Serial.println("----------------------------------------");
  Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println(" °C");
  Serial.print("Ciśnienie:   "); Serial.print(cisnienie);   Serial.println(" hPa");
  Serial.print("Wilgotność:  "); Serial.print(wilgotnosc);  Serial.println(" %");
  Serial.println("----------------------------------------");

  // Odczekaj 10 sekund przed kolejnym pomiarem
  delay(10000);
}
