#include <Arduino.h>

const int latchPin = GPIO_NUM_22;
const int clockPin = GPIO_NUM_23;
const int dataPin = GPIO_NUM_21;
const int ledPin3 = GPIO_NUM_18;
const int buzzerPin = GPIO_NUM_19;

/*
  not finished yet
  im gonna add some explosion thing at some point
*/

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

const byte blank = B11111111;

void updateShiftRegister(byte pattern) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, pattern);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  updateShiftRegister(blank);
  digitalWrite(ledPin3, LOW);
}

void loop () {
  for (int i = 9; i >= 5; i--) {
    updateShiftRegister(digits[i]);
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(997);
  }
  for (int i = 4; i >= 2; i--) {
    updateShiftRegister(digits[i]);
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(497);
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(497);
  }
  for (int i = 2; i >= 0; i--) {
    updateShiftRegister(digits[i]);
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(247);
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(247);
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(247);
    digitalWrite(buzzerPin, HIGH);
    delay(3);
    digitalWrite(buzzerPin, LOW);
    delay(247);
  }

  digitalWrite(ledPin3, HIGH);
  for (int i = 0; i < 50; i++) {
      digitalWrite(buzzerPin, HIGH); // Set to HIGH to make the buzzer sound
      delay(3); // Wait for 3 milliseconds
      digitalWrite(buzzerPin, LOW); // LOW to turn off the buzzer
      delay(3); // 
  }
  delay(1000);
}
