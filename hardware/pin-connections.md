# ESP32 Pin Connections

## 1. Purpose

This document describes the connections between the ESP32 development board and the sensors and output devices used in the Smart Campus Dashboard.

## 2. Example Pin Map

| Component | Signal | Example ESP32 Pin |
|---|---|---|
| ZMPT101B | Analog Output | GPIO 34 |
| ACS712 | Analog Output | GPIO 35 |
| Relay Module | Control Input | GPIO 26 |
| DHT22 | Data | GPIO 4 |
| MQ-2 | Analog Output | GPIO 32 |
| HC-SR04 | Trigger | GPIO 5 |
| HC-SR04 | Echo | GPIO 18 |
| Buzzer | Control | GPIO 25 |
| Status LED | Control through resistor | GPIO 2 |

**Note:** Only include components that are actually installed. Verify every pin against the physical circuit and firmware.

## 3. Connection Guidelines

1. Confirm the pinout of the exact ESP32 development board.
2. Ensure that sensor outputs remain within the ESP32's permitted input-voltage range.
3. Connect power and ground according to each module's requirements.
4. Do not connect a 5 V HC-SR04 Echo signal directly to an ESP32 GPIO; use a suitable level shifter or voltage divider.
5. Check whether the relay module is active-high or active-low.
6. Keep mains wiring isolated from low-voltage electronics.

## 4. Proteus Circuit Simulation

The circuit is designed in Proteus to illustrate the proposed component connections and system layout.

### Circuit Diagram


<img width="1600" height="999" alt="Proteus-Circuit png" src="https://github.com/user-attachments/assets/67cdf73b-c8e6-40c6-b8ae-8250e208905c" />


### Simulation Notes

- This image documents the circuit design.
- Simulation results depend on the components and models available in Proteus.
- A simulated circuit does not automatically verify physical hardware operation.

## 5. Verification

Check the circuit diagram, GPIO assignments, power connections, and firmware before powering the physical prototype.
