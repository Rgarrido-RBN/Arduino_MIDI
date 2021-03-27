
/* 
  created 26 Feb 2021
  by Rubén Garrido
*/
void initISR(){
attachInterrupt(digitalPinToInterrupt(button[0]), ISRPin2, FALLING);
attachInterrupt(digitalPinToInterrupt(button[1]), ISRPin3, FALLING);
attachInterrupt(digitalPinToInterrupt(button[2]), ISRPin18, FALLING);
attachInterrupt(digitalPinToInterrupt(button[3]), ISRPin19, FALLING);
attachInterrupt(digitalPinToInterrupt(button[4]), ISRPin20, FALLING);
attachInterrupt(digitalPinToInterrupt(button[5]), ISRPin21, FALLING);
}

void initPins() {
    //Init pins of Arduino
  for(int i=0; i < NUMOFBUTTONS; i++){
  pinMode(button[i], INPUT_PULLUP);
  pinMode(led[i], OUTPUT);
    }
  }

void ISRPin2(){
  sendPreset(1);
  toogleLED(1);
}
  
void ISRPin3(){
  sendPreset(2);
  toogleLED(2);
  }
  
void ISRPin18(){
  sendPreset(3);
  toogleLED(3);
  }
  
void ISRPin19(){
  sendPreset(4);
  toogleLED(4);
  }
  
void ISRPin20(){
  sendPreset(5);
  toogleLED(5);
  }
  
void ISRPin21(){
  sendPreset(6);
  toogleLED(6);
  }

void sendPreset(int preset){
  
  if(prevPreset != preset)
  {
    prevPreset = preset;
    Serial.print(preset);
  }
}
  