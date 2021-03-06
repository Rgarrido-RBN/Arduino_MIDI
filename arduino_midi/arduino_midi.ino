
/* 
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino midi controller with Arduino Mega 2560 
  
*/

#include <MIDI.h>
#include <LiquidCrystal.h>

#define NUMOFBUTTONS  6

MIDI_CREATE_DEFAULT_INSTANCE();
// Digital Pins usables for interrupts 2, 3, 18, 19, 20, 21

const int button[NUMOFBUTTONS] = {2,3,18,19,20,21};
const int led[NUMOFBUTTONS] = {6,7,8,9,10,11};

void setup() {
  
  Serial.begin(31250);
  initPins();
  initISR();

}

void loop() {
  
}
