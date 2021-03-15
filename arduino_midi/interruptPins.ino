
/* 
  created 26 Feb 2021
  by Rubén Garrido
*/
void initISR(){
 attachInterrupt(digitalPinToInterrupt(button[0]), ISRPin2, FALLING);
 //attachInterrupt(digitalPinToInterrupt(button[1]), ISRPin3, RISING);
 //attachInterrupt(digitalPinToInterrupt(button[2]), ISRPin18, RISING);
 //attachInterrupt(digitalPinToInterrupt(button[3]), ISRPin19, RISING);
 //attachInterrupt(digitalPinToInterrupt(button[4]), ISRPin20, RISING);
 //attachInterrupt(digitalPinToInterrupt(button[5]), ISRPin21, RISING);
}

void initPins() {
    //Init pins of Arduino
  for(int i=0; i < NUMOFBUTTONS; i++){
  pinMode(button[i], INPUT_PULLUP);
  pinMode(led[i], OUTPUT);
    }
  }
  
void ISRPin2(){
  sendNote(20);
  delay(5);
}
  
void ISRPin3(){
  sendNote(48);
  }
  
void ISRPin18(){
  sendNote(49);
  }
  
void ISRPin19(){
  sendNote(50);
  }
  
void ISRPin20(){
  sendNote(51);
  }
  
void ISRPin21(){
  sendNote(52);
  }

void sendNote(unsigned int note){
  MIDI.sendNoteOn(note, 127, 1);                
  MIDI.sendNoteOff(note, 0, 1);
  //Debugging
  Serial.print("DEBUG\n");
 
}
