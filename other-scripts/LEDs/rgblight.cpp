#include <Arduino.h>

const int ledRedPin = GPIO_NUM_16;
const int ledGreenPin = GPIO_NUM_17;
const int ledBluePin = GPIO_NUM_18;

void red(int duration) {
  analogWrite(ledRedPin, 0);
  analogWrite(ledGreenPin, 255);
  analogWrite(ledBluePin, 255);
  delay(duration);
}

void green(int duration) {
  analogWrite(ledRedPin, 255);
  analogWrite(ledGreenPin, 0);
  analogWrite(ledBluePin, 255);
  delay(duration);
}

void blue(int duration) {
  analogWrite(ledRedPin, 255);
  analogWrite(ledGreenPin, 255);
  analogWrite(ledBluePin, 0);
  delay(duration);
}

void setup() {
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
}

void loop() {
  red(500);
  green(500);
  blue(500);
}
