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

void printPresetOfBank(int mode)
{
  if(mode == 1)
  {
  lcdLeft.setCursor(0, 0);
  lcdLeft.print(presetsTopLeftLookUpTable[bank]);

  lcdLeft.setCursor(1, 0);
  lcdLeft.print(presetsBottomLeftLookUpTable[bank]);

  lcdRight.setCursor(0, 0);
  lcdRight.print(presetsTopRightLookUpTable[bank]);

  lcdRight.setCursor(1, 0);
  lcdRight.print(presetsBottomRightLookUpTable[bank]);

  lcdCenter.setCursor(0, 0);
  lcdCenter.print(presetsTopCenterLookUpTable[bank]);

  lcdCenter.setCursor(1, 0);
  lcdCenter.print(presetsBottomCenterLookUpTable[bank]);
  }
  
  #ifdef PEDAL_MODE_ENABLED 
  else 
  {
    //TODO: Implementation of pedal selection mode
  }
  #endif
}


