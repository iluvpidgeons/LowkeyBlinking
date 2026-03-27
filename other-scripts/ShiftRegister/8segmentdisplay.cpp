#include <Arduino.h>

const int latchPin = GPIO_NUM_22; // Pin connected to the ST_CP pin of the 74HC595
const int clockPin = GPIO_NUM_23; // Pin connected to the SH_CP pin of the 74HC595
const int dataPin = GPIO_NUM_21; // Pin connected to the DS pin of the 74HC595

// Array to store the segment patterns for digits 0-9 and a black (all off)
// For a common cathode (+) a '0' (LOW) turns on a segment, a '1' (HIGH) turns it off.
byte digits[] = {
  // a b c d e f g DP
  B00000011, // 0
  B10011111, // 1
  B00100101, // 2
  B00001101, // 3
  B10011001, // 4
  B01001001, // 5
  B01000001, // 6
  B00011111, // 7
  B00000001, // 8
  B00001001  // 9
};

byte letters[] = {
  B10010001, // H
  B01100001, // E
  B11100011, // L
  B11100010, // L2
  B00000011, // O
};

byte blank = B11111111; // All segments off

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
  for (int i = 0; i <= 4; i++) {
    updateShiftRegister(letters[i]); // Display letters
    delay(1000); // Wait for 1 second
  }
}

void setup() {
  // Initialize the pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  updateShiftRegister(blank);
}

void loop () {
  countdown();
}