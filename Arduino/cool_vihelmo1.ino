// C++ code
//
void setup()
{
  pinMode (A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
 	float voltage = analogRead(A0) *5/1024.0;
  	float cel = (voltage - 0.49699) *100;
  	Serial.println(cel);
}