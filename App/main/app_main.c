#include "FreeRTOS.h"
#include "main.h"

void StartMainTask(void *argument)
{
  for(;;)
  {
    HAL_GPIO_TogglePin(LED_Test_GPIO_Port,LED_Test_Pin);
    osDelay(2000);
  }
}