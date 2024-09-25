/*
 * LCD.h
 *
 *  Created on: Sep 23, 2024
 *      Author: Ahmed Osama
 */

#ifndef LCD_LCD_H_
#define LCD_LCD_H_
#include "../MCAL/RCC/STM32f103_RCC.h"
#include "../MCAL/SysTick/STM32f103_STK.h"
#include "../MCAL/GPIO/STM32f103_GPIO.h"

#define LCD_DATA_PORT   	PORTA
#define LCD_CTRL_PORT		PORTB

#define LCD_DATA_PIN_MASK	0xFF	/*pin 0 to pin  7  (DATA PINs)   */
#define LCD_CTRL_PIN_MASK	0x3 	/*Pin 0 (RSPIN) and pin 1 (ENPIN)*/

#define LCD_RSPIN  			PIN0
#define LCD_ENPIN   		PIN1
/*#define LCD_RWPIN  			PIN14*/

typedef enum
{
	LCD_ROW1,
	LCD_ROW2
}LCD_Row_t;
#define LCD_COLUMN_NUM		16



ErrorStatus_t LCD_Init(void);
ErrorStatus_t LCD_WriteChar(uint8_t Data);
ErrorStatus_t LCD_WriteString(uint8_t *String, uint8_t Size);
ErrorStatus_t LCD_SetCursor(uint8_t Row, uint8_t Column);
ErrorStatus_t LCD_ScrollRight(void);
ErrorStatus_t LCD_ScrollLeft(void);
ErrorStatus_t LCD_PrintNumber(int32_t Number);
ErrorStatus_t LCD_Clear(void);
ErrorStatus_t LCD_WriteSpecialChar(uint8_t *Pattern, uint8_t PatternNumber ,uint8_t Row, uint8_t Column);

#endif /* LCD_LCD_H_ */
