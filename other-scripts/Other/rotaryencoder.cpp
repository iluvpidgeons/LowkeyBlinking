#include <Arduino.h>

/*
  Not finished yet
*/

const int CLK = GPIO_NUM_16;
const int DT = GPIO_NUM_17;
const int SW = GPIO_NUM_18;
const int buzzerPin = GPIO_NUM_19;

int counter = 0;
int lastCLKState;
int currentCLKState;

void setup() {
  Serial.begin(115200);
  // I dont know if these should all be INPUT_PULLUP
  pinMode(CLK, INPUT_PULLUP); // knob movement
  pinMode(DT, INPUT_PULLUP); // direction
  pinMode(SW, INPUT_PULLUP); // button (optional)
  pinMode(buzzerPin, OUTPUT);

  lastCLKState = digitalRead(CLK);
}

void loop() {
  currentCLKState = digitalRead(CLK);

  // Detect rotation, I lowkey didnt write this part
  if (currentCLKState != lastCLKState && currentCLKState == LOW) {

    if (digitalRead(DT) != currentCLKState) {
      counter++;
    } else {
      counter--;
    }
  }

  lastCLKState = currentCLKState;

  if ((digitalRead(CLK) == 0) || (digitalRead(SW) == 0)) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  
  Serial.print("CLK: ");
  Serial.print(digitalRead(CLK));
  Serial.print(" DT: ");
  Serial.print(digitalRead(DT));
  Serial.print(" SW: ");
  Serial.print(digitalRead(SW));
  Serial.print(", ");
  Serial.println(counter);
}