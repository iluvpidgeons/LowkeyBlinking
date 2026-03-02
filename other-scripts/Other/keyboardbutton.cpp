#include <Arduino.h>
// #include "USB.h"
#include "USBHIDKeyboard.h"

/*
  THIS DOES NOT WORK
*/

void setup() {
  // Start the keyboard service
  Keyboard.begin();
  USB.begin();
  
  // Wait for 5 seconds to give you time to open a text editor
  delay(5000);
  
  // Type text
  Keyboard.println("Hello World from ESP32-S3!");
}

void loop() {
  // Empty loop
}