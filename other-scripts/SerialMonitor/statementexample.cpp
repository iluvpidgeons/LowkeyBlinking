#include <Arduino.h>

int a, b, c, x; // Declare variables

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\n\n\n******* Control Structures in C++ *******");

  //_______If Statement_______
  Serial.println("________ If Statement ________");
  a = 33;
  b = 200;
  if (b > a) {
    Serial.println("b is greater than a");
  }

  //_______Else If Statement_______
  Serial.println("\n________ Else If Statement ________");
  a = 33;
  b = 33;
  if (b > a) {
    Serial.println("b is greater than a");
  } else if (a == b) {
    Serial.println("a and b are equal");
  }
  
  //_______Else Statement_______
  Serial.println("\n________ Else Statement ________");
  a = 200;
  b = 33;
  if (b > a) {
    Serial.println("b is greater than a");
  } else if (a == b) {
    Serial.println("a and b are equal");
  } else {
    Serial.println("a is greater than b");
  }

  //_______And Statement
  Serial.println("\n________ And Statement ________");
  a = 200;
  b = 33;
  c = 500;
  if (a > b && c > a) {
    Serial.println("Both conditions are True");
  }

  //_______Or Statement_______
  Serial.println("\n________ Or Statement ________");
  a = 2;
  b = 33;
  c = 500;
  if (a > b || a > c) {
    Serial.println("At least one condition is True");
  }

  // _______Not Statement_______
  Serial.println("\n________ Not Statement ________");
  a = 33;
  b = 200;
  if (!(a > b)) {
    Serial.println("a is NOT greater than b");
  }

  // _______Nested If Statement_______
  Serial.println("\n________ Nested If Statement ________");
  x = 41;
  if (x > 10) {
    Serial.println("Above ten");
    if (x > 20) {
    Serial.println("and also above 20!");
    } else {
    Serial.println("but not above 20.");
    }
  } else {
    Serial.println("Not above 10");
  }
}

void loop() {
  // acivate epstien mode
}