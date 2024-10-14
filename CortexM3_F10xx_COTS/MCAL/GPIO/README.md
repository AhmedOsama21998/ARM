# STM32F103 GPIO Driver

This directory contains the GPIO (General Purpose Input/Output) driver for the STM32F103 Cortex-M3 microcontroller. The driver provides functions for configuring and managing the GPIO ports and pins for input/output operations, setting pin values, reading pin states, and configuring the direction of pins.

## Features

- Configure GPIO pins as input or output.
- Set or read the value of specific pins.
- Set or read the value of entire GPIO ports.
- Error handling and status reporting for invalid parameters.
- Support for setting specific pins within a port without affecting others.

## Functions

### `ErrorStatus_t GPIO_InitPin(Port_t Port, Pin_t Pin, PinMode_t Mode)`

- **Description**: Initializes a specific pin with a specified mode (input/output).
- **Parameters**:
  - `Port`: Specifies the port (e.g., PORTA, PORTB).
  - `Pin`: The pin number to configure.
  - `Mode`: The mode of the pin (input, output, pull-up, pull-down, etc.).
- **Returns**: `ErrorStatus_t` (OK or ERROR).

### `ErrorStatus_t GPIO_SetPinValue(Port_t Port, Pin_t Pin, PinState_t State)`

- **Description**: Sets the value (HIGH or LOW) of a specific pin.
- **Parameters**:
  - `Port`: The port of the pin (e.g., PORTA, PORTB).
  - `Pin`: The pin number to set the value for.
  - `State`: The state to set (HIGH or LOW).
- **Returns**: `ErrorStatus_t` (OK or ERROR).

### `PinState_t GPIO_GetPinValue(Port_t Port, Pin_t Pin)`

- **Description**: Reads the current value of a specific pin.
- **Parameters**:
  - `Port`: The port of the pin (e.g., PORTA, PORTB).
  - `Pin`: The pin number to read.
- **Returns**: `PinState_t` (HIGH or LOW).

### `ErrorStatus_t GPIO_SetPortValue(Port_t Port, uint32_t Value)`

- **Description**: Sets the value of an entire port.
- **Parameters**:
  - `Port`: The port to set the value for (e.g., PORTA, PORTB).
  - `Value`: The 32-bit value to assign to the port.
- **Returns**: `ErrorStatus_t` (OK or ERROR).

### `ErrorStatus_t GPIO_SetPortDirection(Port_t Port, uint32_t PinMask, PinMode_t Mode)`

- **Description**: Configures the direction (input/output) of multiple pins in a port.
- **Parameters**:
  - `Port`: The port of the pins (e.g., PORTA, PORTB).
  - `PinMask`: A bitmask representing the pins to configure.
  - `Mode`: The mode for the selected pins (input, output, etc.).
- **Returns**: `ErrorStatus_t` (OK or ERROR).

### `ErrorStatus_t GPIO_SetSpecificPinValue(Port_t Port, Pin_t StartPin, uint32_t Value, uint8_t PinCount)`

- **Description**: Sets the value for a specific range of pins in a port.
- **Parameters**:
  - `Port`: The port containing the pins (e.g., PORTA, PORTB).
  - `StartPin`: The starting pin in the range.
  - `Value`: The value to assign to the range of pins.
  - `PinCount`: The number of pins to modify, starting from `StartPin`.
- **Returns**: `ErrorStatus_t` (OK or ERROR).

---

## Usage Example

```c
// Initialize a pin as output
GPIO_InitPin(PORTA, PIN0, OUTPUT_MODE);

// Set the pin value to HIGH
GPIO_SetPinValue(PORTA, PIN0, HIGH);

// Read the pin value
PinState_t pinState = GPIO_GetPinValue(PORTA, PIN0);

// Set the value for an entire port
GPIO_SetPortValue(PORTB, 0xFFFF);

// Configure the direction of multiple pins in a port
GPIO_SetPortDirection(PORTC, 0x0F, OUTPUT_MODE);
