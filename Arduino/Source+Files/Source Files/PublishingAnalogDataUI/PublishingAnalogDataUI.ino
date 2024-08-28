#include<ESP8266WiFi.h>
#include<PubSubClient.h>

void callback(char *topic,byte *payload,unsigned int length1){    
Serial.print("message arrived[");
Serial.print(topic);
Serial.println("]");
Serial.println(payload[0]);   
if(payload[0]==49) digitalWrite(LED_BUILTIN,HIGH);    //ASCII VALUE OF '1' IS 49
else if(payload[0]==50)digitalWrite(LED_BUILTIN,LOW);//ASCII VALUE OF '2' IS 50

}

const char *mqtt_server="broker.hivemq.com";
const char *ssid = "yourssid";
const char *pass = "yourpswd";
WiFiClient NodeMcuClient;
PubSubClient client(mqtt_server, 1883, callback, NodeMcuClient);


void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); 
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
if(Status)
{Serial.println("MQTT Connected");
client.subscribe("INTERNAL_LED");
}
}

void loop() {
if(!client.connected()){

client.connect("6d5d630c85054781b7484a67b76cfd62.s1.eu.hivemq.cloud");
Serial.println("MQTT Connected");
client.subscribe("INTERNAL_LED");
delay(1000);
}



 client.loop();
 

}
