/*
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino MIDI controller using Arduino Mega 2560

*/

void toogleLED(int preset) {

  if (prevPreset != preset) {
    prevPreset = preset;
    digitalWrite(led[preset], HIGH);
  }
}
