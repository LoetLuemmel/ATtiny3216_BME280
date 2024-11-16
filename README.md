BOSCH BME280 Sensor
===================

# BME280 Wetterstation

Eine Arduino-basierte Wetterstation mit dem BME280 Sensor zur Messung von:
- Temperatur
- Luftdruck
- Luftfeuchtigkeit
- Höhe

## Hardware
- Arduino (z.B. ESP32, Arduino Uno)
- BME280 Sensor

## Installation
1. Klonen Sie das Repository
2. Öffnen Sie das Projekt in der Arduino IDE oder PlatformIOç
3. Laden Sie den Code auf Ihren Arduino

## Verbindungen
- BME280 SDA -> Arduino SDA
- BME280 SCL -> Arduino SCL
- BME280 VCC -> 3.3V
- BME280 GND -> GND

<code>
'''
           ATtiny3216
           ____  ____
    VDD  1|    \/    |20 GND
    PA4  2|          |19 PA3
    PA5  3|          |18 PA2
    PA6  4|          |17 PA1
    PA7  5|          |16 PA0/UPDI
    PB5  6|          |15 PC3
    PB4  7|          |14 PC2
    PB3  8|          |13 PC1
    PB2  9|          |12 PC0
SDA/PB1 10|__________|11 PB0/SCL

'''
</code>
