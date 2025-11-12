#include <Arduino.h>

const int ledPins[] = {
  GPIO_NUM_16, GPIO_NUM_17, GPIO_NUM_18, GPIO_NUM_19, GPIO_NUM_15,
  GPIO_NUM_21, GPIO_NUM_22, GPIO_NUM_23, GPIO_NUM_32, GPIO_NUM_33
};

const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);
const int delayTime = 100; // milliseconds

void setup() {
  // Set all LED pins as outputs
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH); // initialize as HIGH
  }
}

void loop() {
  // Loop through LEDs one by one
  for (int i = 0; i < ledCount; i++) {
    // Turn all LEDs ON
    for (int j = 0; j < ledCount; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    // Turn current LED OFF
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}
