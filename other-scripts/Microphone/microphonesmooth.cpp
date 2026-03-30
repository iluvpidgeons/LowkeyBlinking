#include <Arduino.h>

/*
  chatgpt wrote most of this I aint that smart
*/

const int micPin = GPIO_NUM_39;
// const int ledPin1 = GPIO_NUM_16;
// const int ledPin2 = GPIO_NUM_17;
// const int ledPin3 = GPIO_NUM_18;
const int resolution = 12;

float alpha = 0.1;   // smaller = smoother and slower, larger = more sensitive and faster
float level = 0;

void setup() {
  Serial.begin(115200);
  pinMode(micPin, INPUT);
  // pinMode(ledPin1, OUTPUT);
  // pinMode(ledPin2, OUTPUT);
  // pinMode(ledPin3, OUTPUT);
  analogReadResolution(resolution); 
}

void loop() {
  int raw = analogRead(micPin);   // 0–4095
  int centered = raw - 1800;       // remove DC offset
  float amplitude = abs(centered ); // get signal strength

  level = alpha * amplitude + (1 - alpha) * level;

  // if (level < 1750) { // threshold for LED
  //   digitalWrite(ledPin1, HIGH);
  // } else {
  //   digitalWrite(ledPin1, LOW);
  // }
  // if (level < 1600) {
  //   digitalWrite(ledPin2, HIGH);
  // } else {
  //   digitalWrite(ledPin2, LOW);
  // }
  // if (level < 1500) {
  //   digitalWrite(ledPin3, HIGH);
  // } else {
  //   digitalWrite(ledPin3, LOW);
  // }
  
  Serial.print("RAW: ");
  Serial.print(raw);
  Serial.print(" Smooth: ");
  Serial.println(level);
  delay(2);
}