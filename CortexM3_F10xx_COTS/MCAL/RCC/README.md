# STM32F103 RCC Driver

## Overview

This repository contains a set of drivers for configuring and managing the Reset and Clock Control (RCC) peripheral of the STM32F103 microcontroller. The drivers include functions for configuring oscillators, setting system clock sources, enabling and disabling peripheral clocks, and configuring PLL and HSE dividers.

## Features

- **Oscillator Configuration:**
  - Configure High-Speed External (HSE), High-Speed Internal (HSI), Low-Speed External (LSE), and Low-Speed Internal (LSI) oscillators.
  
- **System Clock Source:**
  - Select system clock source (HSI, HSE, PLL, or none).

- **PLL Configuration:**
  - Set PLL source and multiplication factor.

- **HSE Divider Configuration:**
  - Configure HSE clock divider.

- **Peripheral Clock Management:**
  - Enable and disable peripheral clocks for AHB, APB1, and APB2 buses.

## Files

- `STM32f103_RCC.h`: Header file with definitions and function prototypes.
- `STM32f103_RCC.c`: Source file with implementations of RCC configuration functions.

## Functions

### `HAL_Status_t RCC_OscConfig(RCC_OscInit_t *RCC_OscInit)`

Configures system oscillators based on the provided `RCC_OscInit` structure. 

**Parameters:**
- `RCC_OscInit`: Pointer to a structure containing oscillator configuration settings.

**Returns:**
- `HAL_OK` if successful.
- `HAL_ERROR` if there is an error.

### `HAL_Status_t RCC_SetSysClk(RCC_SWSYSCLK_t Clk_type)`

Sets the system clock source.

**Parameters:**
- `Clk_type`: The clock source to set (HSI, HSE, PLL, or none).

**Returns:**
- `HAL_OK` if successful.
- `HAL_ERROR` if there is an error.

### `HAL_Status_t RCC_PLL_Config(RCC_PLLMULL_t PLL_MUL, uint8_t PLL_SRC)`

Configures the PLL settings.

**Parameters:**
- `PLL_MUL`: PLL multiplication factor.
- `PLL_SRC`: PLL source (HSE or HSI).

**Returns:**
- `HAL_OK` if successful.
- `HAL_ERROR` if there is an error.

### `HAL_Status_t RCC_HSE_Config(uint8_t HSE_State)`

Configures the HSE divider.

**Parameters:**
- `HSE_State`: Divider setting (e.g., HSE_DIV_1 or HSE_DIV_2).

**Returns:**
- `HAL_OK` if successful.
- `HAL_ERROR` if there is an error.

### `HAL_Status_t RCC_EnableClk(BusPrephiral_t BusName, uint8_t Prephiral)`

Enables the clock for a specified peripheral.

**Parameters:**
- `BusName`: The bus to enable (AHB, APB1, or APB2).
- `Prephiral`: The peripheral to enable.

**Returns:**
- `HAL_OK` if successful.
- `HAL_ERROR` if there is an error.

### `HAL_Status_t RCC_DisableCLK(BusPrephiral_t BusName, uint8_t Prephiral)`

Disables the clock for a specified peripheral.

**Parameters:**
- `BusName`: The bus to disable (AHB, APB1, or APB2).
- `Prephiral`: The peripheral to disable.

**Returns:**
- `HAL_OK` if successful.
- `HAL_ERROR` if there is an error.

## Usage

1. **Include Header File:**
   ```c
   #include "STM32f103_RCC.h"
