/* 
  Created 26 Feb 2021
  by Rubén Garrido

  Arduino MIDI controller using Arduino Mega 2560 
  
*/

int checkBank()
{

  bool bankButtonStateUp = digitalRead(button[6]);
  bool bankButtonStateDown = digitalRead(button[7]);

  if (bankButtonStateUp == HIGH && bankButtonStateUp != prevBankButtonStateUp) 
  {
    bank++;
    timeMeasured = millis();
    return screenMode;
  } 
  else if (millis() - timeMeasured > 1500 && bankButtonStateUp == HIGH) 
  {
    if (screenMode == PRESET_MODE) 
    {
      bank = 0;
      return PEDAL_MODE;
      Serial.write("Pedal mode enable \n"); //DEBUG
    } 
    else if (screenMode == PEDAL_MODE) 
    {
      return PRESET_MODE;
      Serial.write("Preset mode enable \n"); //DEBUG
    }
  } 
  else if (bankButtonStateUp == HIGH && bankButtonStateUp != prevBankButtonStateUp) 
  {
    bank--;
    return screenMode;
  }
  prevBankButtonStateUp = bankButtonStateUp;
  prevBankButtonStateDown = bankButtonStateDown;
}

void printPresetOfBank(int mode)
{
  if(mode == PRESET_MODE)
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
    lcdLeft.setCursor(0, 0);
    lcdLeft.print(pedalsLookUpTable[0]);

    lcdLeft.setCursor(1, 0);
    lcdLeft.print(pedalsLookUpTable[1]);

    lcdRight.setCursor(0, 0);
    lcdRight.print(pedalsLookUpTable[2]);

    lcdRight.setCursor(1, 0);
    lcdRight.print(pedalsLookUpTable[3]);

    lcdCenter.setCursor(0, 0);
    lcdCenter.print(pedalsLookUpTable[4]);

    lcdCenter.setCursor(1, 0);
    lcdCenter.print(pedalsLookUpTable[5]);
  }
  #endif
}


