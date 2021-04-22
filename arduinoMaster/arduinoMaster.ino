/* 
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino MIDI controller using Arduino Mega 2560 
  
*/

#include <LiquidCrystal.h>

#define NUMOFBUTTONS  8

// Digital Pins usables for interrupts 2, 3, 18, 19, 20, 21

const int button[NUMOFBUTTONS] = {2,3,18,19,20,21,22,23};
const int led[NUMOFBUTTONS] = {6,7,8,9,10,11};

const int rsLeft = 12, enLeft = 11, d4Left = 5, d5Left = 4, d6Left = 24, d7Left = 25;
const int rsRight = 26, enRight = 27, d4Right = 28, d5Right = 29, d6Right = 30, d7Right = 31; // TODO: Check if pins cpuld be used
const int rsCenter = 32, enCenter = 33, d4Center = 34, d5Center = 35, d6Center = 36, d7Center = 37; // TODO: Check if pins cpuld be used

short int preset = 0;
short int bank = 0;

bool prevBankButtonStateUp = false;
bool prevBankButtonStateDown = false;

short int prevPreset = 0;

LiquidCrystal lcdLeft(rsLeft, enLeft, d4Left, d5Left, d6Left, d7Left);
LiquidCrystal lcdRight(rsRight, enRight, d4Right, d5Right, d6Right, d7Right);
LiquidCrystal lcdCenter(rsCenter, enCenter, d4Center, d5Center, d6Center, d7Center);

char* presetsTopLeftLookUpTable[]
{
  "Preset_Name_1",
  "Preset Name 2",
  "Preset Name 3",
  "Preset Name 4",
  "Preset Name 5",
  "Preset Name 6"
};

char* presetsBottomLeftLookUpTable[]
{
  "Preset_Name_1",
  "Preset Name 2",
  "Preset Name 3",
  "Preset Name 4",
  "Preset Name 5",
  "Preset Name 6"
};

char* presetsTopCenterLookUpTable[]
{
  "Preset_Name_1",
  "Preset Name 2",
  "Preset Name 3",
  "Preset Name 4",
  "Preset Name 5",
  "Preset Name 6"
};

char* presetsBottomCenterLookUpTable[]
{
  "Preset_Name_1",
  "Preset Name 2",
  "Preset Name 3",
  "Preset Name 4",
  "Preset Name 5",
  "Preset Name 6"
};

char* presetsBottomRightLookUpTable[]
{
  "Preset_Name_1",
  "Preset Name 2",
  "Preset Name 3",
  "Preset Name 4",
  "Preset Name 5",
  "Preset Name 6"
};

char* presetsTopRightLookUpTable[]
{
  "Preset_Name_1",
  "Preset Name 2",
  "Preset Name 3",
  "Preset Name 4",
  "Preset Name 5",
  "Preset Name 6"
};


void setup() 
{
  Serial.begin(9600);
  initPins();
  initISR();
  lcdLeft.begin(16, 2);
  lcdRight.begin(16, 2);
  lcdCenter.begin(16, 2);
}

void loop() 
{

checkBank();

if( preset != prevPreset)
{
 printPresetOfBank(); 
}
delay(10);
}
