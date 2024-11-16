#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#define BME280_I2C_ADDR 0x76

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Warten bis die serielle Verbindung bereit ist
  while (!Serial) delay(10);
  
  Serial.println("BME280 Test");
  
  // BME280 initialisieren
  if (!bme.begin(BME280_I2C_ADDR)) {
    Serial.println("Konnte BME280 Sensor nicht finden!");
    while (1) delay(10);
  }
  
  // Empfohlene Einstellungen für Wetterstation
  bme.setSampling(Adafruit_BME280::MODE_NORMAL,     // Betriebsmodus
                  Adafruit_BME280::SAMPLING_X16,     // Temperatur-Übersampling
                  Adafruit_BME280::SAMPLING_X16,     // Druck-Übersampling
                  Adafruit_BME280::SAMPLING_X16,     // Feuchtigkeits-Übersampling
                  Adafruit_BME280::FILTER_X16,       // Filter
                  Adafruit_BME280::STANDBY_MS_500);  // Standby-Zeit
}

void loop() {
  Serial.print("Temperatur = ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Luftdruck = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Luftfeuchtigkeit = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Höhe = ");
  Serial.print(bme.readAltitude(1013.25)); // 1013.25 = Standardluftdruck auf Meereshöhe
  Serial.println(" m");

  Serial.println();
  delay(2000);
}