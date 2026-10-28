# Software Implementation

## 1. Overview

The Smart Campus Dashboard is developed using the ESP32 microcontroller and Arduino IDE. The software collects sensor readings, processes the data, displays diagnostic information through the Serial Monitor, and sends supported readings to a cloud dashboard when configured.

## 2. Source Code

**File:** `SmartCampus.ino`

The source code is responsible for:
- Initializing the ESP32 and connected sensors.
- Reading voltage and current sensor signals.
- Processing sensor readings.
- Displaying readings and system status in the Serial Monitor.
- Communicating with the configured cloud dashboard.
- Controlling the relay according to the implemented program logic.

## 3. Cloud Dashboard

**Image:** `cloud-dashboard.png`

The cloud dashboard provides a visual interface for monitoring the system. Depending on the implemented features, it displays electrical measurements such as voltage, current, power, and relay status.

The dashboard helps users observe system readings remotely when the ESP32 and dashboard service are connected.

## 4. Arduino IDE Serial Monitor Output

**Image:** `serial-monitor.png`

The Arduino IDE Serial Monitor displays sensor readings and diagnostic messages transmitted by the ESP32. It is useful for checking program execution, observing sensor values, and troubleshooting communication or sensor issues.

## 5. Software Workflow

1. The ESP32 initializes the connected sensors and configured communication services.
2. The program reads and processes sensor data.
3. Measurements and status messages are printed to the Serial Monitor.
4. Supported measurements are transmitted to the cloud dashboard when connectivity is available.
5. Relay operation follows the conditions programmed in the firmware.

## 6. Development Tools

- Arduino IDE
- ESP32 board support package
- Required sensor libraries
- Cloud dashboard platform used in the project

## 7. Testing and Verification

The software can be tested by observing Serial Monitor readings, checking cloud dashboard updates, and verifying sensor and relay behavior under appropriate test conditions.

## 8. Security

Wi-Fi passwords, dashboard authentication tokens, and other confidential credentials should not be included in publicly accessible source code or screenshots.

## 9. Project Status

Update this section to describe the current development and testing status of the Smart Campus Dashboard mini project.
