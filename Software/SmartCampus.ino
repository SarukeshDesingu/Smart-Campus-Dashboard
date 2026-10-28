/*
  Project Name : Smart Campus Dashboard
  Controller   : ESP32
  IDE          : Arduino IDE

  Description:
  An ESP32-based monitoring system that collects sensor
  readings and displays available measurements through
  the Serial Monitor and configured cloud dashboard.

  Features:
  - Sensor data acquisition
  - Serial Monitor output
  - Cloud dashboard communication
  - Relay control according to implemented logic

  Project Type: Mini Project
*/

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Campus Dashboard"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <Arduino.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ---------- Wi-Fi ----------
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// ---------- ESP32 pin connections ----------
// Change these pins to match your actual wiring.
const int VOLTAGE_PIN = 34;  // ZMPT101B analog output
const int CURRENT_PIN = 35;  // ACS712 analog output
const int RELAY_PIN   = 26;  // Relay input

// Set according to your relay module:
// Many relay modules are active LOW.
const int RELAY_ON  = LOW;
const int RELAY_OFF = HIGH;

// ---------- Calibration settings ----------
// Replace these with values determined through calibration.
float VOLTAGE_CALIBRATION = 1.00f;
float CURRENT_CALIBRATION = 1.00f;

// ADC configuration
const float ADC_REFERENCE = 3.3f;
const int ADC_MAX_VALUE = 4095;

// Samples per measurement
const int NUM_SAMPLES = 2000;

// ---------- Protection setting ----------
// Set to 0 to disable automatic overcurrent switching.
// This is an educational prototype, NOT certified protection.
const float CURRENT_LIMIT_A = 0.0f;

BlynkTimer timer;

float voltageRMS = 0.0f;
float currentRMS = 0.0f;
float powerWatts = 0.0f;

bool relayEnabled = false;
bool blynkConnected = false;

// ---------- Read RMS voltage from analog sensor ----------
float readVoltageRMS() {
  double sumSquares = 0.0;
  double mean = 0.0;

  // Estimate ADC midpoint to remove DC offset.
  for (int i = 0; i < NUM_SAMPLES; i++) {
    mean += analogRead(VOLTAGE_PIN);
    delayMicroseconds(150);
  }
  mean /= NUM_SAMPLES;

  for (int i = 0; i < NUM_SAMPLES; i++) {
    float sample = analogRead(VOLTAGE_PIN);
    float centered = sample - mean;
    sumSquares += centered * centered;
    delayMicroseconds(150);
  }

  float adcRMS = sqrt(sumSquares / NUM_SAMPLES);
  float sensorVoltageRMS =
      (adcRMS * ADC_REFERENCE) / ADC_MAX_VALUE;

  // This factor must be calibrated against a trusted meter.
  return sensorVoltageRMS * VOLTAGE_CALIBRATION;
}

// ---------- Read RMS current from ACS712 ----------
float readCurrentRMS() {
  double mean = 0.0;

  // Estimate sensor's zero-current midpoint.
  for (int i = 0; i < NUM_SAMPLES; i++) {
    mean += analogRead(CURRENT_PIN);
    delayMicroseconds(150);
  }
  mean /= NUM_SAMPLES;

  double sumSquares = 0.0;

  for (int i = 0; i < NUM_SAMPLES; i++) {
    float sample = analogRead(CURRENT_PIN);
    float centered = sample - mean;
    sumSquares += centered * centered;
    delayMicroseconds(150);
  }

  float adcRMS = sqrt(sumSquares / NUM_SAMPLES);
  float sensorVoltageRMS =
      (adcRMS * ADC_REFERENCE) / ADC_MAX_VALUE;

  // Typical ACS712 sensitivities:
  // 5A module  = 0.185 V/A
  // 20A module = 0.100 V/A
  // 30A module = 0.066 V/A
  //
  // Choose the correct sensitivity for your exact module.
  const float ACS712_SENSITIVITY = 0.100f; // Example: 20A module

  float amps = sensorVoltageRMS / ACS712_SENSITIVITY;
  amps *= CURRENT_CALIBRATION;

  // Suppress small noise readings; tune after calibration.
  if (amps < 0.05f) {
    amps = 0.0f;
  }

  return amps;
}

// ---------- Relay control ----------
void setRelay(bool turnOn) {
  relayEnabled = turnOn;
  digitalWrite(RELAY_PIN, turnOn ? RELAY_ON : RELAY_OFF);

  if (blynkConnected && Blynk.connected()) {
    Blynk.virtualWrite(V3, relayEnabled ? 1 : 0);
  }
}

// Blynk button on Virtual Pin V3
BLYNK_WRITE(V3) {
  int requestedState = param.asInt();
  setRelay(requestedState == 1);
}

// ---------- Update readings and dashboard ----------
void updateReadings() {
  voltageRMS = readVoltageRMS();
  currentRMS = readCurrentRMS();

  // Apparent power estimate only.
  // True real power requires power-factor-aware measurement.
  powerWatts = voltageRMS * currentRMS;

  // Optional demonstration threshold.
  if (CURRENT_LIMIT_A > 0.0f &&
      currentRMS > CURRENT_LIMIT_A) {
    setRelay(false);
  }

  Serial.println();
  Serial.println("===== SMART CAMPUS DASHBOARD =====");
  Serial.print("Voltage : ");
  Serial.print(voltageRMS, 1);
  Serial.println(" V");

  Serial.print("Current : ");
  Serial.print(currentRMS, 2);
  Serial.println(" A");

  Serial.print("Power   : ");
  Serial.print(powerWatts, 1);
  Serial.println(" VA (estimated apparent power)");

  Serial.print("Relay   : ");
  Serial.println(relayEnabled ? "ON" : "OFF");
  Serial.println("==================================");

  if (blynkConnected && Blynk.connected()) {
    Blynk.virtualWrite(V0, voltageRMS);
    Blynk.virtualWrite(V1, currentRMS);
    Blynk.virtualWrite(V2, powerWatts);
    Blynk.virtualWrite(V3, relayEnabled ? 1 : 0);
  }
}

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);

  analogReadResolution(12);
  analogSetPinAttenuation(VOLTAGE_PIN, ADC_11db);
  analogSetPinAttenuation(CURRENT_PIN, ADC_11db);

  Serial.println("Smart Campus Dashboard Starting...");
  Serial.println("Relay defaults to OFF.");

  WiFi.mode(WIFI_STA);
  Blynk.config(BLYNK_AUTH_TOKEN);

  WiFi.begin(ssid, pass);

  Serial.print("Connecting to Wi-Fi");
  unsigned long startAttempt = millis();

  while (WiFi.status() != WL_CONNECTED &&
         millis() - startAttempt < 15000) {
    delay(300);
    Serial.print(".");
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wi-Fi connected.");
    blynkConnected = Blynk.connect(5000);
  } else {
    Serial.println("Wi-Fi unavailable; continuing offline.");
  }

  timer.setInterval(3000L, updateReadings);
  updateReadings();
}

// ---------- Main loop ----------
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (!Blynk.connected()) {
      blynkConnected = Blynk.connect(100);
    } else {
      blynkConnected = true;
      Blynk.run();
    }
  } else {
    blynkConnected = false;
  }

  timer.run();
}
