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
#include "stm32h7xx_hal.h"
#include <stdbool.h>
#include <stdint.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

enum Direction_E
{
   DIRECTION_FORWARD_MIN,
   DIRECTION_FORWARD_NOMINAL,
   DIRECTION_FORWARD_MAX,
   DIRECTION_REVERSE_MIN,
   DIRECTION_REVERSE_NOMINAL,
   DIRECTION_REVERSE_MAX,
   DIRECTION_ERROR,
   DIRECTION_NOT_AVAILABLE
};

typedef float    Hz_T;
typedef uint32_t us_T;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

#define DIRECTION_FORWARD_HIGH_PULSE_TIME_NOMINAL     45000.0f // ns
#define DIRECTION_FORWARD_HIGH_PULSE_TIME_TOLERANCE    7000.0f
#define DIRECTION_REVERSE_HIGH_PULSE_TIME_NOMINAL     45000.0f
#define DIRECTION_REVERSE_HIGH_PULSE_TIME_TOLERANCE   14000.0f
#define DIRECTION_ERROR_HIGH_PULSE_TIME               200000.0f

#define MIN_FREQUENCY_TO_TEST                         3.5   // Hz
#define MAX_FREQUENCY_TO_TEST                         2660.0

#define MAX_ADC_COUNT(adc_handle)                     __HAL_ADC_DIGITAL_SCALE((adc_handle)->Init.Resolution)
#define MIN_ADC_COUNT                                 0u

#define TIMER_CLOCK_RATE_HZ                           64000000 // TODO: Use an actual generated config for this; just need to find it. Candidate macro: HSI_VALUE of Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_ll_rcc.h
#define NANOSECONDS_PER_TIMER_COUNT                   ( (float)( 1.0e9f / (float)TIMER_CLOCK_RATE_HZ ) )
#define TIMER_COUNTS_PER_NANOSECOND                   ( 1.0f / NANOSECONDS_PER_TIMER_COUNT )

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

#ifdef UNIT_TEST
   #define STATIC
#else
   #define STATIC static
#endif

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define Frq_Out_Pin GPIO_PIN_10
#define Frq_Out_GPIO_Port GPIOE
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLINK_RX_Pin GPIO_PIN_8
#define STLINK_RX_GPIO_Port GPIOD
#define STLINK_TX_Pin GPIO_PIN_9
#define STLINK_TX_GPIO_Port GPIOD
#define USB_OTG_FS_PWR_EN_Pin GPIO_PIN_10
#define USB_OTG_FS_PWR_EN_GPIO_Port GPIOD
#define USB_OTG_FS_OVCR_Pin GPIO_PIN_7
#define USB_OTG_FS_OVCR_GPIO_Port GPIOG
#define JTMS_Pin GPIO_PIN_13
#define JTMS_GPIO_Port GPIOA
#define JTCK_Pin GPIO_PIN_14
#define JTCK_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_1
#define LD2_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */
#define BLUE_BUTTON_PIN   B1_Pin
#define BLUE_BUTTON_PORT  B1_GPIO_Port
#define FRQ_OUT_PIN       Frq_Out_Pin
#define FRQ_OUT_PORT      Frq_Out_GPIO_Port

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
