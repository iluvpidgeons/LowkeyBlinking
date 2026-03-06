#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
    Not finished yet
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
    clearBuffer();
}

void loop() {
    lcd.clear();
    lcd.setCursor(0, 0);             // Set cursor to the first colum, first row
    lcd.print("check serial monitor");
    if (Serial.available() > 0) {
        String input;
        input = Serial.readString(); // Serial.parseInt() doesnt work because it reads strings
        clearBuffer();
        lcd.clear();
        lcd.setCursor(0, 0);             // Set cursor to the first colum, first row
        lcd.print(input);
    }
}