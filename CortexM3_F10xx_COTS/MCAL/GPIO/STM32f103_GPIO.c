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


ErrorStatus_t GPIO_SetPortDirection(Port_t Port, uint32_t PinMask, PortDirection_t Direction)
{
	ErrorStatus_t status = OK;
    for (uint8_t pin = 0; pin < 16; ++pin)
    {
        if (PinMask & (1 << pin))
        {
            if (pin < 8)
            {
                // For pins 0-7, modify CRL register
            	GPIOPort[Port]->CR[0] &= ~(0xF << (pin * 4));  // Clear the 4 bits for this pin
                if (Direction == PortOutput)
                {
                	GPIOPort[Port]->CR[0] |= (0x3 << (pin * 4));  // Set as output (e.g., 0b0011)
                } else
                {
                	GPIOPort[Port]->CR[0] |= (0x8<< (pin * 4));  // Set as input (e.g., 0b0100)INPUT PullUp PullDown
                }
            } else
            {
                // For pins 8-15, modify CRH register
            	GPIOPort[Port]->CR[1] &= ~(0xF << ((pin - 8) * 4));  // Clear the 4 bits for this pin
                if (Direction == PortOutput)
                {
                	GPIOPort[Port]->CR[1] |= (0x3 << ((pin - 8) * 4));  // Set as output
                } else
                {
                	GPIOPort[Port]->CR[1]|= (0x8 << ((pin - 8) * 4));  // Set as input INPUT PullUp PullDown
                }
            }
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

ErrorStatus_t GPIO_SetPortValue(Port_t Port, uint32_t Value)
{
	ErrorStatus_t status = OK;
	   switch(Port)
	    {
	        case PORTA:
	            GPIOA->ODR = Value;
	            break;
	        case PORTB:
	            GPIOB->ODR = Value;
	            break;
	        case PORTC:
	            GPIOC->ODR = Value;
	            break;
	        case PORTD:
	            GPIOD->ODR = Value;
	            break;
	        case PORTE:
	            GPIOE->ODR = Value;
	            break;
	        default:
	            return status = ERROR;  // Invalid port
	    }

	return status;
}
ErrorStatus_t GPIO_SetSpecificPinsValue(Port_t Port, uint32_t Value, uint8_t StartPin, uint8_t NumPins)
{
    ErrorStatus_t status = OK;

    if (StartPin > 15 || NumPins > 16 || (StartPin + NumPins) > 16)
    {
        return status = ERROR;  // Invalid pin range
    }
    uint32_t mask = (1 << NumPins) - 1;        // Create a mask for the number of pins to be modified
    mask <<= StartPin;                         // Shift the mask to the starting pin position
    Value <<= StartPin;                        // Shift the value to match the pin position
	GPIOPort[Port]->ODR = (GPIOPort[Port]->ODR & ~mask) | (Value & mask); // Clear the masked bits, then set the new value

    return status;
}

ErrorStatus_t GPIO_ReadPin(Port_t Port,Pin_t PinNum,PinVal_t *PinVal)
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
