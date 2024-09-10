/*
 * STM32f103_RCC.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Ahmed Osama
 */
#ifndef RCC_STM32F103_RCC_H_
#define RCC_STM32F103_RCC_H_

#include"stdint.h"
/******************* Macro Declations *******************/
#define NULL								0
#define SET_BIT(REG, BIT)   				((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)  				((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)   				((REG) & (BIT))

#define READ_REG(REG)						((REG))
#define WRITE_REG(REG,VAL)					((REG) =(VAL))
#define MODIFY_REG(REG,CLEARMASK,SETMASK)	WRITE_REG((REG) ,((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK))

#define RCC					((RCC_Reg_t *)0x40021000UL)
#define RCC_OSCTYPE_NONE	0x00000000U
#define RCC_OSCTYPE_HSI		0x00000001U
#define RCC_OSCTYPE_HSE		0x00000002U
#define RCC_OSCTYPE_LSI		0x00000004U
#define RCC_OSCTYPE_LSE		0x00000008U

#define RCC_HSE_OFF			((uint8_t)0x00)
#define RCC_HSE_ON			((uint8_t)0x01)
#define RCC_HSI_OFF			((uint8_t)0x00)
#define RCC_HSI_ON			((uint8_t)0x01)
#define RCC_LSE_OFF			((uint8_t)0x00)
#define RCC_LSE_ON			((uint8_t)0x01)
#define RCC_LSI_OFF			((uint8_t)0x00)
#define RCC_LSI_ON			((uint8_t)0x01)


#define RCC_CFGR_HPRE_Pos	(4U)
#define RCC_CFGR_HPRE_Msk	(0xFUL << RCC_CFGR_HPRE_Pos)
#define RCC_AHB_DIV_1		0x00000000U
#define RCC_AHB_DIV_2		0x00000080U
#define RCC_AHB_DIV_4		0x00000090U
#define RCC_AHB_DIV_8		0x000000A0U
#define RCC_AHB_DIV_16		0x000000B0U
#define RCC_AHB_DIV_64		0x000000C0U
#define RCC_AHB_DIV_128		0x000000D0U
#define RCC_AHB_DIV_265		0x000000E0U
#define RCC_AHB_DIV_512		0x000000F0U

#define RCC_CFGR_PPRE1_Pos	(8U)
#define RCC_CFGR_PPRE1_Msk	(0x7UL << RCC_CFGR_PPRE1_Pos)
#define RCC_APB1_DIV_1		0x00000000U
#define RCC_APB1_DIV_2		0x00000400U
#define RCC_APB1_DIV_4		0x00000500U
#define RCC_APB1_DIV_8		0x00000600U
#define RCC_APB1_DIV_16		0x00000700U

#define RCC_CFGR_PPRE2_Pos	(11U)
#define RCC_CFGR_PPRE2_Msk	(0x7UL << RCC_CFGR_PPRE2_Pos)
#define RCC_APB2_DIV_1		0x00000000U
#define RCC_APB2_DIV_2		0x00002000U
#define RCC_APB2_DIV_4		0x00002800U
#define RCC_APB2_DIV_8		0x00003000U
#define RCC_APB2_DIV_16		0x00003800U

#define RCC_CFGR_PLLMULL_Pos	(18U)
#define RCC_CFGR_PLLMULL_Msk	(0xFUL << RCC_CFGR_PLLMULL_Pos)

#define RCC_CFGR_SWSYSCLK_Pos	(0U)
#define RCC_CFGR_SWSYSCLK_Msk	(0x3UL << RCC_CFGR_SWSYSCLK_Pos)

#define HSE_DIV_1	((uint8_t)0x00)
#define HSE_DIV_2	((uint8_t)0x01)
#define RCC_HSE		0U
#define RCC_HSI		1U

typedef enum
{
	HAL_OK				= 0x00U,
	HAL_ERROR			= 0x01U,
	HAL_BUSY    		= 0x02U,
	HAL_TIMEOUT 		= 0x03U,
	SysClockConfigERROR = 0x04U,
}HAL_Status_t;

typedef enum
{
	RCC_AHB,
	RCC_APB1,
	RCC_APB2,
}BusPrephiral_t;
/******************* Macro Functions Declations for RCC_APB2ENR Resgister ******************/
typedef enum
{
	AFIO =0,
	GPIOA =2,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,
	ADC1,ADC2,
	TIM1,SPI1,TIM8,USART1,ADC3,
	TIM9=19,TIM10,TIM11,
}RCC_APB2ENR_t;
/******************* Macro Functions Declations for RCC_AHBENR Resgister ******************/
typedef enum
{
	DMA1,DMA2,SRAM,FLITF=4,CRC=6,FSMC=8,SDIO=10
}RCC_AHBENR_t;
/******************* Macro Functions Declations for RCC_APB1ENR Resgister ******************/
typedef enum
{
	TIM2,TIM3,TIM4,TIM5,TIM6,TIM7,TIM12,TIM13,TIM14,
	WWDG=11,
	SPI2=14,SPI3,
	USART2=17,USART3,USART4,USART5,
	I2C1,I2C2,
	USB,CAN=25,
	BKP=27,PWR,DAC,
}RCC_APB1ENR_t;

/******************* Macro Functions Declations for RCC_CR Resgister ******************/

#define RCC_CR_HSION_ENABLE()		(RCC->RCC_CR  |= (1 << 0))
#define RCC_CR_HSEON_ENABLE()		(RCC->RCC_CR  |= (1 << 16))
#define RCC_CR_PLLON_ENABLE()		(RCC->RCC_CR  |= (1 << 24))

#define RCC_CR_HSION_DISABLE()		(RCC->RCC_CR  &= ~(1 << 0))
#define RCC_CR_HSEON_DISABLE()		(RCC->RCC_CR  &= ~(1 << 16))
#define RCC_CR_PLLON_DISABLE()		(RCC->RCC_CR  &= ~(1 << 24))

/******************* Macro Functions Declations for RCC_BDCR Resgister ******************/

#define RCC_BDCR_LSEON_ENABLE()		(RCC->RCC_BDCR  |= (1 << 0))
#define RCC_BDCR_LSEON_DISABLE()	(RCC->RCC_BDCR  &= ~(1 << 0))

/******************* Macro Functions Declations for RCC_CSR Resgister ******************/
#define RCC_CSR_LSION_ENABLE()		(RCC->RCC_CSR  |= (1 << 0))
#define RCC_CSR_LSION_DISABLE()		(RCC->RCC_CSR  &= ~(1 << 0))

/******************* Macro Functions Declations for RCC_CFGR Resgister ******************/
#define RCC_CFGR_HSE_DIV_1()		(RCC->RCC_CFGR   &= ~(1 << 17))
#define RCC_CFGR_HSE_DIV_2()		(RCC->RCC_CFGR  |= (1 << 17))
#define RCC_CFGR_PLL_CLKSRC_HSI()	(RCC->RCC_CFGR   &= ~(1 << 16))
#define RCC_CFGR_PLL_CLKSRC_HSE()	(RCC->RCC_CFGR  |= (1 << 16))
typedef enum
{
 RCC_PLLMULL2	=		((uint32_t)0x00000000),
 RCC_PLLMULL3	=		((uint32_t)0x00040000),
 RCC_PLLMULL4	=		((uint32_t)0x00080000),
 RCC_PLLMULL5	=		((uint32_t)0x000C0000),
 RCC_PLLMULL6	=		((uint32_t)0x00100000),
 RCC_PLLMULL7	=		((uint32_t)0x00140000),
 RCC_PLLMULL8	=		((uint32_t)0x00180000),
 RCC_PLLMULL9	=		((uint32_t)0x001C0000),
 RCC_PLLMULL10	=		((uint32_t)0x00200000),
 RCC_PLLMULL11	=		((uint32_t)0x00240000),
 RCC_PLLMULL12	=		((uint32_t)0x00280000),
 RCC_PLLMULL13	=		((uint32_t)0x002C0000),
 RCC_PLLMULL14	=		((uint32_t)0x00300000),
 RCC_PLLMULL15	=		((uint32_t)0x00340000),
 RCC_PLLMULL16	=		((uint32_t)0x00380000),
}RCC_PLLMULL_t;

typedef enum
{
 RCC_HSI_SYSCLK=		((uint32_t)0x00000000),
 RCC_HSE_SYSCLK=		((uint32_t)0x00000001),
 RCC_PLL_SYSCLK=		((uint32_t)0x00000002),
 RCC_NO_SYSCLK=			((uint32_t)0x00000003),
}RCC_SWSYSCLK_t;

/*********************************************************************************/
typedef struct
{
	volatile uint32_t	RCC_CR;
	volatile uint32_t	RCC_CFGR;
	volatile uint32_t	RCC_CIR;
	volatile uint32_t	RCC_APB2RSTR;
	volatile uint32_t	RCC_APB1RSTR;
	volatile uint32_t	RCC_AHBENR;
	volatile uint32_t	RCC_APB2ENR;
	volatile uint32_t	RCC_APB1ENR;
	volatile uint32_t	RCC_BDCR;
	volatile uint32_t	RCC_CSR;
}RCC_Reg_t;


typedef struct
{
	uint32_t OSC_Type;
	uint32_t HSEState;
	uint32_t HSIState;
	uint32_t LSEState;
	uint32_t LSIState;
}RCC_OscInit_t;


typedef struct
{
	uint32_t AHBCLKDivider;
	uint32_t APB1CLKDivider;
	uint32_t APB2CLKDivider;
}RCC_ClkInit_t;

/******************* Software Interface Declarations *******************/

HAL_Status_t RCC_OscConfig(RCC_OscInit_t *RCC_OscInit);
//HAL_Status_t RCC_ClockConfig(RCC_ClkInit_t *RCC_ClkInit);
HAL_Status_t RCC_SetSysClk(RCC_SWSYSCLK_t Clk_type);
HAL_Status_t RCC_HSE_Config(uint8_t HSE_State);
HAL_Status_t RCC_PLL_Config(RCC_PLLMULL_t PLL_MUL,uint8_t PLL_SRC);
HAL_Status_t RCC_EnableClk(BusPrephiral_t BusName,uint8_t Prephiral);
HAL_Status_t RCC_DisableCLK(BusPrephiral_t BusName,uint8_t Prephiral);

#endif /* RCC_STM32F103_RCC_H_ */
