#include <Arduino.h>

/*
  chatgpt wrote most of this I aint that smart
*/

const int micPin = GPIO_NUM_39;
const int resolution = 12;

float alpha = 0.1;   // smaller = smoother and slower, larger = more sensitive and faster
float level = 0;

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
  analogReadResolution(resolution); 
}

void loop() {
  int raw = analogRead(micPin);   // 0–4095
  int centered = raw - 1800;       // remove DC offset
  float amplitude = abs(centered ); // get signal strength

  level = alpha * amplitude + (1 - alpha) * level;

  Serial.print("RAW: ");
  Serial.print(raw);
  Serial.print(" Smooth: ");
  Serial.println(level);
  delay(2);
}