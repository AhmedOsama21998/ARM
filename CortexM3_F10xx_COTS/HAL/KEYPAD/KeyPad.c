/*
 * KeyPad.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Ahmed Osama
 */

#include "KeyPad.h"

uint8_t KEYPAD_Keys [KEYPAD_ROW_NUM][KEYPAD_COL_NUM] = KEYPAD_KEYS;
uint8_t KEYPAD_RowsPins[KEYPAD_ROW_NUM] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN};
uint8_t KEYPAD_ColsPins[KEYPAD_COL_NUM] = {KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN,KEYPAD_C4_PIN};


ErrorStatus_t KPD_voidInit(void)
{
	ErrorStatus_t Status =OK;
	Status=GPIO_SetPortDirection(KEYPAD_PORT, COLUMNS_MASK, PortOutput);		// 6  7  8  9 	(COLUMNS)
	Status=GPIO_SetPortDirection(KEYPAD_PORT,ROWS_MASK,PortInput);				// 12 13 14 15	(ROWS)
	Status=GPIO_SetPortValue(KEYPAD_PORT, PORT_HIGH_MASK);
	if(Status == ERROR)
	{
		Status =ERROR;
	}
	return Status;
}
uint8_t  KPD_u8GetPressedKey (void)
{
	uint8_t 	RowCounter;
	uint8_t		ColCounter;
	uint8_t		PinValue;
	uint8_t		KeyValue=KEY_NOT_PRESSED;
	for (ColCounter=0; ColCounter < KEYPAD_COL_NUM; ColCounter++ )
	{
		//Activate Column by Setting 0 at output
		GPIO_WritePin(KEYPAD_PORT, KEYPAD_ColsPins[ColCounter], PIN_LOW);

		for (RowCounter=0; RowCounter < KEYPAD_ROW_NUM; RowCounter++)
		{
			GPIO_ReadPin(KEYPAD_PORT, KEYPAD_RowsPins[RowCounter], &PinValue); //Get row value

			if (PinValue == PIN_LOW)  //check for row value (if true --> switch is pressed)
			{
				STK_Delay_Ms(KEYPAD_DEBOUNCING_MS); //Delay for De-bouncing Effect
				GPIO_ReadPin(KEYPAD_PORT, KEYPAD_RowsPins[RowCounter],& PinValue); //Get row value

				if (PinValue == PIN_LOW)  //check for row value (if true --> switch is pressed)
				{
					KeyValue = KEYPAD_Keys [RowCounter][ColCounter]; //Read
				}
				while (PinValue == PIN_LOW)
				{
					GPIO_ReadPin(KEYPAD_PORT, KEYPAD_RowsPins[RowCounter],& PinValue); //Get row value
				}
			}
		}
		GPIO_WritePin(KEYPAD_PORT, KEYPAD_ColsPins[ColCounter], PIN_HIGH); //De-Activate column by Setting 1 at output
	}
	return KeyValue;
}
