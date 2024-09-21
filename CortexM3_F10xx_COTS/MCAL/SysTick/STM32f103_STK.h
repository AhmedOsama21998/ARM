/*
 * STM32f103_STK.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Ahmed Osama
 */

#ifndef SYSTICK_STM32F103_STK_H_
#define SYSTICK_STM32F103_STK_H_

#include "../LIB/Std_Types.h"

#define STK					((STK_Reg_t *)0xE000E010UL)

typedef enum
{
	ENABLE=0,
	TICKINT,
	CLKSOURCE,
	COUNTFLAG=16
}STKCTRL_t;

typedef struct
{
	volatile uint32_t STK_CTRL;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;

}STK_Reg_t;

ErrorStatus_t STK_Init();
ErrorStatus_t STK_Delay_Ms(uint32_t MilliSec);

#endif /* SYSTICK_STM32F103_STK_H_ */
