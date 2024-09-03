#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include "semphr.h"

#define rtDelay(v) {vTaskDelay(v/15);}

QueueHandle_t xQueue;
SemaphoreHandle_t xBinarySemaphore;

typedef struct sensorInit
{
  char* sensorName;
  char* sensorType;
  int   sensorData;
  float sensorScaleUnit;
};

void setup()
{
  Serial.begin(9600);
  xQueue= xQueueCreate(10, sizeof(sensorInit));
  xBinarySemaphore= xSemaphoreCreateBinary();
  xTaskCreate(txTask, "Sender", 120, NULL,1,NULL);
  xTaskCreate(rxTask, "Receiver", 120, NULL,1,NULL);
  xSemaphoreGive(xBinarySemaphore);
  
}

void loop()
{}

void txTask(void*)
{


while(1)
{

sensorInit Ultrasonic;
Ultrasonic.sensorName="Ultrasonic";
Ultrasonic.sensorType="Analog";

Ultrasonic.sensorScaleUnit=4.2;
for (int i=0; i<255;i++)
{
Ultrasonic.sensorData=i;
xQueueSend( xQueue, &Ultrasonic, portMAX_DELAY);
int msgsWaitingCount= uxQueueMessagesWaiting(xQueue);
int availableQueueSize= uxQueueSpacesAvailable(xQueue);

xSemaphoreTake(xBinarySemaphore,portMAX_DELAY);
Serial.print("Messages Waiting: ");
Serial.print(msgsWaitingCount);
Serial.print(" ");
Serial.print("Available Space: ");
Serial.println(availableQueueSize);
xSemaphoreGive(xBinarySemaphore);
}

 
 
}

}

void rxTask (void*)
{sensorInit Ultrasonic;

  while(1)
  {
    xQueueReceive(xQueue, &Ultrasonic, portMAX_DELAY);

    
    xSemaphoreTake(xBinarySemaphore,portMAX_DELAY);
    Serial.print("Data Received=  ");
    Serial.print(Ultrasonic.sensorName);
    Serial.print(" ");
    Serial.print(Ultrasonic.sensorType);
    Serial.print(" ");
    Serial.print(Ultrasonic.sensorData);
    Serial.print(" ");
    Serial.print(Ultrasonic.sensorScaleUnit);
    Serial.println("");
    Serial.println("");
    xSemaphoreGive(xBinarySemaphore);
  
    
  }
}
 

 
 
