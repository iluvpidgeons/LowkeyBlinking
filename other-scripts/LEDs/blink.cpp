#include <Arduino.h>

const int ledPin3 = GPIO_NUM_18;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  digitalWrite(ledPin3, HIGH);
  Serial.println("LED ON");
  delay(1000);
  digitalWrite(ledPin3, LOW);
  Serial.println("LED OFF");
  delay(1000);
}