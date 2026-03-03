#include <Arduino.h>

const int micPin = GPIO_NUM_39;
const int resolution = 12;
int micValue;

void setup() {
  Serial.begin(115200);
  analogReadResolution(resolution);
}

void loop() {
  micValue = analogRead(micPin);
  Serial.println(micValue);
  delay(100);
}