/*
 * SSD.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Ahmed Osama
 */

#include "SSD.h"

uint8_t SSD_Numbers[10] = {ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };

void SSD_voidInit(SSD_t * SSD   )
{

	GPIO_SetPortDirection( SSD->Port, SSD_PIN_MASK, PortOutput);
	switch (SSD->CommonState)
	{
	case COMMON_ANODE :
		GPIO_SetPortValue(SSD->Port, PIN_HIGH);
		break;
	case COMMON_CATHODE :
		GPIO_SetPortValue(SSD->Port , PIN_LOW );
		break;
	default:
		break;
	}
}

void SSD_voidDisplayNumbers ( SSD_t * SSD , uint8_t Copy_u8Number  )
{
	switch (SSD->CommonState )
	{
	case COMMON_CATHODE:
		GPIO_SetSpecificPinsValue(SSD->Port, SSD_Numbers[Copy_u8Number], SSD_START_PIN, SSD_CONNECTED_PINS_DATA_NUM);
		break;

	case COMMON_ANODE :
		GPIO_SetSpecificPinsValue(SSD->Port, ~SSD_Numbers[Copy_u8Number], SSD_START_PIN, SSD_CONNECTED_PINS_DATA_NUM);
	break ;
	default:
		break;
	}
}

