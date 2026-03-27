#include <Arduino.h>

const int latchPin = GPIO_NUM_22; // Pin connected to the ST_CP pin of the 74HC595
const int clockPin = GPIO_NUM_23; // Pin connected to the SH_CP pin of the 74HC595
const int dataPin = GPIO_NUM_21; // Pin connected to the DS pin of the 74HC595

// Variable to hold the state of the LEDs (8 bits for 8 LEDs)
byte leds = 0;

// Function to update the shift register with the current state of the leds byte
void updateShiftRegister() {
  digitalWrite(latchPin, LOW); // Set latchPin LOW to prevent changes while shifting
  shiftOut(dataPin, clockPin, MSBFIRST, leds); // Send the byte to the shift register
  digitalWrite(latchPin, HIGH); // Set latchPin high to update the outputs
}

void setup() {
  // Initialize the pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  updateShiftRegister();
}

void loop() {
  // Example 1: Light up all LEDs one by one
  for (int i = 0; i < 8; i++) {
    bitSet(leds, i);
    bitClear(leds, i-1);
    if (i == 0) {
      bitClear(leds, 7); // Clear the last LED when the first is lit
    }
    updateShiftRegister();
    delay(500); // Wait before turning on the next LED
  }
}

// bitClear() turns the leds off