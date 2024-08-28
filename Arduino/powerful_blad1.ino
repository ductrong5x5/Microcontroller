#include <Servo.h>

// C++ code
//
int sp1=4;
int sp2=5;
int sp3=6;
int sp4=7;
Servo ctrlServo;
int Button =0;
int delayTime =0;
bool Mode =0;
int Inter=2;


void getButton() {
  delay(50); // Simple debounce
  if (digitalRead(sp1) == 0) 
    Button = 1;
   else if (digitalRead(sp2) == 0) 
    Button = 2;
  else if (digitalRead(sp3) == 0) 
    Button = 3;
   else if (digitalRead(sp4) == 0) 
    Button = 4;
  
    
  delayTime = speedOption();
  Serial.println(Button);
}

           
           
int speedOption()
{
  switch(Button){
    case 1:
  		Mode=1;
  		return 100;
    case 2:
  		Mode=1;
  		return 50;
    case 3:
  		Mode=1;
  		return 25;
    case 4:
  		Mode=1;
    	return 5;
     
    default:
  		
  		return 0;
  }

}    
void setup()
{
  Serial.begin(9600);
  ctrlServo.attach(3);
  pinMode(Inter,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Inter),getButton, CHANGE);
}

void loop()
{ 
  if (Mode ==1){
    for(int pos=0; pos<=180;pos++){
      ctrlServo.write(pos);
      delay(delayTime);
    }
    for(int pos=180; pos>=0;pos--){
      ctrlServo.write(pos);
      delay(delayTime);
    }
  }
}