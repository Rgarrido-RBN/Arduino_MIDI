/* 
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino MIDI controller using Arduino Mega 2560 
  
*/

void checkBank()
{
  
bool bankButtonStateUp = digitalRead(button[6]);
bool bankButtonStateDown = digitalRead(button[7]); 

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
  switch(preset)
  {
    case 0 :
      printPreset(presetsTopLeftLookUpTable[bank]);
    break;
    case 1 :
      printPreset(presetsBottomLeftLookUpTable[bank]);
    break;
    case 2 :
      printPreset(presetsTopRightLookUpTable[bank]);
    break;
    case 3 :
      printPreset(presetsBottomRightLookUpTable[bank]);
    break;
    case 4 :
      printPreset(presetsTopCenterLookUpTable[bank]);
    break;
    case 5 :
      printPreset(presetsBottomCenterLookUpTable[bank]);
    break;
  
  
  
  }
}


void printPreset(char* presetName)
{
//lcd.print(presetName);
}


