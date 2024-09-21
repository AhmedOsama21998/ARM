# STM32F103 GPIO Driver

## Overview

This repository contains the GPIO driver for the STM32F103 microcontroller, part of the ARM Cortex-M3 series. The driver allows users to configure and control the GPIO (General Purpose Input/Output) pins and Alternate Function Input/Output (AFIO) functionalities.

## Features

- **Pin Initialization**: Supports configuration of GPIO pins in various modes (input, output, alternate function) with control over speed and resistor settings (pull-up/pull-down).
- **Pin Control**: Functions to write to, toggle, and read from GPIO pins.
- **AFIO Configuration**: Enables configuration of alternate functions for advanced pin multiplexing.

## Functions Description

### GPIO Initialization
- **`GPIO_PinInit`**: Initializes GPIO pins based on the `PinConfig_t` structure, setting the mode, type, and speed.

### GPIO Pin Operations
- **`GPIO_WritePin`**: Writes a high or low state to a specific GPIO pin.
- **`GPIO_TogglePin`**: Toggles the state of a specific GPIO pin.
- **`GPIO_ReadPin`**: Reads the current state of a specific GPIO pin.

### AFIO Control
- **`AFIO_ENR`**: Enables or disables alternate functions on specific GPIO pins.
- **`AFIO_EXTRICR`**: Configures external interrupt settings for GPIO pins using AFIO.

## Usage Example

```c
PinConfig_t pinConfig = {
    .Port = PORTA,
    .PinNum = PIN0,
    .Mode.ModeType = OutputMode,
    .Mode.OutputMode_t = OUTPUT_GP_PUSHPULL,
    .Mode.OutputSpeed_t = OUTPUT_SPEED_10MHZ
};

GPIO_PinInit(&pinConfig);  // Initialize PA0 as an output pin
GPIO_WritePin(PORTA, PIN0, PIN_HIGH);  // Set PA0 to high
