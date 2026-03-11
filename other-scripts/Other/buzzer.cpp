#include <Arduino.h>

const int buzzerPin = GPIO_NUM_18;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 50; i++) // Loop 50 times and play a short tone each time
  {
    digitalWrite(buzzerPin, HIGH); // Set to HIGH to make the buzzer sound
    delay(3); // Wait for 3 milliseconds
    digitalWrite(buzzerPin, LOW); // LOW to turn off the buzzer
    delay(3); // 
  }
  delay(1000); // Wait for 1s before starting the next loop
}