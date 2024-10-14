/*
 * STM32f103_NVIC.h
 *
 *  Created on: Oct 11, 2024
 *      Author: Ahmed Osama
 */

#ifndef NVIC_STM32F103_NVIC_H_
#define NVIC_STM32F103_NVIC_H_

#include "../LIB/Std_Types.h"

#define NVIC				((NVIC_Reg_t *)0xE000E100UL)
#define SCB_AIRCR			*((volatile uint32_t *)0xE000ED0C)



typedef enum
{
	 _16Gp_0Sub  	= 0x05FA0300,
	 _8Gp_2Sub   	= 0x05FA0400,
	 _4GP_4SUB		= 0x05FA0500,
	 _2Gp_8Sub   	= 0x05FA0600,
	 _0Gp_16Sub  	= 0x05FA0700
}PriGp_t;


typedef enum
{
	NVIC_WWDG,
	NVIC_PVD,
	NVIC_TAMPER,
	NVIC_RTC,
	NVIC_FLASH,
	NVIC_RCC,
	NVIC_EXTI0,NVIC_EXTI1,NVIC_EXTI2,NVIC_EXTI3,NVIC_EXTI4,
	NVIC_DMA1_Ch1,NVIC_DMA1_Ch2,NVIC_DMA1_Ch3,NVIC_DMA1_Ch4,NVIC_DMA1_Ch5,NVIC_DMA_Ch6,NVIC_DMA_Ch7,
	NVIC_ADC1_2,
	NVIC_USB_HP_CAN_TX ,
	NVIC_USB_LP_CAN_RX0,
	NVIC_CAN_RX1,
	NVIC_CAN_SCE,
	NVIC_EXTI9_5,
	NVIC_TIM1_BRK,NVIC_TIM1_UP,NVIC_TIM1_TRG_COM,NVIC_TIM1_CC,
	NVIC_TIM2,NVIC_TIM3,NVIC_TIM4,
	NVIC_I2C1_EV,NVIC_I2C1_ER,
	NVIC_I2C2_EV,NVIC_I2C2_ER,
	NVIC_SPI1,NVIC_SPI2,
	NVIC_USART1,NVIC_USART2,NVIC_USART3,
	NVIC_EXTI15_10,
	NVIC_RTCAlarm,
	NVIC_USBWakeup,
	NVIC_TIM8_BRK,NVIC_TIM8_UP,NVIC_TIM8_TRG_COM,NVIC_TIM8_CC,
	NVIC_ADC3,
	NVIC_FSMC,
	NVIC_SDIO,
	NVIC_TIM5,
	NVIC_SPI3,
	NVIC_UART4,NVIC_UART5,
	NVIC_TIM6,NVIC_TIM7,
	NVIC_DMA2_Ch1,NVIC_DMA2_Ch2,NVIC_DMA2_Ch3,NVIC_DMA2_Ch4_5,
}IRQn_Type;

typedef struct
{
	volatile uint32_t	ISER[8];
	volatile uint32_t	Res1[24];

	volatile uint32_t	ICER[8];
	volatile uint32_t	Res2[24];

	volatile uint32_t	ISPR[8];
	volatile uint32_t	Res3[24];

	volatile uint32_t	ICPR[8];
	volatile uint32_t	Res4[24];

	volatile uint32_t	IABR[8];
	volatile uint32_t	Res5[56];

	volatile uint8_t	IPR[240];
	volatile uint32_t	Res6[644];

	volatile uint32_t	STIR;

}NVIC_Reg_t;


ErrorStatus_t NVIC_EnableIRQ(IRQn_Type IRQn);
ErrorStatus_t NVIC_DisableIRQ(IRQn_Type IRQn);
ErrorStatus_t NVIC_SetPendingIRQ(IRQn_Type IRQn);
ErrorStatus_t NVIC_ClearPendingIRQ(IRQn_Type IRQn);
ErrorStatus_t NVIC_GetActiveFlag(IRQn_Type IRQn , uint8_t * FlagStatus);

ErrorStatus_t NVIC_SetPriorityGrouping(PriGp_t priority_grouping);

ErrorStatus_t NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority);
ErrorStatus_t NVIC_GetPriority(IRQn_Type IRQn, uint32_t *Priority);


#endif /* NVIC_STM32F103_NVIC_H_ */
