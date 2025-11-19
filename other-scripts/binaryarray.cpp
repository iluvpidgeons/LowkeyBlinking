#include <Arduino.h>

const int STcp = GPIO_NUM_22;//ST_CP
const int SHcp = GPIO_NUM_23;//SH_CP
const int DS = GPIO_NUM_21;  //DS

int datArray[] = {B00000000
  , B00000001
  , B00000011
  , B00000111
  , B00001111
  , B00011111
  , B00111111
  , B01111111};

void setup()
{
  //set pins to output
  pinMode(STcp, OUTPUT);
  pinMode(SHcp, OUTPUT);
  pinMode(DS, OUTPUT);
}

void loop ()
{
  for(int num = 0; num <8; num++)
  {
    digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
    shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
    digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
    delay(1000);
  }
}