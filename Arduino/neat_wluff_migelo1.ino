// C++ code
//
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(2) == LOW){
    digitalWrite(8,HIGH);
    Serial.println("Motor has Started");
  
  }
  else if (digitalRead(3) == LOW){
    digitalWrite(8,LOW);
    Serial.println("Motor has Stopped");
  }
}