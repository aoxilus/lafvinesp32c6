#include <Arduino.h>

// Pin definitions for your board
#define TFT_BL    22   // Backlight pin

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("\n=== LCD Backlight + Basic Test ===");
  Serial.println("Board: UeeKKoo ESP32-C6-1.47 LCD");

  // Turn on backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  Serial.println("Backlight pin (GPIO22) set HIGH");

  // Try to initialize with minimal code
  Serial.println("If your screen has a backlight, it should now be on (white/bright).");
  Serial.println("If nothing appears, the display initialization needs different pins or driver.");
}

void loop() {
  Serial.println("Test running - backlight should be on.");
  delay(3000);
}
