/* 
  created 26 Feb 2021
  by Rubén Garrido
*/

void initISR()
{
attachInterrupt(digitalPinToInterrupt(button[0]), ISRPin2, FALLING);
attachInterrupt(digitalPinToInterrupt(button[1]), ISRPin3, FALLING);
attachInterrupt(digitalPinToInterrupt(button[2]), ISRPin18, FALLING);
attachInterrupt(digitalPinToInterrupt(button[3]), ISRPin19, FALLING);
attachInterrupt(digitalPinToInterrupt(button[4]), ISRPin20, FALLING);
attachInterrupt(digitalPinToInterrupt(button[5]), ISRPin21, FALLING);

Serial.write("Interrupt pins init completed \n");
}

void initPins() 
{
    //In don't know why but pin 2 must be inilialized as a normal input
    //pinMode(button[0], INPUT_PULLUP);
    //Init input pins of Arduino
  for(int i=1; i < NUMOFBUTTONS; i++)
  {
    pinMode(button[i], INPUT_PULLUP);
  }
    //Init output pins of Arduino
   for(int j=0; j < NUM_OF_LEDS; j++)
  {
    pinMode(led[j], OUTPUT);
  }

Serial.write("Pins initialization completed\n");
}

void ISRPin2()
{
  preset = sendPreset(0);
  Serial.print("Actual preset is 0 and I don't know why \n ");
}
  
void ISRPin3()
{
  preset = sendPreset(1);
  Serial.print("Actual preset is 1 and I don't know why \n ");
}
  
void ISRPin18()
{
  preset = sendPreset(2);
}
  
void ISRPin19()
{
  preset = sendPreset(3);
}
  
void ISRPin20()
{
  preset = sendPreset(4);
}
  
void ISRPin21()
{
  preset = sendPreset(5);
}

short int sendPreset(short int actPreset){
  
  if(prevPreset != actPreset)
  {
    prevPreset = actPreset;
    
    Serial.print("Actual preset is: "); Serial.print(actPreset); Serial.print("\n");//DEBUG
    Serial.print("Actual bank is: "); Serial.print(bank); Serial.print("\n"); //DEBUG
    
    for(int i; i <= NUM_OF_LEDS; i++)
    {
      if(i == actPreset && actPreset != prevPreset)
      {
        digitalWrite(led[i], HIGH);  
      }
      else
      {
        digitalWrite(led[i], LOW);
      }
      
    }
    
  }
  return actPreset;
}



  