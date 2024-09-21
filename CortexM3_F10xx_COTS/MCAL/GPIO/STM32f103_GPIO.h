/*
 * STM32f103_GPIO.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Ahmed Osama
 */

#ifndef GPIO_STM32F103_GPIO_H_
#define GPIO_STM32F103_GPIO_H_

#include "../LIB/Std_Types.h"
/*************************************** Macro Declations ****************************************/

#define GPIOA_BASE_ADDRESS	0x40010800UL
#define GPIOB_BASE_ADDRESS	0x40010C00UL
#define GPIOC_BASE_ADDRESS	0x40011000UL
#define GPIOD_BASE_ADDRESS	0x40011400UL
#define GPIOE_BASE_ADDRESS	0x40011800UL
#define AFIO_BASE_ADDRESS	0x40010000UL

#define GPIOA	((GPIO_Reg_t*)GPIOA_BASE_ADDRESS)
#define GPIOB	((GPIO_Reg_t*)GPIOB_BASE_ADDRESS)
#define GPIOC	((GPIO_Reg_t*)GPIOC_BASE_ADDRESS)
#define GPIOD	((GPIO_Reg_t*)GPIOD_BASE_ADDRESS)
#define GPIOE	((GPIO_Reg_t*)GPIOE_BASE_ADDRESS)
#define AFIO 	((AFIO_Reg_t*)AFIO_BASE_ADDRESS)


/*********************************************************************************/
/******************* Macro Functions Declations for GPIOx_CR Resgister ******************/


#define GPIO_CR_MASK		0b1111
#define GPIO_CRMODE_MASK	0b11
#define GPIO_CRCNF_MASK		0b11


/******************* Macro Functions Declations for AFIO_EVCR Resgister ******************/

#define AFIO_EVCR_PIN_POS	(0U)
#define AFIO_EVCR_PIN_MASK	(0xFUL << AFIO_EVCR_PIN_POS)

#define AFIO_EVCR_PORT_POS	(4U)
#define AFIO_EVCR_PORT_MASK	(0x7UL << AFIO_EVCR_PORT_POS)

#define AFIO_EVCR_EVOE		(7U)

/******************* Macro Functions Declations for AFIO_EXTICR Resgister ******************/

#define AFIO_EXTICR_MASK	0b1111

/*********************************************************************************/

typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
}Port_t;

typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}Pin_t;

typedef struct
{
	enum
	{
		INPUT_ANLOG			      	=0b0000,
		INPUT_FLOATING				=0b0100,
		INPUT_PULLUP_PULLDOWN		=0b1000,
	}InputMode_t;
	 enum
	{
		OUTPUT_GP_PUSHPULL		=0b00,
		OUTPUT_GP_OPENDRAIN		=0b01,
		OUTPUT_AF_PUSHPULL		=0b10,
		OUTPUT_AF_OPENDRAIN		=0b11
	}OutputMode_t;
	 enum
	{
		OUTPUT_SPEED_10MHZ	=0b01,
		OUTPUT_SPEED_2MHZ	=0b10,
		OUTPUT_SPEED_50MHZ	=0b11,
	}OutputSpeed_t;
	enum
	{
		InputMode,OutputMode
	}ModeType;
	enum
	{
		AFIO_Enable,AFIO_Disable
	}AFIO_Status;
}GPIO_Mode_t;


typedef enum
{
	PIN_LOW=0,
	PIN_HIGH=1
}PinVal_t;
/*********************************************************************************/

typedef struct
{
	volatile uint32_t CR[2];
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Reg_t;

typedef struct
{
	Port_t			Port;
	Pin_t			PinNum;
	GPIO_Mode_t		Mode;
}PinConfig_t;

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	volatile uint32_t MAPR2;
}AFIO_Reg_t;



/******************* Software Interface Declarations *******************/
ErrorStatus_t GPIO_PinInit(const PinConfig_t * PinConfig);
ErrorStatus_t GPIO_WritePin(Port_t Port,Pin_t PinNum,PinVal_t PinVal);
ErrorStatus_t GPIO_TogglePin(Port_t Port,Pin_t PinNum);
ErrorStatus_t GPIO_ReadPin(Port_t Port,Pin_t PinNum,PinVal_t* PinVal);
ErrorStatus_t AFIO_ENR(const PinConfig_t * AFIOConfig);
ErrorStatus_t AFIO_EXTRICR(const PinConfig_t * AFIOConfig);

#endif /* GPIO_STM32F103_GPIO_H_ */
