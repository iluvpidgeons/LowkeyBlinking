#include <Arduino.h>

const int latchPin = GPIO_NUM_22;
const int clockPin = GPIO_NUM_23;
const int dataPin = GPIO_NUM_21;

byte leds = 0;

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  updateShiftRegister();
}

void loop() {
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    updateShiftRegister();
    bitClear(leds, i);
    delay(500);
  }

  for (int i = 6; i > 0; i--) {
    bitSet(leds, i);
    updateShiftRegister();
    bitClear(leds, i);
    delay(500);
  }
}