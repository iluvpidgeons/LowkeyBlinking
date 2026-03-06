#include <Arduino.h>

const int motor1A = GPIO_NUM_13;
const int motor2A = GPIO_NUM_14;
const int enableA = GPIO_NUM_27;

// PWM settings
const int freq = 20000; // PWM frequency: 20 kHz (Adjust 2-20 kHz as needed)
const int resolution = 8; // PWM resolution: 8 bits (dutyCycle: 0-255)

void stop(int rtime) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, LOW);
  ledcWrite(enableA, 0);
  delay(rtime);
}

void forward(int spd, int rtime) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor2A, LOW);
  ledcWrite(enableA, spd);
  delay(rtime);
}

void reverse(int spd, int rtime) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, HIGH);
  ledcWrite(enableA, spd);
  delay(rtime);
}

void setup() {
  Serial.begin(115200);
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);

  // Set up PWM
  ledcAttach(enableA, freq, resolution);
  ledcWrite(enableA, 0);  // Start with motor stopped
}

void loop() {
  forward(255, 2000); // Move forward at speed 255 for 2 seconds
  stop(1000);         // Stop for 1 second
}