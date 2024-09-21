/*
 * STM32f103_STK.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Ahmed Osama
 */
#include "STM32f103_STK.h"


ErrorStatus_t STK_Init()
{
	ErrorStatus_t status = OK;

	SET_BIT(STK->STK_CTRL,ENABLE);/* Enables the counter */
	CLEAR_BIT(STK->STK_CTRL,TICKINT);/*Disable SysTick exception request*/
	CLEAR_BIT(STK->STK_CTRL,CLKSOURCE);/*AHB Div by 8 */

	return status;
}

ErrorStatus_t STK_Delay_Ms(uint32_t MilliSec)
{
	ErrorStatus_t status = OK;
	for(uint32_t counter=0; counter<MilliSec; counter++)
	{
		SET_BIT(STK->STK_CTRL,ENABLE);
		CLEAR_BIT(STK->STK_CTRL,TICKINT);
		STK->STK_LOAD	=	1000;
		while(READ_BIT(STK->STK_CTRL,COUNTFLAG)	==	0);
		CLEAR_BIT(STK->STK_CTRL,ENABLE);
		STK->STK_LOAD	=	0;
		STK->STK_VAL	=	0;
	}
	return status;

}
