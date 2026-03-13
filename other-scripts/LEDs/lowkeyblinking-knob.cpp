#include <Arduino.h>

/*
  this is one of the first scripts I made so im not gonna edit it but I forgot to add an analogReadResolution
*/

int potPin = GPIO_NUM_36; // Analog input pin
int ledPin1 = GPIO_NUM_16;
int ledPin2 = GPIO_NUM_17;
int ledPin3 = GPIO_NUM_18;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(potPin);
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  delay(sensorValue);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  delay(sensorValue);

  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(sensorValue);
}
