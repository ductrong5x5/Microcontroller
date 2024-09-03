#include <Arduino_FreeRTOS.h>
#include "semphr.h"
#define rtDelay(v) {vTaskDelay(v/15);}

SemaphoreHandle_t Binary_Semaphore;

void setup()
{
  Serial.begin(9600);
  xTaskCreate(taskSerial1, "serial1", 128, NULL, 0, NULL);
  xTaskCreate(taskSerial2, "serial2", 128, NULL, 2, NULL);
  Binary_Semaphore= xSemaphoreCreateMutex();
  xSemaphoreGive(Binary_Semaphore);
  
  
}

void loop()
{}

void taskSerial1(void*)
{while(1)
{ xSemaphoreTake(Binary_Semaphore, portMAX_DELAY);
  Serial.println("I am in Task Serial 1");
  xSemaphoreGive(Binary_Semaphore);
  rtDelay(30);
}
}


void taskSerial2(void*)
{while(1)
{ xSemaphoreTake(Binary_Semaphore, portMAX_DELAY);
  Serial.println("I am in Task Serial 2");
  xSemaphoreGive(Binary_Semaphore);
  rtDelay(30);
}
}
