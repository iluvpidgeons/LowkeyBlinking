#include <Arduino.h>

/*
  chatgpt wrote most of ts
  this is broken and unfinished
*/

const int micPin = 39;
const int resolution = 12;
const int numSamples = 20;       // Number of samples for smoothing
int samples[numSamples];          // Array to store samples

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
  analogReadResolution(resolution);
  for (int i = 0; i < numSamples; i++) samples[i] = 0; // initialize array
}

void loop() {
  // Shift all samples left and add new reading at the end
  for (int i = 0; i < numSamples; i++) {
    samples[i] = analogRead(micPin);
  }


  // samples[numSamples - 1] = analogRead(micPin);

  // Calculate average
  long sum = 0;
  for (int i = 0; i < numSamples; i++) {
    sum += samples[i];
  }

  float avg = (float)sum / (float)numSamples;

  // Serial.print("RAW: ");
  // Serial.print(analogRead(micPin));
  int readVal = analogRead(micPin);
  // if (readVal < 1000) Serial.print(" ");
  // if (readVal < 100)  Serial.print(" ");
  // if (readVal < 10)   Serial.print(" ");
  // Serial.print(readVal);
  // Serial.print(" Smooth: ");
  // Serial.println(avg);
  // Serial.print("RAW: ");
  // if (analogRead(micPin) < 1000) Serial.print(" ");
  // if (analogRead(micPin) < 100)  Serial.print(" ");
  // if (analogRead(micPin) < 10)   Serial.print(" ");
  // Serial.print(analogRead(micPin));

  // Serial.print("   Smooth: ");
  // if (avg < 1000) Serial.print(" ");
  // if (avg < 100)  Serial.print(" ");
  // if (avg < 10)   Serial.print(" ");
  // Serial.println(avg);

  delay(10); // ~100 Hz sampling
  if (readVal > 3000) {
    Serial.println("> 3000");
  } else if (readVal > 2000) {
    Serial.println("> 2000");
  } else if (readVal > 1000) {
    Serial.println("> 1000");
  } else if (readVal > 500) {
    Serial.println("> 500");
  } else if (readVal > 100) {
    Serial.println("> 100");
  }

}
