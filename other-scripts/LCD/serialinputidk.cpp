#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
    not finished yet
*/

int lcdColums = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColums, lcdRows); // Set the LCD I2C address and dimensions

void clearBuffer() {
    while(Serial.available() > 0) Serial.read();
}

void setup() {
    lcd.init();                      // Initialize the LCD
    lcd.backlight();                 // Turn on the LCD backlight.
    Serial.begin(115200);
    delay(1000);
    Serial.println("Type what u want displayed on the LCD: ");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("check serial monitor");
    clearBuffer();
}

void loop() {
    if (Serial.available() > 0) {
        String input;
        input = Serial.readString(); // Serial.parseInt() doesn't work because it reads ints, not Strings
        clearBuffer();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(input);
    }
}