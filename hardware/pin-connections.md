# ESP32 Pin Connections

## Pin Map

| Component | Signal | Example ESP32 pin |
|---|---|---|
| ZMPT101B | Analog output | GPIO 34 |
| ACS712 | Analog output | GPIO 35 |
| Relay module | Control input | GPIO 26 |
| DHT22 | Data | GPIO 4 |
| MQ-2 | Analog output | GPIO 32 |
| HC-SR04 | Trigger | GPIO 5 |
| HC-SR04 | Echo | GPIO 18 |
| Buzzer | Control | GPIO 25 |
| Status LED | Anode through resistor | GPIO 2 |

## Connection Guidelines
1. Confirm the pinout of the exact ESP32 development board.
2. Connect sensor outputs only within the ESP32's permitted input-voltage range.
3. Connect grounds together only where appropriate for the low-voltage circuit design.
4. Never connect a 5 V HC-SR04 Echo output directly to an ESP32 GPIO; use a suitable level shifter or divider.
5. Check whether the relay module is active-high or active-low before using it.
6. Keep mains wiring physically separated from low-voltage electronics and use suitable isolation and protective equipment.
