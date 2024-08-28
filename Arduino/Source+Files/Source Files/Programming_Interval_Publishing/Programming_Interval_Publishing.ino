#include<ESP8266WiFi.h>
#include<PubSubClient.h>
unsigned long lastPub=0;
int pubTime=3000;
void callback(char *topic, byte *payload, unsigned int len)
{
  Serial.print("MQTT Message was received[");
  Serial.print(topic);
  Serial.println("]");
  Serial.println(payload[0]);
  
  if(payload[0]==49)
  digitalWrite(LED_BUILTIN, HIGH);
  else if(payload[0]==50)
  digitalWrite(LED_BUILTIN, LOW);
}

const char *mqtt_server="broker.hivemq.com";
const char *ssid = "yourssid";
const char *pass = "yourpswd";
WiFiClient NodeMcuClient;
PubSubClient client(mqtt_server, 1883, callback, NodeMcuClient);


void setup() {
Serial.begin(9600); 
pinMode(2,OUTPUT);
Serial.println("Connecting to....");
Serial.println(ssid);
WiFi.begin(ssid, pass);
 
while(WiFi.status() !=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.println("WiFi Connected");
int Status=client.connect("6d5d630c85054781b7484a67b76cfd62.s1.eu.hivemq.cloud");
if(Status==1)
{
  Serial.println("MQTT Connected");
  client.subscribe("INTERNAL_LED");
}
 
}

void loop() {

if(!client.connected())
{
int Status=client.connect("6d5d630c85054781b7484a67b76cfd62.s1.eu.hivemq.cloud");
if(Status==1)
{
  Serial.println("MQTT Connected");
  client.subscribe("INTERNAL_LED");
}  
} 
client.loop();
unsigned long now = millis();
if(now-lastPub>=pubTime)
{
bool ledStatus= digitalRead(2);
lastPub= now;
int Pot= analogRead(A0);
 
client.publish("PotValue", String(Pot).c_str());
client.publish("ledStatus", String(ledStatus).c_str());
 
}
}
