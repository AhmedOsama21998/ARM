/*
 * STM32f103_NVIC.c
 *
 *  Created on: Oct 11, 2024
 *      Author: Ahmed Osama
 */

#include "STM32f103_NVIC.h"


ErrorStatus_t NVIC_EnableIRQ(IRQn_Type IRQn)
{
	ErrorStatus_t status = OK;
	uint8_t Local_RegNum = IRQn / 32;
	uint8_t Local_BitNum = IRQn % 32;
	if(IRQn <= NVIC_DMA2_Ch4_5)
	{
		NVIC->ISER[Local_RegNum] = 1<< Local_BitNum;
	}else
	{
		status =ERROR;
	}
	return status;
}
ErrorStatus_t NVIC_DisableIRQ(IRQn_Type IRQn)
{
	ErrorStatus_t status = OK;
	uint8_t Local_RegNum = IRQn / 32;
	uint8_t Local_BitNum = IRQn % 32;
	if(IRQn <= NVIC_DMA2_Ch4_5)
	{
		NVIC->ICER[Local_RegNum] = 1<< Local_BitNum;
	}else
	{
		status =ERROR;
	}
	return status;
}
ErrorStatus_t NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	ErrorStatus_t status = OK;
	uint8_t Local_RegNum = IRQn / 32;
	uint8_t Local_BitNum = IRQn % 32;
	if(IRQn <= NVIC_DMA2_Ch4_5)
	{
		NVIC->ISPR[Local_RegNum] = 1<< Local_BitNum;
	}else
	{
		status =ERROR;
	}
	return status;
}
ErrorStatus_t NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	ErrorStatus_t status = OK;
	uint8_t Local_RegNum = IRQn / 32;
	uint8_t Local_BitNum = IRQn % 32;
	if(IRQn <= NVIC_DMA2_Ch4_5)
	{
		NVIC->ICPR[Local_RegNum] = 1<< Local_BitNum;
	}else
	{
		status =ERROR;
	}
	return status;
}
ErrorStatus_t NVIC_GetActiveFlag(IRQn_Type IRQn , uint8_t * FlagStatus)
{
	ErrorStatus_t status = OK;
	uint8_t Local_RegNum = IRQn / 32;
	uint8_t Local_BitNum = IRQn % 32;
	if(NULL == FlagStatus)
	{
		status = NULL_PTR;
	}else
	{
		if(IRQn <= NVIC_DMA2_Ch4_5)
		{
			*FlagStatus = READ_BIT(NVIC->IABR[Local_RegNum],Local_BitNum);
		}else
		{
			status =ERROR;
		}
	}
	return status;
}

ErrorStatus_t NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority)
{
	ErrorStatus_t status = OK;
	if((IRQn <= NVIC_DMA2_Ch4_5)&(priority <= 15))
	{
		NVIC->IPR[IRQn] = priority << 4;
	}else
	{
		status =ERROR;
	}
	return status;
}


ErrorStatus_t NVIC_SetPriorityGrouping(PriGp_t priority_grouping)
{
	ErrorStatus_t status = OK;
	if(priority_grouping <= 0x05FA0700)
	{
		SCB_AIRCR = priority_grouping;
	}else
	{
		status =ERROR;
	}
	return status;
}
