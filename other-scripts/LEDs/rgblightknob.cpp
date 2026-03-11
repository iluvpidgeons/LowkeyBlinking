#include <Arduino.h>

/*
  This dont work yet but im tryna make a potentiometer go through the color wheel
  I DONT KNOW HOW TO DO THIS IDK SHIT ABOUT COLORS
*/

const int ledPinRed = GPIO_NUM_16;
const int ledPinGreen = GPIO_NUM_17;
const int ledPinBlue = GPIO_NUM_18;

const int potPin = GPIO_NUM_36;
const int resolution = 8; // 0 - 255

void setup() {
  Serial.begin(115200);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  pinMode(potPin, INPUT);

  analogReadResolution(resolution);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);
  
  // start all pins off
  analogWrite(ledPinRed, 255);
  analogWrite(ledPinGreen, 255);
  analogWrite(ledPinBlue, 255);

  if (potValue < 42.5) {
    analogWrite(ledPinRed, 0);
    analogWrite(ledPinGreen, potValue * 6);
  } else if (potValue < 85) {
    analogWrite(ledPinGreen, 0);
    analogWrite(ledPinBlue, potValue * 6);
  } else if (potValue < 127.5) {
    analogWrite(ledPinBlue, 0);
    analogWrite(ledPinRed, potValue * 6);
  } else if (potValue < 170) {
    analogWrite(ledPinRed, 0);
    analogWrite(ledPinGreen, potValue * 6);
  } else if (potValue < 212.5) {
    analogWrite(ledPinGreen, 0);
    analogWrite(ledPinBlue, potValue * 6);
  } else {
    analogWrite(ledPinBlue, 0);
    analogWrite(ledPinRed, potValue * 6);
  }
}