#include <Arduino.h>
// #include <BleKeyboard.h>
// #include <BleMouse.h>

/*
  The bluetooth library doesnt work yet
*/

const int buttonPin = GPIO_NUM_23;
// BleMouse bleMouse;

void setup() {
  Serial.begin(115200);
  // bleMouse.begin();
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // if (bleMouse.isConnected()) {
  //   if (digitalRead(buttonPin) == LOW) {
  //     bleMouse.press(MOUSE_LEFT);
  //     Serial.println("Pressed");
  //   } else {
  //     bleMouse.release(MOUSE_LEFT);
  //     Serial.println("Released");
  //   }
  // }
}