#include <Arduino.h>

/*
  I will rewrite this later
*/

const int buttonPin = GPIO_NUM_4;
const int ledPin3 = GPIO_NUM_18;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // empty
}