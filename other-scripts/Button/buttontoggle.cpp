#include <Arduino.h>

/*
  This didnt work because THERE WASNT A SINGLE DIGITALWRITE LINE
*/

const int buttonpin = GPIO_NUM_23;
const int ledPin3 = GPIO_NUM_18;
const int resolution = 8; // 8 bits resolution, values from 0 to 255

int buttonState;
int ledState = HIGH;

void changestate(int speed) {
    if (ledState == LOW) {
      for (int i = 0; i <= 255; i++) {
        analogWrite(ledPin3, i);
        delay(speed / 255);
      }
      ledState = HIGH;
    } else {
      for (int i = 255; i >= 0; i--) {
        analogWrite(ledPin3, i);
        delay(speed / 255);
      }
      ledState = LOW;
    }
    digitalWrite(ledPin3, ledState);
    Serial.print("Button Pressed, ");
    Serial.println(ledState);
} // I am going to make this fade in and out depending on the speed varible

void setup() {
  Serial.begin(115200);
  pinMode(buttonpin, INPUT_PULLUP);
  pinMode(ledPin3, OUTPUT);
  analogReadResolution(resolution);
  digitalWrite(ledPin3, ledState);
}

void loop() {
  int buttonState = digitalRead(buttonpin);
  if (buttonState == LOW) {
    changestate(500);
    int buttonState = digitalRead(buttonpin);
    if  (buttonState == LOW) {
      while (digitalRead(buttonpin) == LOW) {
        // do nothing
      }
    }
  }
}