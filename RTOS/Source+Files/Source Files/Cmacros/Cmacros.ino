#include <Arduino_FreeRTOS.h>
#define rtDelay(v) {vTaskDelay(v/portTICK_PERIOD_MS)
const int blinkLed=13;
#define rtDelay(v) {vTaskDelay(v/15);} // delay in mS
void setup()
{

xTaskCreate 
(
taskLedBlink,
"blink",
128,
NULL,
2,
NULL
);

xTaskCreate
(
taskSerial,
"serial",
128,
NULL,
1,
NULL
);

Serial.begin(9600);
}

void loop()
{}

void taskLedBlink(void*)
{
  digitalWrite(blinkLed,HIGH);
  rtDelay(500);
  digitalWrite(blinkLed,LOW);
  rtDelay(500);
  
}

void taskSerial(void*)
{
Serial.println("Blinking is happening as a multi thread");
rtDelay(500);

}
