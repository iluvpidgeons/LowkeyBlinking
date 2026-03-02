#include <Arduino.h>
const int ledPinRed = GPIO_NUM_16;
const int ledPinGreen = GPIO_NUM_17;
const int ledPinBlue = GPIO_NUM_18;

//only should be r y or g
void light(char color, int time) {
  if (color == 'r') {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinGreen, HIGH);
  } else if (color == 'g') {
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinGreen, LOW);
  } else if (color == 'y') {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinBlue, HIGH);
    digitalWrite(ledPinGreen, LOW);
  }
  Serial.print(color);
  Serial.print(", ");
  Serial.println(time);
  delay(time);
}


void setup() {
  Serial.begin(115200);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
}

void loop() {
  light('r', 1000);
  light('y', 1000);
  light('g', 1000);
}