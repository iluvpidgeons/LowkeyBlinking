#include <Arduino.h>

/*
  I really dont know how PWM channels work but it shouldn't matter
*/

const int positiveA = GPIO_NUM_13;
const int negativeA = GPIO_NUM_14;
const int enableA = GPIO_NUM_27;
const int potPin = GPIO_NUM_36;

// PWM settings
// const int channel = 0;
const int freq = 20000; // idk really what to set this to
const int resolution = 8; // 0-255

void stop(int rtime) {
  digitalWrite(positiveA, LOW);
  digitalWrite(negativeA, LOW);
  ledcWrite(enableA, 0);
  delay(rtime);
}

void go(int spd, int rtime) {
  digitalWrite(positiveA, HIGH);
  digitalWrite(negativeA, LOW);
  ledcWrite(enableA, spd);
  delay(rtime);
}

void setup() {
  Serial.begin(115200);
  pinMode(positiveA, OUTPUT);
  pinMode(negativeA, OUTPUT);
  pinMode(enableA, OUTPUT); // this pin shoudlnt be neccesary but it looks better to have
  pinMode(potPin, INPUT);
  analogReadResolution(resolution);

  // Set up PWM
  ledcAttach(enableA, freq, resolution);
  ledcWrite(enableA, 0);  // Start with battery off
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.println(potValue);
  go(potValue, 1000);
  // stop(1000);
}