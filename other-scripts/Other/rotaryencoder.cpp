#include <Arduino.h>

/*
  Not finished yet
*/

const int CLK = GPIO_NUM_16;
const int DT = GPIO_NUM_17;
const int SW = GPIO_NUM_23;
const int buzzerPin = GPIO_NUM_18;

int counter = 0;
int lastCLKState;
int currentCLKState;

void setup() {
  Serial.begin(115200);
  pinMode(CLK, INPUT); // knob movement
  pinMode(DT, INPUT); // direction
  pinMode(SW, INPUT_PULLUP); // button
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
  Serial.print(",");
  Serial.println(counter);
}