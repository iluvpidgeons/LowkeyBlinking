#include <Arduino.h>

/*
  chatgpt wrote most of ts
*/

const int micPin = 39;
const int numSamples = 20;       // Number of samples for smoothing
int samples[numSamples];          // Array to store samples

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < numSamples; i++) samples[i] = 0; // initialize array
}

void loop() {
  // Shift all samples left and add new reading at the end
  for (int i = 0; i < numSamples - 1; i++) {
    samples[i] = samples[i + 1];
  }
  samples[numSamples - 1] = analogRead(micPin);

  // Calculate average
  long sum = 0;
  for (int i = 0; i < numSamples; i++) sum += samples[i];
  float avg = sum / (float)numSamples;

  Serial.print("RAW: ");
  Serial.print(analogRead(micPin));
  Serial.print(" Smooth: ");
  Serial.println(avg);

  delay(10);  // ~100 Hz sampling
}