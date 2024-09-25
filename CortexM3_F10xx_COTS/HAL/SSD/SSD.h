/*
 * SSD.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Ahmed Osama
 */

#ifndef SSD_SSD_H_
#define SSD_SSD_H_
#include "../MCAL/GPIO/STM32f103_GPIO.h"


#define ZERO 	0b00111111
#define ONE		0b00000110
#define TWO		0b01011011
#define THREE	0b01001111
#define FOUR	0b01100110
#define FIVE	0b01101101
#define SIX		0b01111101
#define SEVEN	0b00000111
#define EIGHT	0b01111111
#define NINE 	0b01101111

#define SSD_PIN_MASK						0x3F8
#define SSD_CONNECTED_PINS_DATA_NUM			7
#define SSD_START_PIN						PIN3
#define COMMON_ANODE						19
#define COMMON_CATHODE						20



typedef struct
{
	uint8_t Port ;
	uint8_t CommonState ;
}SSD_t ;


void SSD_voidInit(SSD_t * S   );

void SSD_voidDisplayNumbers ( SSD_t * S , uint8_t Copy_u8Number  );
#endif /* SSD_SSD_H_ */
