#include <Arduino.h>

const int micPin = GPIO_NUM_39;
const int resolution = 12;
const int ledPin1 = GPIO_NUM_16;
const int ledPin2 = GPIO_NUM_17;
const int ledPin3 = GPIO_NUM_18;

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  analogReadResolution(resolution);
}

void loop() {
  int readVal = analogRead(micPin);
  // change these values, the microphone currently sits at around 1600 when idle
  if (readVal > 3000) {
    Serial.println("> 3000");
  } else if (readVal > 2000) {
    Serial.println("> 2000");
  } else if (readVal > 1000) {
    Serial.println("> 1000");
  } else if (readVal > 500) {
    Serial.println("> 500");
  } else if (readVal > 100) {
    Serial.println("> 100");
  }
  delay(10); // ~100 Hz sampling
}
