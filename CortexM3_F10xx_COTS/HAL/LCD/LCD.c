/*
 * LCD.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Ahmed Osama
 */
#include "LCD.h"
static ErrorStatus_t LCD_SendInstruction(uint8_t Instruction);

ErrorStatus_t LCD_Init(void)
{
	ErrorStatus_t Status =OK;

	RCC_OscInit_t	RCC_OscInitSTRUCT ;

	RCC_OscInitSTRUCT.OSC_Type =RCC_OSCTYPE_HSI;
	RCC_OscInitSTRUCT.HSIState=RCC_HSI_ON;
	Status= RCC_OscConfig(&RCC_OscInitSTRUCT);
	RCC_SetSysClk(RCC_HSI_SYSCLK);
	/*HSI Is System Clk with 8 MHZ */
	RCC_EnableClk(RCC_APB2, RCC_GPIOA);
	RCC_EnableClk(RCC_APB2, RCC_GPIOB);
	STK_Init();
	//Configure the direction of all CONTROL pins is o/p
	//Configure the direction of data port
	Status = GPIO_SetPortDirection(LCD_CTRL_PORT,LCD_CTRL_PIN_MASK, PortOutput);
	Status = GPIO_SetPortDirection(LCD_DATA_PORT,LCD_DATA_PIN_MASK,PortOutput);

	/*LCD Initialization*/
	STK_Delay_Ms(30);
	/*Fn Set*/
	LCD_SendInstruction(0b00111100);
	STK_Delay_Ms(2);
	/*Display ON/OFF*/
	LCD_SendInstruction(0b00001100);
	STK_Delay_Ms(2);
	/*Clear Display*/
	LCD_SendInstruction(0b00000001);
	STK_Delay_Ms(2);
	/*Entry Mode Set*/
	LCD_SendInstruction(0b00000110);
	STK_Delay_Ms(2);
	return Status;
}



static ErrorStatus_t LCD_SendInstruction(uint8_t Instruction)
{
	ErrorStatus_t Status =OK;

	//RS = 0 (Command), RW = 0 (Write), E = 1 (Enable)
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_RSPIN, PIN_LOW);
/*	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_RWPIN, PIN_LOW);*/
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_ENPIN, PIN_HIGH);

	//001,DL(8-bit data),N(2-lines),F(5*10 dots)
	Status = GPIO_SetPortValue(LCD_DATA_PORT, Instruction);
	//E (1 then 0 --> falling edge)
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_ENPIN, PIN_HIGH);
	STK_Delay_Ms(1);
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_ENPIN, PIN_LOW);

	return Status;
}

ErrorStatus_t LCD_WriteChar(uint8_t Data)
{
	ErrorStatus_t Status =OK;

	//RS = 1 (Data), RW = 0 (Write), E = 1 (Enable)
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_RSPIN, PIN_HIGH);
/*	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_RWPIN, PIN_LOW);*/
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_ENPIN, PIN_HIGH);

	//001,DL(8-bit data),N(2-lines),F(5*10 dots)
	Status = GPIO_SetPortValue(LCD_DATA_PORT, Data);

	//LCD_ENPIN (1 then 0 --> falling edge)
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_ENPIN, PIN_HIGH);
	STK_Delay_Ms(1);
	Status = GPIO_WritePin(LCD_CTRL_PORT, LCD_ENPIN, PIN_LOW);

	return Status;

}
ErrorStatus_t LCD_WriteString(uint8_t *String, uint8_t Size)
{
	ErrorStatus_t Status =OK;
	//String is an array of characters
	for(uint8_t i=0; i<Size; i++)
	{
		Status = LCD_WriteChar(String[i]);	//Write a char on each iteration
	}
	return Status;
}

ErrorStatus_t LCD_SetCursor(uint8_t Row, uint8_t Column)
{
	ErrorStatus_t Status =OK;

	if( (Row == LCD_ROW1) && (Column < LCD_COLUMN_NUM) )		//Writing on Any grid resides on the 1st row
	{
		LCD_SendInstruction(0x80 + Column);	//0x80 is the address of the 1st location in the 1st row
	}
	else if( (Row == LCD_ROW2) && (Column < LCD_COLUMN_NUM) )//Writing on Any grid resides on the 2nd row
	{
		LCD_SendInstruction(0xC0 + Column);	//0xC0 is the address of the 1st location in the 1st row
	}
	else
	{
		//Do Nothing
	}
	return Status;
}
ErrorStatus_t LCD_ScrollLeft(void)
{
	ErrorStatus_t Status =OK;

    // Send the command to shift display to the left
	LCD_SendInstruction(0x18);
	return Status;

}
ErrorStatus_t LCD_ScrollRight(void)
{
	ErrorStatus_t Status =OK;

    // Send the command to shift display to the right
	LCD_SendInstruction(0x1C);
	return Status;

}
ErrorStatus_t LCD_PrintNumber(int32_t Number)
{
	ErrorStatus_t Status =OK;
	uint8_t buffer[12];   // Max size for 32-bit integer (11 digits + null terminator)
    uint8_t i = 0;
    uint8_t isNegative = 0;
    // Handle negative numbers
    if (Number < 0)
    {
        isNegative = 1;
        Number = -Number;
    }
    // Convert number to string (reverse order)
    do
    {
        buffer[i++] = (Number % 10) + '0';  // Get the last digit and convert it to character
        Number /= 10;                       // Remove the last digit
    } while (Number != 0);
    // Add '-' for negative numbers
    if (isNegative)
    {
        buffer[i++] = '-';
    }
    // Now print the string in reverse order
    while (i > 0) {
        LCD_WriteChar(buffer[--i]);  // Assuming you have an LCD_WriteData() to send a single character to the LCD
    }
	return Status;
}

ErrorStatus_t LCD_Clear(void)
{
	ErrorStatus_t Status =OK;
	LCD_SendInstruction(0b00000001);
	return Status;
}
ErrorStatus_t LCD_WriteSpecialChar(uint8_t *Pattern, uint8_t PatternNumber ,uint8_t Row, uint8_t Column)
{
	ErrorStatus_t Status =OK;
	/*Set CGRAM address */
	/*calculate the CGRAM address*/
	uint8_t Local_Adress=(PatternNumber*8);
	LCD_SendInstruction(Local_Adress+64);
	/*                    address   +64th bit*/

	/*save the pattern in CGRAM address */
	/* or Write data to CGRAM or DDRAM */
	for (uint8_t i=0 ;i<8 ;i++)
	{
		LCD_WriteChar(Pattern[i]);
		//the address counter counter AC will auto increment the next address
	}

	/*Set DDRAM Address */
	/*or go back to DDRAM to display the pattern*/
	LCD_SetCursor(Row, Column);
	/* Read data from CGRAM or DDRAM*/
	/*or display the pattern*/
	LCD_WriteChar(PatternNumber); //instead of ASCII letter in CGROM

	return Status;
}
