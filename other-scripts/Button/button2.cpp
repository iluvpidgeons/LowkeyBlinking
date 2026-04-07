#include <Arduino.h>

/*
  same as button.cpp but without LED, for testing
*/

const int buttonPin = GPIO_NUM_32;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    Serial.println("Button Pressed");
  } else {
    Serial.println("Button Released");
  }
}
