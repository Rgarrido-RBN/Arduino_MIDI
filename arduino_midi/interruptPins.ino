
/* 
  created 26 Feb 2021
  by Rubén Garrido
*/
void initISR(){
attachInterrupt(digitalPinToInterrupt(button[0]), ISRPin2, FALLING);
attachInterrupt(digitalPinToInterrupt(button[1]), ISRPin3, RISING);
attachInterrupt(digitalPinToInterrupt(button[2]), ISRPin18, RISING);
attachInterrupt(digitalPinToInterrupt(button[3]), ISRPin19, RISING);
attachInterrupt(digitalPinToInterrupt(button[4]), ISRPin20, RISING);
attachInterrupt(digitalPinToInterrupt(button[5]), ISRPin21, RISING);
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
}
  
void ISRPin3(){
  sendPreset(2);
  }
  
void ISRPin18(){
  sendPreset(3);
  }
  
void ISRPin19(){
  sendPreset(4);
  }
  
void ISRPin20(){
  sendPreset(5);
  }
  
void ISRPin21(){
  sendPreset(6);
  }

void sendPreset(int preset){
  int prevPreset = 0;
  if(prevPreset != preset)
  {
    prevPreset = preset;
    Serial.print(preset);
  }
}
  