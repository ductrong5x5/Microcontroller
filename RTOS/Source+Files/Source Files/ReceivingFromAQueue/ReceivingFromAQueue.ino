#include <Arduino_FreeRTOS.h>
#include <queue.h>

#define rtDelay(v) {vTaskDelay(v/15);}

QueueHandle_t xQueue;

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
  xTaskCreate(txTask, "Sender", 120, NULL,1,NULL);
  xTaskCreate(rxTask, "Receiver", 120, NULL,1,NULL);
  
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
Ultrasonic.sensorData=55;
Ultrasonic.sensorScaleUnit=4.2;

xQueueSend( xQueue, &Ultrasonic, portMAX_DELAY);
int msgsWaitingCount= uxQueueMessagesWaiting(xQueue);
int availableQueueSize= uxQueueSpacesAvailable(xQueue);

Serial.print("Messages Waiting: ");
Serial.print(msgsWaitingCount);
Serial.print(" ");
Serial.print("Available Space: ");
Serial.println(availableQueueSize);



 
 
}

}

void rxTask (void*)
{sensorInit Ultrasonic;

  while(1)
  {
    xQueueReceive(xQueue, &Ultrasonic, portMAX_DELAY);

    
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
  
    
  }
}
 

 
 
