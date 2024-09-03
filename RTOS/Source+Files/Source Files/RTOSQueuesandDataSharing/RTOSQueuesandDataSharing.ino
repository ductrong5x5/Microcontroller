#include <Arduino_FreeRTOS.h>
#include <queue.h>

#define rtDelay(v) {vTaskDelay(v/15);}

QueueHandle_t xQueue;


void setup()
{
  Serial.begin(9600);
  xQueue= xQueueCreate(5, sizeof(int));
  xTaskCreate(txTask, "Sender", 120, NULL,1,NULL);
  
}

void loop()
{}

void txTask(void*)
{

int data=123;
while(1)
{
xQueueSend( xQueue, &data, portMAX_DELAY);
Serial.print("Data sent=  ");
Serial.println(data);
rtDelay(1000);
 
}

}
 

 
 
