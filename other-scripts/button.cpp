#include <Arduino.h>
#include <Bounce2.h>

/*
  lowk dont know how most of this works
*/

const int BUTTON_PIN = GPIO_NUM_22; // button pin
const int LED_PIN1 = GPIO_NUM_23; // LED pin

int lastButtonState = HIGH; // Store button status (HIGH = 1, LOW = 0)
int ledState = LOW; // Tracks the current state of the LED

Bounce2::Button button = Bounce2::Button();

void momentaryLight() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    digitalWrite(LED_PIN1, HIGH); // turn LED on when button pressed
  }
  else {
    digitalWrite(LED_PIN1, LOW); // turn LED off when button not pressed
  }
}

void changestate() {
    if (ledState == LOW) {
      ledState = HIGH;
    }
    else {
      ledState = LOW;
    }
    digitalWrite(LED_PIN1, ledState);
}

void lightSwitch() {  
  int buttonState = digitalRead(BUTTON_PIN);

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
  pinMode(LED_PIN1, OUTPUT);
  button.attach(BUTTON_PIN, INPUT_PULLUP);
  button.interval(25); // set debounce interval to 25 milliseconds
}

void loop() {
  lightSwitchDebounced();
}
