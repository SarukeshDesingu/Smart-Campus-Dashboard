# Hardware Components

## Project
Smart Campus Dashboard — ESP32-Based Monitoring and Protection System

## Main Components

| No. | Component | Purpose |
|---|---|---|
| 1 | ESP32 development board | Reads sensors and processes data |
| 2 | ZMPT101B voltage sensor | Measures AC voltage through an appropriate isolated sensing module |
| 3 | ACS712 current sensor | Measures current within its supported range |
| 4 | Relay module | Switches a connected load when commanded |
| 5 | DHT22 temperature and humidity sensor | Monitors environmental conditions, if included |
| 6 | MQ-2 gas sensor | Detects certain combustible gases and smoke, if included |
| 7 | HC-SR04 ultrasonic sensor | Measures distance, for example, tank level, if included |
| 8 | Buzzer | Provides an audible alert, if included |
| 9 | LEDs | Indicate operating or alert status, if included |
| 10 | Jumper wires and breadboard | Connect low-voltage prototype components |
| 11 | Power supply | Powers the ESP32 and compatible modules |

## Notes
- Verify each sensor's operating voltage and output range before connecting it to the ESP32.
- ESP32 GPIO inputs are not 5 V tolerant.
- Do not connect mains voltage directly to the ESP32 or a breadboard.
- Use appropriate isolation, fusing, enclosures, and qualified supervision for mains-related testing.
