/* 
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino MIDI controller using Arduino Mega 2560 
  
*/
#include "MIDI.h"
#include <LiquidCrystal.h>

#define NUMOFBUTTONS  6

// Digital Pins usables for interrupts 2, 3, 18, 19, 20, 21

const int button[NUMOFBUTTONS] = {2,3,18,19,20,21};
const int led[NUMOFBUTTONS] = {6,7,8,9,10,11};
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
unsigned int preset = 0;
unsigned int prevPreset = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned char presetLookUpTable[]
{
  'Preset Name 1',
  'Preset Name 2',
  'Preset Name 3',
  'Preset Name 4',
  'Preset Name 5',
  'Preset Name 6'
};

void setup() 
{
  Serial.begin(9600);
  initPins();
  initISR();
  lcd.begin(16, 2);
}

void loop() 
{

if( preset != prevPreset)
{
  printPreset(presetLookUpTable[preset]);
}

}
