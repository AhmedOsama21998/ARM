/*
 * STM32f103_GPIO.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Ahmed Osama
 */
#include "STM32f103_GPIO.h"
static GPIO_Reg_t* GPIOPort[5]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};
/*static AFIO_Reg_t* AFIOPort[5]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};*/

ErrorStatus_t GPIO_PinInit(const PinConfig_t * PinConfig)
{
	ErrorStatus_t status = OK;
	uint8_t Local_RegNum = (PinConfig->PinNum) / 8U;
	uint8_t Local_BitNum = (PinConfig->PinNum) % 8U;
	if(NULL == PinConfig)
	{
		status = ERROR;
	}else
	{
		if((PinConfig->PinNum <= PIN15)&&(PinConfig->Port <=PORTE))
		{
			switch (PinConfig->Mode.ModeType)
			{
			case InputMode:
				(GPIOPort[PinConfig->Port]->CR[Local_RegNum])&= ~(GPIO_CR_MASK<<(Local_BitNum * 4U));
				(GPIOPort[PinConfig->Port]->CR[Local_RegNum])|=  ((PinConfig->Mode.InputMode_t)<<Local_BitNum * 4U);
				break;
			case OutputMode:
				(GPIOPort[PinConfig->Port]->CR[Local_RegNum])&= ~(GPIO_CRCNF_MASK<<((Local_BitNum * 4U) + 2U));
				(GPIOPort[PinConfig->Port]->CR[Local_RegNum])|=  ((PinConfig->Mode.OutputMode_t)<<((Local_BitNum * 4U) + 2U));

				(GPIOPort[PinConfig->Port]->CR[Local_RegNum])&= ~(GPIO_CRMODE_MASK<<(Local_BitNum * 4U));
				(GPIOPort[PinConfig->Port]->CR[Local_RegNum])|=  ((PinConfig->Mode.OutputSpeed_t)<<Local_BitNum * 4U);
				break;
			default:status = ERROR;break;
			}
		}
	}
	return status;
}
ErrorStatus_t AFIO_ENR(const PinConfig_t * AFIOConfig)
{
	ErrorStatus_t status = OK;
	if(NULL == AFIOConfig)
	{
		status = NULL_PTR;
	}else
	{
		if((AFIOConfig->Port <= PORTE) && (AFIOConfig->PinNum <= PIN15))
		{
			AFIO->EVCR &=~ (AFIO_EVCR_PIN_MASK << AFIO_EVCR_PIN_POS);
			AFIO->EVCR |=  ((AFIOConfig->PinNum) <<AFIO_EVCR_PIN_POS);
			AFIO->EVCR &=~ (AFIO_EVCR_PORT_MASK << AFIO_EVCR_PORT_POS);
			AFIO->EVCR |=  ((AFIOConfig->Port) <<AFIO_EVCR_PORT_POS);
			switch (AFIOConfig->Mode.AFIO_Status)
			{
				case AFIO_Enable:
					SET_BIT(AFIO->EVCR,AFIO_EVCR_EVOE);
					break;
				case AFIO_Disable:
					CLEAR_BIT(AFIO->EVCR,AFIO_EVCR_EVOE);
					break;
				default:
					status = ERROR;
					break;
			}
		}else
		{
			status = ERROR;
		}
	}
	return status;
}
ErrorStatus_t AFIO_EXTRICR(const PinConfig_t * AFIOConfig)
{
	ErrorStatus_t status = OK;
	uint8_t Local_RegNum = (AFIOConfig->PinNum) / 4U;/* AFIO->EXTICR[Local_RegNum] */
	uint8_t Local_BitNum = (AFIOConfig->PinNum) % 4U;
	if(NULL == AFIOConfig)
	{
		status = NULL_PTR;
	}else
	{
		if((AFIOConfig->Port <= PORTE) && (AFIOConfig->PinNum <= PIN15))
		{
			/* PUT your Code Configuration Here*/
			AFIO->EXTICR[Local_RegNum] &= ~(AFIO_EXTICR_MASK << Local_BitNum *4U);
			AFIO->EXTICR[Local_RegNum] |=  ((AFIOConfig->Port) << Local_BitNum *4U);
		}else
		{
			status = ERROR;
		}
	}
	return status;
}
ErrorStatus_t GPIO_WritePin(Port_t Port,Pin_t PinNum,PinVal_t PinVal)
{
	ErrorStatus_t status = OK;
	if((Port <= PORTE) && (PinNum <= PIN15))
	{
		if(PinVal == PIN_HIGH)
		{
			/*GPIOPort[Port]->ODR |= (1<< PinNum);*/
			/*SET_BIT(GPIOPort[Port]->ODR,PinNum);*/
			SET_BIT(GPIOPort[Port]->BSRR,PinNum);
		}else if(PinVal == PIN_LOW)
		{
			/*GPIOPort[Port]->ODR &= ~(1<< PinNum);*/
			/*CLEAR_BIT(GPIOPort[Port]->ODR,PinNum);*/
			SET_BIT(GPIOPort[Port]->BSRR,(16+PinNum));
		}else
		{
			status = ERROR;
		}
	}else
	{
		status = ERROR;
	}
	return status;
}

ErrorStatus_t GPIO_ReadPin(Port_t Port,Pin_t PinNum,PinVal_t* PinVal)
{
	ErrorStatus_t status = OK;
	if((Port <= PORTE) && (PinNum <= PIN15))
	{
		*PinVal = READ_BIT(GPIOPort[Port]->IDR,PinNum);
	if(NULL== PinVal)
		{
		status= NULL_PTR;
		}
	}else
	{
		status = ERROR;
	}
	return status;
}

ErrorStatus_t GPIO_TogglePin(Port_t Port,Pin_t PinNum)
{
	ErrorStatus_t status = OK;
	if((Port <= PORTE) && (PinNum <= PIN15))
	{
			TOGGLE_BIT(GPIOPort[Port]->ODR,PinNum);
	}else
	{
		status = ERROR;
	}
	return status;
}
