#include <Arduino.h>

const int micPin = GPIO_NUM_39;
const int resolution = 12;
int micValue;

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
  analogReadResolution(resolution);
}

void loop() {
  micValue = analogRead(micPin); // whenever maxed out, instead of reading 4095 it reads 0 and this script adjusts that
  if (micValue == 0) {
    Serial.println("4095");
  } else {
    Serial.println(micValue);
  }
  delay(10); // ~100 Hz sampling
}