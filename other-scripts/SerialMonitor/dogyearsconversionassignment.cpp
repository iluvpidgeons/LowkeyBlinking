#include <Arduino.h>

/*
    This is basically just serialmonitorinput.cpp but simpiler and converts dog years to human years with serial monitor
*/

int dogAge;
float dogRealAge;

void clearBuffer() {
    while(Serial.available() > 0) Serial.read();
}

void printSummary(){
    Serial.println("--- Summary ---");
    // these dont work lowkey ion know why prolly because of the float
    // Serial.printf("Dog Age: %d years\n", dogAge);
    // Serial.printf("Dog Age in Human Years: %d years\n", dogRealAge);

    Serial.print("Dog Age: ");
    Serial.println(dogAge);
    Serial.print("Dog Age in Human Years: ");
    Serial.println(dogRealAge);

    Serial.print("Restarting in 5 seconds...");
    delay(5000);
    ESP.restart();
}

void setup() {
    Serial.begin(115200);
    delay(1000); // Give the serial monitor time to connect
    Serial.println("Enter Dog age in human years:");
    clearBuffer();
}

void loop() {
    if (Serial.available() > 0) {
        dogAge = Serial.parseInt();
        clearBuffer();
        // dogRealAge = dogAge * 7;
        if (dogAge >= 2) {
            dogRealAge = 21 + (dogAge - 2) * 4;
        }
        if (dogAge == 1) {
            dogRealAge = 10.5;
        }
    printSummary();   
    }
}