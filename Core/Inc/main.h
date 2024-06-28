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
#include "stm32g0xx_hal.h"
#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_system.h"
#include "stm32g0xx_ll_exti.h"
#include "stm32g0xx_ll_cortex.h"
#include "stm32g0xx_ll_utils.h"
#include "stm32g0xx_ll_pwr.h"
#include "stm32g0xx_ll_dma.h"
#include "stm32g0xx_ll_rtc.h"
#include "stm32g0xx_ll_usart.h"
#include "stm32g0xx_ll_wwdg.h"
#include "stm32g0xx_ll_gpio.h"

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
#define COL_LAT_IN_Pin LL_GPIO_PIN_0
#define COL_LAT_IN_GPIO_Port GPIOA
#define COL_CLK_IN_Pin LL_GPIO_PIN_1
#define COL_CLK_IN_GPIO_Port GPIOA
#define DATA1_Pin LL_GPIO_PIN_4
#define DATA1_GPIO_Port GPIOA
#define DATA2_Pin LL_GPIO_PIN_5
#define DATA2_GPIO_Port GPIOA
#define DISP_ENB_Pin LL_GPIO_PIN_6
#define DISP_ENB_GPIO_Port GPIOA
#define DOT_Pin LL_GPIO_PIN_7
#define DOT_GPIO_Port GPIOA
#define INT_Pin LL_GPIO_PIN_0
#define INT_GPIO_Port GPIOB
#define GPIO_12_24_Pin LL_GPIO_PIN_1
#define GPIO_12_24_GPIO_Port GPIOB
#define HH_TEN_Pin LL_GPIO_PIN_2
#define HH_TEN_GPIO_Port GPIOB
#define HH_UNIT_Pin LL_GPIO_PIN_10
#define HH_UNIT_GPIO_Port GPIOB
#define MM_TEN_Pin LL_GPIO_PIN_11
#define MM_TEN_GPIO_Port GPIOB
#define MM_UNIT_Pin LL_GPIO_PIN_12
#define MM_UNIT_GPIO_Port GPIOB
#define SS_TEN_IN_Pin LL_GPIO_PIN_13
#define SS_TEN_IN_GPIO_Port GPIOB
#define SS_UNIT_IN_Pin LL_GPIO_PIN_14
#define SS_UNIT_IN_GPIO_Port GPIOB
#define PRG_Pin LL_GPIO_PIN_15
#define PRG_GPIO_Port GPIOB
#define DEC_Pin LL_GPIO_PIN_11
#define DEC_GPIO_Port GPIOA
#define INC_Pin LL_GPIO_PIN_12
#define INC_GPIO_Port GPIOA
#define debug_35_Pin LL_GPIO_PIN_13
#define debug_35_GPIO_Port GPIOA
#define debug_36_Pin LL_GPIO_PIN_14
#define debug_36_GPIO_Port GPIOA
#define GPS_ON_Pin LL_GPIO_PIN_15
#define GPS_ON_GPIO_Port GPIOA
#define LED_BLINK_Pin LL_GPIO_PIN_0
#define LED_BLINK_GPIO_Port GPIOD
#define TEST_Pin LL_GPIO_PIN_5
#define TEST_GPIO_Port GPIOB
#define SCL_Pin LL_GPIO_PIN_6
#define SCL_GPIO_Port GPIOB
#define SDA_Pin LL_GPIO_PIN_7
#define SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define READ_TEST                 LL_GPIO_IsInputPinSet(GPIO_PORT_B, GPIO_PIN_5)                //PB5

#define READ_GPIO_12_24             LL_GPIO_IsInputPinSet(GPIO_PORt_B, GPIO_PIN_1)                //PB1

#define READ_INT                  LL_GPIO_IsInputPinSet(GPIO_PORT_B, GPIO_PIN_0)                //PB0

#define READ_INC                  LL_GPIO_IsInputPinSet(GPIO_PORT_B, GPIO_PIN_12)               //PB12

#define READ_SS_TEN               LL_GPIO_IsInputPinSet(GPIO_PORT_B, GPIO_PIN_13)               //PB13

#define READ_PRG                  LL_GPIO_IsInputPinSet(GPIO_PORT_B, GPIO_PIN_15)               //PB15

#define READ_SS_UNIT              LL_GPIO_IsInputPinSet(GPIO_PORT_B, GPIO_PIN_14)               //PB14

#define READ_COL_LAT              LL_GPIO_IsInputPinSet(GPIO_PORT_A, GPIO_PIN_0)                //PA0

#define READ_COL_CLK              LL_GPIO_IsInputPinSet(GPIO_PORT_A, GPIO_PIN_1)                //PA1
  
#define SWRITE_DATA1              LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);
#define RWRITE_DATA1              LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);

#define SWRITE_DATA2              LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
#define RWRITE_DATA2              LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);

#define SWRITE_DISP_ENB           LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6);  
#define RWRITE_DISP_ENB           LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);

#define SWRITE_DOT                LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_7);
#define RWRITE_DOT                LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);

#define SWRITE_HH_TEN             LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_2);
#define RWRITE_HH_TEN             LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_2);

#define SWRITE_HH_UNIT            LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_10);
#define RWRITE_HH_UNIT            LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_10);

#define SWRITE_MM_TEN             LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_0);
#define RWRITE_MM_TEN             LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0);

#define SWRITE_MM_UNIT            LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_0);
#define RWRITE_MM_UNIT            LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0);

#define SWRITE_SDA                LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
#define RWRITE_SDA                LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);

#define SWRITE_SCL                LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
#define RWRITE_SCL                LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);

#define SWRITE_GPS_ON             LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
#define RWRITE_GPS_ON             LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);









/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
