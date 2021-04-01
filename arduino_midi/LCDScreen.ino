/* 
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino MIDI controller using Arduino Mega 2560 
  
*/

void checkBank()
{
bool bankButtonStateUp = digitalRead(button[7]);
bool bankButtonStateDown = digitalRead(button[7]); 
bool prevBankButtonStateUp;
bool prevBankButtonStateDown;
  if( bankButtonStateUp == HIGH && bankButtonStateUp != prevBankButtonStateUp ) 
  {
    bank++;
  }
  else if ( bankButtonStateUp == HIGH && bankButtonStateUp != prevBankButtonStateUp )
  {
    bank--;
  }
prevBankButtonStateUp = bankButtonStateUp;
prevBankButtonStateDown = bankButtonStateDown;    
}

void printPresetOfBank()
{
  switch(bank)
  {
    case 0 :
      printPreset(presetsOfBank0LookUpTable[preset]);
    break;
    case 1 :
      printPreset(presetsOfBank1LookUpTable[preset]);
    break;
    case 2 :
      printPreset(presetsOfBank2LookUpTable[preset]);
    break;
  }
}


void printPreset(unsigned char presetName)
{
lcd.print(presetName);
}


