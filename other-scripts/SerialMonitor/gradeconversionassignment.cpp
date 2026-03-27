#include <Arduino.h>

void clearBuffer() {
    while(Serial.available() > 0) Serial.read();
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    clearBuffer();
    Serial.println("Enter your grade (0-100): ");
}

void loop() {
    if (Serial.available() > 0) {
        String letterGrade;
        int grade = Serial.parseInt();
        clearBuffer();
        if (grade >= 90) {
            letterGrade = "A";
        } else if (grade >= 80) {
            letterGrade = "B";
        } else if (grade >= 70) {
            letterGrade = "C";
        } else if (grade >= 60) {
            letterGrade = "D";
        } else {
            letterGrade = "F";
        }
        Serial.print("Your grade is: ");
        Serial.println(letterGrade);
    }
}