#include <Arduino.h>

/*
  this script uses 3 potentiometers omg bro
*/

const int ledPinRed = GPIO_NUM_16;
const int ledPinGreen = GPIO_NUM_17;
const int ledPinBlue = GPIO_NUM_18;

const int potPin1 = GPIO_NUM_36;
const int potPin2 = GPIO_NUM_39;
const int potPin3 = GPIO_NUM_34;

const int resolution = 8;

void setup() {
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);

  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
  pinMode(potPin3, INPUT);

  analogReadResolution(resolution);
  Serial.begin(115200);
}

void loop() {
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);
  int potValue3 = analogRead(potPin3);
  
  analogWrite(ledPinRed, potValue1);
  analogWrite(ledPinGreen, potValue2);
  analogWrite(ledPinBlue, potValue3);

  Serial.print(potValue1);
  Serial.print(", ");
  Serial.print(potValue2);
  Serial.print(", ");
  Serial.println(potValue3);
}