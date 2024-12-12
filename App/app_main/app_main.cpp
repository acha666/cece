#include "FreeRTOS.h"
#include "cmsis_os2.h"
#include "main.h"

#include <exception>

#include "app_main.hpp"

extern "C" void StartMainTask(void *argument)
{
  for(;;)
  {
    HAL_GPIO_TogglePin(LED_Test_GPIO_Port,LED_Test_Pin);
    osDelay(2000);
  }
}