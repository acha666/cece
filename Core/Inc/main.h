/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PE5_TIM91_M1_OUTA_Pin GPIO_PIN_5
#define PE5_TIM91_M1_OUTA_GPIO_Port GPIOE
#define PE6_TIM92_M1_OUTB_Pin GPIO_PIN_6
#define PE6_TIM92_M1_OUTB_GPIO_Port GPIOE
#define LED_Test_Pin GPIO_PIN_1
#define LED_Test_GPIO_Port GPIOA
#define PA2_TIM23_M0_OUTA_Pin GPIO_PIN_2
#define PA2_TIM23_M0_OUTA_GPIO_Port GPIOA
#define PA3_TIM24_M0_OUTB_Pin GPIO_PIN_3
#define PA3_TIM24_M0_OUTB_GPIO_Port GPIOA
#define PB14_TIM121_SERVO_Pin GPIO_PIN_14
#define PB14_TIM121_SERVO_GPIO_Port GPIOB
#define PB15_TIM122_SERVO_Pin GPIO_PIN_15
#define PB15_TIM122_SERVO_GPIO_Port GPIOB
#define PD12_TIM41_SERVO_Pin GPIO_PIN_12
#define PD12_TIM41_SERVO_GPIO_Port GPIOD
#define PD13_TIM42_SERVO_Pin GPIO_PIN_13
#define PD13_TIM42_SERVO_GPIO_Port GPIOD
#define PD14_TIM43_SERVO_Pin GPIO_PIN_14
#define PD14_TIM43_SERVO_GPIO_Port GPIOD
#define PD15_TIM44_SERVO_Pin GPIO_PIN_15
#define PD15_TIM44_SERVO_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
