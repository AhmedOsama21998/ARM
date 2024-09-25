/*
 * STM32f103_RCC.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Ahmed Osama
 */
#include "STM32f103_RCC.h"
ErrorStatus_t RCC_OscConfig(RCC_OscInit_t *RCC_OscInit)
{
	ErrorStatus_t status = OK;
	if(NULL == RCC_OscInit)
	{
		status = ERROR;
	}
	else
	{
		/******************** HSE Config ****************************/
		 if(RCC_OSCTYPE_HSE == RCC_OscInit->OSC_Type)
		 {
			 if(RCC_HSE_ON == RCC_OscInit->HSEState)
			 {
				 RCC_CR_HSEON_ENABLE();
			 }else if(RCC_HSE_OFF == RCC_OscInit->HSEState)
			 {
				 RCC_CR_HSEON_DISABLE();
			 }
		/******************** HSI Config ****************************/
		 }else if(RCC_OSCTYPE_HSI == RCC_OscInit->OSC_Type)
		 {
			 if(RCC_HSI_ON == RCC_OscInit->HSIState)
			 {
				 RCC_CR_HSION_ENABLE();
			 }else if(RCC_HSI_OFF == RCC_OscInit->HSIState)
			 {
				 RCC_CR_HSION_DISABLE();
			 }
		/******************** LSE Config ****************************/
		 }else if(RCC_OSCTYPE_LSE == RCC_OscInit->OSC_Type)
		 {
			 if(RCC_LSE_ON == RCC_OscInit->LSEState)
			 {
				 RCC_BDCR_LSEON_ENABLE();
			 }else if(RCC_LSE_OFF == RCC_OscInit->LSEState)
			 {
				 RCC_BDCR_LSEON_DISABLE();
			 }
		/******************** LSI Config ****************************/
		 }else if(RCC_OSCTYPE_LSI == RCC_OscInit->OSC_Type)
		 {
			 if(RCC_LSI_ON == RCC_OscInit->LSIState)
			 {
				 RCC_CSR_LSION_ENABLE();
			 }else if(RCC_LSE_OFF == RCC_OscInit->LSIState)
			 {
				 RCC_CSR_LSION_DISABLE();
			 }
		 }else{status = ERROR;/*Nothing*/}
	}
	return status;
}

ErrorStatus_t RCC_SetSysClk(RCC_SWSYSCLK_t Clk_type)
{
	ErrorStatus_t status = OK;
	switch (Clk_type)
	{
		case RCC_HSI_SYSCLK:
			RCC->RCC_CFGR &= ~RCC_CFGR_SWSYSCLK_Msk;
			RCC->RCC_CFGR |= Clk_type;
			break;
		case RCC_HSE_SYSCLK:
			RCC->RCC_CFGR &= ~RCC_CFGR_SWSYSCLK_Msk;
			RCC->RCC_CFGR |= Clk_type;
			break;
		case RCC_PLL_SYSCLK:
			RCC->RCC_CFGR &= ~RCC_CFGR_SWSYSCLK_Msk;
			RCC->RCC_CFGR |= Clk_type;
			break;
		case RCC_NO_SYSCLK:
			RCC->RCC_CFGR &= ~RCC_CFGR_SWSYSCLK_Msk;
			RCC->RCC_CFGR |= Clk_type;
			break;
		default:
			status = ERROR;
			break;
	 }
	return status;
}
ErrorStatus_t RCC_PLL_Config(RCC_PLLMULL_t PLL_MUL,uint8_t PLL_SRC)
{
	ErrorStatus_t status = OK;

	switch (PLL_SRC)
	{
	case RCC_HSE:
		RCC_CFGR_PLL_CLKSRC_HSE();
		break;
	case RCC_HSI:
		RCC_CFGR_PLL_CLKSRC_HSI();
		break;
	default:
		status = ERROR;
		break;
	}
	RCC->RCC_CFGR &=   ~RCC_CFGR_PLLMULL_Msk;
	RCC->RCC_CFGR |=	PLL_MUL;
return status;
}

ErrorStatus_t RCC_HSE_Config(uint8_t HSE_State)
{
	ErrorStatus_t status = OK;
	if(3 == HSE_State)
	{
		status = ERROR;
	}else
	{
		switch (HSE_State)
		{
		case HSE_DIV_1:
			RCC_CFGR_HSE_DIV_1();
			break;
		case HSE_DIV_2:
			RCC_CFGR_HSE_DIV_2();
			break;
		default:
			status = ERROR;
			break;
		}
	 }
	return status;
}

/*
ErrorStatus_t RCC_ClockConfig(RCC_ClkInit_t *RCC_ClkInit)
{
	ErrorStatus_t status = OK;
	if(NULL == RCC_ClkInit)
	{
		status = ERROR;
	}
	else
	{
		MODIFY_REG(RCC->RCC_CFGR,RCC_CFGR_HPRE_Msk,RCC_ClkInit->AHBCLKDivider);
		MODIFY_REG(RCC->RCC_CFGR,RCC_CFGR_PPRE1_Msk,RCC_ClkInit->APB1CLKDivider);
		MODIFY_REG(RCC->RCC_CFGR,RCC_CFGR_PPRE2_Msk,RCC_ClkInit->APB2CLKDivider);
	}
	return status;
}
*/
ErrorStatus_t RCC_EnableClk(BusPrephiral_t BusName,uint8_t Prephiral)
{
	ErrorStatus_t status = OK;
	if(-1 == Prephiral)
	{
		status = ERROR;
	}else
	{
        switch(BusName)
        {
            case RCC_AHB:
            	RCC->RCC_AHBENR   |= (1 << Prephiral);
                break;
            case RCC_APB1:
            	RCC->RCC_APB1ENR  |= (1 << Prephiral);
                break;
            case RCC_APB2:
            	RCC->RCC_APB2ENR  |= (1 << Prephiral);
                break;
            default:
            	status = ERROR;
                break;
        }
	}
	return status;
}
ErrorStatus_t RCC_DisableCLK(BusPrephiral_t BusName,RCC_AHBENR_t Prephiral)
{
	ErrorStatus_t status = OK;
	if(-1 == Prephiral)
	{
		status = ERROR;
	}else
	{
        switch(BusName)
        {
            case RCC_AHB:
            	RCC->RCC_AHBENR  &= ~(1 << Prephiral);
                break;
            case RCC_APB1:
            	RCC->RCC_APB1ENR &= ~(1 << Prephiral);
                break;
            case RCC_APB2:
            	RCC->RCC_APB2ENR &= ~(1 << Prephiral);
                break;
            default:
            	status = ERROR;
                break;
        }
	}
	return status;
}
