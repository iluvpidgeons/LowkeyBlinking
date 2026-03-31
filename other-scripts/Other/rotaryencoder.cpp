#include <Arduino.h>

/*
  not finished yet
*/

const int SW = GPIO_NUM_16;
const int DT = GPIO_NUM_17;
const int CLK = GPIO_NUM_18;
const int buzzerPin = GPIO_NUM_19;

int counter = 0;
int lastCLKState;
int currentCLKState;

void setup() {
  Serial.begin(115200);
  // I don't know if these should all be INPUT_PULLUP
  pinMode(CLK, INPUT_PULLUP); // knob movement
  pinMode(DT, INPUT_PULLUP); // direction
  pinMode(SW, INPUT_PULLUP); // button (optional)
  pinMode(buzzerPin, OUTPUT);

  lastCLKState = digitalRead(CLK);
}

void loop() {
  currentCLKState = digitalRead(CLK);

  // detect rotation, I lowkey didn't write this part
  if (currentCLKState != lastCLKState && currentCLKState == LOW) {

    if (digitalRead(DT) != currentCLKState) {
      counter++;
    } else {
      counter--;
    }
  }

  lastCLKState = currentCLKState;

  // ill rewrite this later
  if ((digitalRead(CLK) == 0) || (digitalRead(SW) == 0)) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  
  // theres prolly a better way to format this but idk
  Serial.print("CLK: ");
  Serial.print(digitalRead(CLK));
  Serial.print(" DT: ");
  Serial.print(digitalRead(DT));
  Serial.print(" SW: ");
  Serial.print(digitalRead(SW));
  Serial.print(", ");
  Serial.println(counter);
}