#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int lcdColums = 16;
int lcdRows = 2;

byte heart[] = {
  B00000,
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,
  B00000
};

LiquidCrystal_I2C lcd(0x27, lcdColums, lcdRows); // Set the LCD I2C address and dimensions

void setup ()
{
    lcd.init();                      // Initialize the LCD
    lcd.backlight();                 // Turn on the LCD backlight.
    lcd.createChar(0, heart);
}

void loop () {
    lcd.setCursor(0, 0);             // Set cursor to the first colum, first row
    lcd.write(byte(0));
    delay(1000);
    lcd.clear(); // clears the display to print new message
    lcd.setCursor(0, 1);             // Set the cursor to first colum, second row
    lcd.write(byte(0));
    delay(1000);
    lcd.clear();
}