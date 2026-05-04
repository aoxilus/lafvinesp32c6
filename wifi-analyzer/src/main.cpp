#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n==================================");
  Serial.println("ESP32-C6 Test Firmware Loaded");
  Serial.println("Board: UeeKKoo ESP32-C6-1.47 LCD");
  Serial.println("Upload successful via COM10");
  Serial.println("==================================\n");
  Serial.println("If you see this, flashing works!");
  Serial.println("Next step: Full WiFi scanner with LCD + SD card.");
}

void loop() {
  Serial.println("Test running... (alive on COM10)");
  delay(5000);
}
