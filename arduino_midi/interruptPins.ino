
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
}

void initPins() 
{
    //Init pins of Arduino
  for(int i=0; i < NUMOFBUTTONS; i++)
  {
    pinMode(button[i], INPUT_PULLUP);
    pinMode(led[i], OUTPUT);
  }
}

void ISRPin2()
{
  preset = sendPreset(0);
}
  
void ISRPin3()
{
  preset = sendPreset(1);
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

unsigned int sendPreset(int actPreset){
  
  if(prevPreset != actPreset)
  {
    prevPreset = actPreset;
    Serial.print(actPreset);
    digitalWrite(led[actPreset], HIGH);
  }
}
  