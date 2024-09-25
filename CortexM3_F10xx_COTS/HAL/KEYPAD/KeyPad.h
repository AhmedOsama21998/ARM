/*
 * KeyPad.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Ahmed Osama
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_
#include "../MCAL/RCC/STM32f103_RCC.h"
#include "../MCAL/SysTick/STM32f103_STK.h"
#include "../MCAL/GPIO/STM32f103_GPIO.h"


#define KEYPAD_PORT      	 		PORTB


#define KEYPAD_C1_PIN     			PIN6
#define KEYPAD_C2_PIN     			PIN7
#define KEYPAD_C3_PIN     			PIN8
#define KEYPAD_C4_PIN     			PIN9


#define KEYPAD_R1_PIN     			PIN12
#define KEYPAD_R2_PIN     			PIN13
#define KEYPAD_R3_PIN     			PIN14
#define KEYPAD_R4_PIN     			PIN15


#define KEYPAD_ROW_NUM    		 	4
#define KEYPAD_COL_NUM     			4


#define KEYPAD_DEBOUNCING_MS    	20

#define KEY_NOT_PRESSED    			0xFF

#define KEYPAD_FLAG_UP    			1
#define KEYPAD_FLAG_DOWN  			0
#define COLUMNS_MASK				0x3C0
#define ROWS_MASK					0xFFFFF000
#define PORT_HIGH_MASK				0xFFFFF3C0

#define KEYPAD_KEYS					{{'1', '2', '3', '+'}, \
									{'4', '5', '6', '-'},  \
									{'7', '8', '9', '/'},  \
									{'*', '0', 'C', '='}}

#define KEYPAD_Cols  				{KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN, KEYPAD_C4_PIN}
#define KEYPAD_ROWs  				{KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN}


ErrorStatus_t KPD_voidInit(void);
uint8_t KPD_u8GetPressedKey (void);

#endif /* KEYPAD_KEYPAD_H_ */
