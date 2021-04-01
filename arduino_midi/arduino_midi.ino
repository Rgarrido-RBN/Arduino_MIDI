/* 
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino MIDI controller using Arduino Mega 2560 
  
*/
#include "MIDI.h"
#include <LiquidCrystal.h>

#define NUMOFBUTTONS  8

// Digital Pins usables for interrupts 2, 3, 18, 19, 20, 21

const int button[NUMOFBUTTONS] = {2,3,18,19,20,21,22,23};
const int led[NUMOFBUTTONS] = {6,7,8,9,10,11};
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 24, d7 = 25;
short int preset = 0;
short int bank = 0;

short int prevPreset = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned char presetsOfBank0LookUpTable[]
{
  'Preset Name 1',
  'Preset Name 2',
  'Preset Name 3',
  'Preset Name 4',
  'Preset Name 5',
  'Preset Name 6'
};

unsigned char presetsOfBank1LookUpTable[]
{
  'Preset Name 1',
  'Preset Name 2',
  'Preset Name 3',
  'Preset Name 4',
  'Preset Name 5',
  'Preset Name 6'
};

unsigned char presetsOfBank2LookUpTable[]
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

checkBank();

if( preset != prevPreset)
{
 printPresetOfBank(); 
}

}
