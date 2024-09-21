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
- **`AFIO_EXTRICR`**: Configures external interrupt settings for GPIO pins using AFIO

### GPIO Initialization

#### `GPIO_PinInit`
Initializes GPIO pins based on the provided configuration.

**Parameters:**
- `PinConfig_t *pinConfig`: Pointer to a structure that defines the GPIO pin configuration, including port, pin number, mode, output type, and speed.

**Returns:**
- `HAL_Status_t`: Status of the initialization, either `HAL_OK` or `HAL_ERROR`.

### GPIO Pin Operations

#### `GPIO_WritePin`
Writes a high or low state to a specific GPIO pin.

**Parameters:**
- `GPIO_Port_t port`: The port to which the pin belongs (e.g., `PORTA`, `PORTB`).
- `GPIO_Pin_t pin`: The pin number to write to (e.g., `PIN0`, `PIN1`).
- `GPIO_PinState_t state`: The desired state for the pin (`PIN_HIGH` or `PIN_LOW`).

**Returns:**
- `HAL_Status_t`: Status of the operation, either `HAL_OK` or `HAL_ERROR`.

#### `GPIO_TogglePin`
Toggles the state of a specific GPIO pin.

**Parameters:**
- `GPIO_Port_t port`: The port to which the pin belongs (e.g., `PORTA`, `PORTB`).
- `GPIO_Pin_t pin`: The pin number to toggle (e.g., `PIN0`, `PIN1`).

**Returns:**
- `HAL_Status_t`: Status of the operation, either `HAL_OK` or `HAL_ERROR`.

#### `GPIO_ReadPin`
Reads the current state of a specific GPIO pin.

**Parameters:**
- `GPIO_Port_t port`: The port to which the pin belongs (e.g., `PORTA`, `PORTB`).
- `GPIO_Pin_t pin`: The pin number to read (e.g., `PIN0`, `PIN1`).

**Returns:**
- `GPIO_PinState_t`: The current state of the pin (`PIN_HIGH` or `PIN_LOW`).

### AFIO Control

#### `AFIO_ENR`
Enables or disables alternate functions on specific GPIO pins.

**Parameters:**
- `uint8_t AFIO_State`: The state of the AFIO (`AFIO_ENABLE` or `AFIO_DISABLE`).

**Returns:**
- `HAL_Status_t`: Status of the operation, either `HAL_OK` or `HAL_ERROR`.

#### `AFIO_EXTICR`
Configures external interrupt settings for GPIO pins using AFIO.

**Parameters:**
- `GPIO_Port_t port`: The port to which the pin belongs (e.g., `PORTA`, `PORTB`).
- `GPIO_Pin_t pin`: The pin number to configure (e.g., `PIN0`, `PIN1`).
- `EXTI_TriggerType_t triggerType`: The type of external interrupt trigger (`EXTI_FALLING`, `EXTI_RISING`, `EXTI_BOTH`).

**Returns:**
- `HAL_Status_t`: Status of the operation, either `HAL_OK` or `HAL_ERROR`.

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
