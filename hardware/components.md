
# Hardware Components

## 1. Overview

The Smart Campus Dashboard uses an ESP32 microcontroller with sensors and output devices to monitor electrical parameters and, where implemented, environmental conditions.

## 2. Components and Their Functions

| S. No. | Component | Function |
|---|---|---|
| 1 | ESP32 Development Board | Processes sensor readings and communicates with the dashboard |
| 2 | ZMPT101B Voltage Sensor | Senses AC voltage |
| 3 | ACS712 Current Sensor | Senses electrical current |
| 4 | Relay Module | Switches a connected load according to the program |
| 5 | DHT22 Sensor | Measures temperature and humidity, if used |
| 6 | MQ-2 Gas Sensor | Detects certain gases and smoke, if used |
| 7 | HC-SR04 Ultrasonic Sensor | Measures distance or water level, if used |
| 8 | Buzzer | Provides an audible alert, if used |
| 9 | LED Indicators | Indicate status or alerts, if used |
| 10 | Jumper Wires | Connect low-voltage circuit components |
| 11 | Power Supply | Supplies power to the electronic components |

## 3. Main Controller

The ESP32 is the main controller of the system. It reads data from connected sensors, processes the readings, and communicates with the dashboard when network connectivity is configured.

## 4. Output Devices

The relay, buzzer, and LEDs provide output functions where included in the prototype. Their operation depends on the firmware and configured conditions.

## 5. Circuit Diagram and Hardware Components

The following image shows the circuit design and hardware components used in the Smart Campus Dashboard project.

<img width="1536" height="1024" alt="circuit components" src="https://github.com/user-attachments/assets/862d350d-1c3f-4ec5-a741-5b968b23aef9" />


**Figure 1:** Circuit diagram and hardware components of the Smart Campus Dashboard.

The circuit diagram illustrates the connections between the ESP32 microcontroller, sensors, and output devices. The component view provides a visual reference for the hardware used in the prototype.

## 6. Safety Precautions

- Never connect mains voltage directly to ESP32 GPIO pins.
- Check sensor output voltages before connecting them to the ESP32.
- Use appropriate isolation, fuses, enclosures, and protective equipment for mains-related circuits.
- Test relay operation with a safe low-voltage setup before use.
