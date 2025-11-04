#include <Arduino.h>

// lowkey makes this light flash

void setup() {
  // put your setup code here, to run once:
 pinMode(GPIO_NUM_16, OUTPUT);
 pinMode(GPIO_NUM_17, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GPIO_NUM_16, LOW);
  digitalWrite(GPIO_NUM_17, HIGH);
  delay(100);
  digitalWrite(GPIO_NUM_16, HIGH);
  digitalWrite(GPIO_NUM_17, LOW);
  delay(100);
}
