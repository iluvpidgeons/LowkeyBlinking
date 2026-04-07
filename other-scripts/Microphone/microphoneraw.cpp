#include <Arduino.h>

/*
  when silent it usally sits around 1600
  when loud instead of reading 4095 it reads 0
*/

const int micPin = GPIO_NUM_39;
const int resolution = 12;
int micValue;

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
  analogReadResolution(resolution);
}

void loop() {
  micValue = analogRead(micPin);
  if (micValue == 0) {
    Serial.println("4095");
  } else {
    Serial.println(micValue);
  }
  delay(10); // ~100 Hz sampling
}