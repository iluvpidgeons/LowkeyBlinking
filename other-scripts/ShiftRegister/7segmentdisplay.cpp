#include <Arduino.h>

const int latchPin = GPIO_NUM_22;
const int clockPin = GPIO_NUM_23;
const int dataPin = GPIO_NUM_21;

const byte blank = 0b11111111; // All segments off
const byte digits[] = {
  // a b c d e f g DP
  0b00000011, // 0
  0b10011111, // 1
  0b00100101, // 2
  0b00001101, // 3
  0b10011001, // 4
  0b01001001, // 5
  0b01000001, // 6
  0b00011111, // 7
  0b00000001, // 8
  0b00011001  // 9
};

void updateShiftRegister(byte pattern) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, pattern);
  digitalWrite(latchPin, HIGH);
}

void countdown () {
  for (int i = 9; i >= 0; i--) {
    updateShiftRegister(digits[i]); // Display numbers
    delay(1000); // Wait for 1 second
  }
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  updateShiftRegister(blank);
}

void loop () {
  countdown();
}