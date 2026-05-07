#include <Arduino.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS 1000

PulseOximeter pox;
uint32_t tsLastReport = 0;

void onBeatDetected() {
    Serial.println("Beat detected!");
}

void setup() {
    Serial.begin(115200);

    Wire.begin(21, 22);

    Serial.println("Initializing MAX30100...");

    if (!pox.begin()) {
        Serial.println("MAX30100 failed");
        while (1);
    }

    Serial.println("MAX30100 initialized");

    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  pox.update();

  if (millis() - tsLastReport > 1000) {
    Serial.print("Heart rate: ");
    Serial.print(pox.getHeartRate());
    Serial.print(" bpm / SpO2: ");
    Serial.println(pox.getSpO2());

    tsLastReport = millis();
  }
}