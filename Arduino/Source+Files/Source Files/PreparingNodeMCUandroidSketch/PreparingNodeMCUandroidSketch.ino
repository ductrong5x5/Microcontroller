#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

char auth[]="auth";
const char *ssid = "yourssid";
const char *pass = "yourpswrd";
 
void setup() {

Serial.begin(9600);
delay(10);
digitalWrite(LED_BUILTIN, HIGH);
Serial.println("Connecting to....");
Serial.println(ssid);

WiFi.begin(ssid, pass);

while(WiFi.status() !=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.println("WiFi Connected");
Blynk.begin(auth,ssid,pass);

}

void loop() {
 
Blynk.run();

}
