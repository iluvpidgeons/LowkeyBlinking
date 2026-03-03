#include <Arduino.h>
// #include <BleKeyboard.h>
// #include <BleMouse.h>

/*
  The bluetooth library doesnt work yet
*/

const int micPin = GPIO_NUM_39;
const int resolution = 12;
int micValue;

// BleMouse bleMouse("Diddyblud Mouse", "ESP32", 100);

void setup() {
  Serial.begin(115200);
  // bleMouse.begin();
  analogReadResolution(resolution);
}

void loop() {
  micValue = analogRead(micPin);
  Serial.println(micValue);
}