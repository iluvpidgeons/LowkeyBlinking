#include <Arduino.h>

const int buttonPin = GPIO_NUM_4;
const int ledPin3 = GPIO_NUM_18;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin3, HIGH);
    Serial.println("Button Pressed");
  } else {
    digitalWrite(ledPin3, LOW);
    Serial.println("Button Released");
  }
}
