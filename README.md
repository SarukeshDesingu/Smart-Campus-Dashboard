# Smart Campus Dashboard

### ESP32-Based Electrical Monitoring and Protection System

## Overview

The **Smart Campus Dashboard** is an ESP32-based embedded monitoring and protection system designed to monitor electrical parameters and environmental conditions within a campus environment.

The system collects sensor data, processes electrical measurements, and displays the readings through a centralized dashboard for monitoring. It also incorporates abnormal-condition detection, alert generation, and relay-based control according to predefined protection logic.

This project demonstrates the integration of embedded systems, sensor interfacing, and dashboard-based monitoring to support improved electrical safety and monitoring efficiency.

## Objectives

- Monitor electrical parameters such as voltage, current, and power.
- Display sensor readings through a centralized dashboard.
- Detect abnormal operating conditions and generate alerts.
- Implement relay-based control based on configured protection logic.
- Monitor environmental conditions using additional sensors.
- Demonstrate the practical application of ESP32-based embedded monitoring and protection.

## Hardware Requirements

| Component | Purpose |
|---|---|
| ESP32 Development Board | Main controller for sensor data acquisition and processing |
| ZMPT101B Voltage Sensor | Measures AC voltage |
| ACS712 Current Sensor | Measures electrical current |
| Relay Module | Enables controlled switching based on protection logic |
| Environmental Sensors | Monitor environmental conditions |
| Connecting Wires | Provide electrical connections between components |
| Power Supply | Supplies power to the system |

## Software and Technologies

- **Microcontroller:** ESP32
- **Programming Language:** Embedded C/C++
- **Development Environment:** Arduino IDE
- **Monitoring Interface:** Dashboard platform used in the project
- **System Integration:** Sensor interfacing, data processing, and relay control

## System Working Principle

1. **Data Acquisition:** The ESP32 collects electrical measurements from the ZMPT101B voltage sensor and ACS712 current sensor, along with readings from connected environmental sensors.
2. **Data Processing:** The controller processes the collected sensor readings to obtain measurement values.
3. **Dashboard Monitoring:** The processed readings are displayed on the dashboard for convenient monitoring.
4. **Abnormal Condition Detection:** The system checks the measured parameters against predefined thresholds.
5. **Alert Generation:** Alerts are triggered when configured abnormal conditions are detected.
6. **Relay Control:** The relay operates according to the implemented protection logic to support controlled switching.

## Key Features

- ESP32-based embedded monitoring system.
- Voltage and current measurement.
- Electrical parameter monitoring, including power where implemented.
- Dashboard-based visualization of sensor readings.
- Detection of predefined abnormal conditions.
- Alert generation based on configured conditions.
- Relay-based switching functionality.
- Integration of environmental sensors.
- Practical implementation and testing of an embedded monitoring prototype.

## Applications

- Campus electrical monitoring.
- Electrical equipment condition monitoring.
- Environmental monitoring in campus buildings.
- Laboratory and classroom monitoring.
- Embedded systems and IoT education.
- Demonstration of sensor-based electrical protection concepts.

## Project Status

**Status: Completed — Developed and Tested**

The Smart Campus Dashboard has been successfully developed and tested as a working prototype. The project integrates the ESP32 with electrical and environmental sensors to collect and process measurements and present the readings through a dashboard.

The implemented system also supports abnormal-condition detection, alert generation, and relay-based control according to the configured protection logic. Development and testing provided practical experience in embedded programming, sensor interfacing, system integration, and electrical monitoring.

## Safety Precautions

- Never connect mains voltage directly to the ESP32.
- Use appropriate isolation and properly rated sensors and protection components.
- Verify all wiring and power connections before operating the system.
- Ensure relay modules and connected loads are rated for the intended application.
- Disconnect power before modifying circuit connections.
- Testing involving hazardous voltages must be performed under qualified supervision.

## Contributors

- **Sarukesh D**
- **Gokul S**

## License

No license has been specified
