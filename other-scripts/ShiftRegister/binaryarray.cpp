#include <Arduino.h>

const int latchPin = GPIO_NUM_22; // Pin connected to the ST_CP pin of the 74HC595
const int clockPin = GPIO_NUM_23; // Pin connected to the SH_CP pin of the 74HC595
const int dataPin = GPIO_NUM_21; // Pin connected to the DS pin of the 74HC595

int datArray[] = {B00000000
  , B00000001
  , B00000011
  , B00000111
  , B00001111
  , B00011111
  , B00111111
  , B01111111
};

void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop () {
  for(int num = 0; num <8; num++)
  {
    digitalWrite(latchPin, LOW); // ground ST_CP and hold low for as long as you are transmitting
    shiftOut(dataPin, clockPin, MSBFIRST, datArray[num]);
    digitalWrite(latchPin, HIGH); // pull the ST_CP to save the data
    delay(1000);
  }
}