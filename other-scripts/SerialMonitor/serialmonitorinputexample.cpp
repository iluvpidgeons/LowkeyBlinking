#include <Arduino.h>

/*
    I didn't write most of this  so I dont really know how it works but like I know most of it
*/

int userAge;
float userHeight;
char userInital;
bool isProgramRunning;
String userName;

void clearBuffer() {
    while(Serial.available() > 0) Serial.read();
}

void printSummary(){
    Serial.println("\n--- Summary ---");
    Serial.print("User: ");
    Serial.print(userName);
    Serial.print(" ");
    Serial.println(userInital);
    Serial.printf("Age: %d years\n", userAge);
    Serial.printf("Height: %.2f meters\n", userHeight);

    if (isProgramRunning) {
        Serial.println("Status: ESP32 logic active.");
    }

    Serial.println("\nRestarting in 10 seconds...");
    delay(10000);
    ESP.restart();
}

void setup() {
    // ESP32 standard baud rate is 115200
    Serial.begin(115200);
    delay(1000); // Give the serial monitor time to connect

    isProgramRunning = true;

    Serial.println("\n--- ESP32 Variable Demo ---");
    Serial.println("Please enter your First name:");
}

void loop() {
    // Step 1: Read String
    if (Serial.available() > 0 && userName == "") {
        userName = Serial.readStringUntil('\n');
        userName.trim();
        Serial.printf("Hello, %s!\n", userName.c_str());
        Serial.println("What is your first initial?");
    }

    // Step 2: Read char
    else if (Serial.available() > 0 && userInital == '\0' && userName != "") {
        userInital = Serial.read();
        clearBuffer();
        Serial.print("Inital stored as: ");
        Serial.println(userInital);
        Serial.println("How old are you?");
    }

    // Step 3: Read Int
    else if (Serial.available() > 0 && userAge == 0 && userInital != '\0') {
        userAge = Serial.parseInt();
        clearBuffer();
        Serial.print("Age stored: ");
        Serial.println(userAge);
        Serial.println("How tall are you in meters? (e.g., 1.82)");
    }

    // Step 4: Read Float
    else if (Serial.available() > 0 && userHeight == 0 && userAge != 0) {
        userHeight = Serial.parseFloat();
        clearBuffer();
        printSummary();
    }
}