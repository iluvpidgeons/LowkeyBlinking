#pragma once // not completely sure what this means

/* 
  not using this yet cuz I don't feel like editing all the scripts but it should work
  the following scripts are NOT consistent with this list
    rgblightknob3.cpp
    rotaryencoder.cpp
    mediacontrol.cpp
*/

// output pins
#define ledPin1 16
#define ledPin2 17
#define ledPin3 18
#define ledPinRed 16
#define ledPinGreen 17
#define ledPinBlue 18
#define buzzerPin 19

// input pins
#define buttonPin 32 // I would use 34 which is an input only pin but it doesn't work with INPUT_PULLUP
#define potPin 36
#define micPin 39

// motor driver
#define motor1A 13
#define motor2A 14
#define enableA 27

// shift register
#define latchPin 22
#define clockPin 23
#define dataPin 21