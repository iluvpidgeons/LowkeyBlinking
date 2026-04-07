#include <Arduino.h>
#include <Bounce2.h>

/*
  lowk dont know how most of this works
*/

const int buttonPin = GPIO_NUM_32; // button pin
const int ledPin3 = GPIO_NUM_18; // LED pin

int lastButtonState = HIGH; // Store button status (HIGH = 1, LOW = 0)
int ledState = LOW; // Tracks the current state of the LED

Bounce2::Button button = Bounce2::Button();

void momentaryLight() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(ledPin3, HIGH); // turn LED on when button pressed
  }
  else {
    digitalWrite(ledPin3, LOW); // turn LED off when button not pressed
  }
}

void changestate() {
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin3, ledState);
}

void lightSwitch() {  
int buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == HIGH) {
      changestate();
    }
  }
}

void lightSwitchDebounced() {
  button.update();
  if (button.released()) { // button pressed
    changestate();
  }
}

void setup() {
  pinMode(ledPin3, OUTPUT);
  button.attach(buttonPin, INPUT_PULLUP);
  button.interval(25); // set debounce interval to 25 milliseconds
}

void loop() {
  lightSwitchDebounced();
}
