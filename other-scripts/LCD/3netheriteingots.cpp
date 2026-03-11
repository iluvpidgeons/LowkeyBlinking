#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int lcdColums = 16;
int lcdRows = 2;

byte ingot[] = {
  B00000,
  B00011,
  B01100,
  B10000,
  B10011,
  B01100,
  B00000,
  B00000
};

byte ingot2[] = {
  B00000,
  B00000,
  B10000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000
};

LiquidCrystal_I2C lcd(0x27, lcdColums, lcdRows); // Set the LCD I2C address and dimensions

void setup ()
{
    lcd.init();                      // Initialize the LCD
    lcd.backlight();                 // Turn on the LCD backlight.
    lcd.createChar(0, ingot);
    lcd.createChar(1, ingot2);
}

void loop () {
    lcd.setCursor(0, 0);
    lcd.print("THREE");
    delay(750);
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("NETHERITE");
    delay(750);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("INGOTS");
    delay(750);

    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.setCursor(1, 1);
    lcd.write(byte(1));
    delay(500);

    lcd.setCursor(2, 1);
    lcd.write(byte(0));
    lcd.setCursor(3, 1);
    lcd.write(byte(1));
    delay(500);

    lcd.setCursor(4, 1);
    lcd.write(byte(0));
    lcd.setCursor(5, 1);
    lcd.write(byte(1));

    delay(1000);
    lcd.clear();
}