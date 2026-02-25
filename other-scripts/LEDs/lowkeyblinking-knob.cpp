#include <Arduino.h>

int sensorPin = GPIO_NUM_33; // Analog input pin
int ledPin1 = GPIO_NUM_16;
int ledPin2 = GPIO_NUM_17;
int ledPin3 = GPIO_NUM_18;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue;
  sensorValue = analogRead(sensorPin);
  
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
