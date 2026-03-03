#include <Arduino.h>

int RED_PIN = GPIO_NUM_16;
int GREEN_PIN = GPIO_NUM_17;
int BLUE_PIN = GPIO_NUM_18;

void red(int duration) {
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);
  delay(duration);
}

void green(int duration) {
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 255);
  delay(duration);
}

void blue(int duration) {
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0);
  delay(duration);
}

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  red(500);
  green(500);
  blue(500);
}
