/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : stm32f10x_conf.h
* Author             : MCD Application Team
* Date First Issued  : 09/29/2006
* Description        : Library configuration file.
********************************************************************************
* History:
* 05/21/2007: V0.3
* 04/02/2007: V0.2
* 02/05/2007: V0.1
* 09/29/2006: V0.01
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_CONF_H
#define __STM32F10x_CONF_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_type.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line below to compile the library in DEBUG mode, this will expanse
   the "assert" macro in the firmware library code (see "Exported macro" section below) */
/* #define DEBUG */

/************************************* BKP ************************************/
#define _BKP

/************************************* DMA ************************************/
#define _DMA

///************************************* EXTI ***********************************/
#define _EXTI

/************************************* GPIO ***********************************/
#define _GPIO
#define _GPIOA
#define _GPIOB
#define _GPIOC
//#define _GPIOD
//#define _GPIOE
#define _AFIO

/************************************* IWDG ***********************************/
#define _IWDG

/************************************* NVIC ***********************************/
#define _NVIC

/************************************* PWR ************************************/
#define _PWR

/************************************* RCC ************************************/
#define _RCC

/************************************* RTC ************************************/
#define _RTC

/************************************* SysTick ********************************/
//#define _SysTick
/************************************* USART **********************************/
#define _USART1
#define _USART2
//#define _USART3

/************************************* WWDG ***********************************/
//#define _WWDG

/* In the following line adjust the value of External High Speed oscillator (HSE)
   used in your application */
#define HSE_Value    ((u32)12000000) /* Value of the External oscillator in Hz*/

/* Exported macro ------------------------------------------------------------*/
#undef assert
#ifdef  DEBUG
/*******************************************************************************
* Macro Name     : assert
* Description    : The assert macro is used for function's parameters check.
*                  It is used only if the library is compiled in DEBUG mode.
* Input          : - expr: If expr is false, it calls assert_failed function
*                    which reports the name of the source file and the source
*                    line number of the call that failed.
*                    If expr is true, it returns no value.
* Return         : None
*******************************************************************************/
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((u8 *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(u8* file, u32 line);
#else
  #define assert_param(expr) ((void)0)
#endif /* DEBUG */

#endif /* __STM32G0x_CONF_H */

/******END OF FILE****/
