# STM32F103 NVIC Driver

This repository contains the NVIC (Nested Vectored Interrupt Controller) driver for the STM32F103 microcontroller. The driver provides essential functions to manage interrupts in the STM32F103 Cortex-M3-based microcontroller.

## Features

- Enable and disable IRQs.
- Set and clear pending interrupts.
- Get the active status of IRQs.
- Set IRQ priorities.
- Configure priority grouping.

## Functions

### 1. `ErrorStatus_t NVIC_EnableIRQ(IRQn_Type IRQn)`

**Description:**  
Enables the interrupt for a specified IRQ number.

**Parameters:**  
- `IRQn`: The IRQ number to enable (of type `IRQn_Type`).

**Returns:**  
- `OK`: Successfully enabled the IRQ.
- `ERROR`: Failed to enable the IRQ due to invalid input.

---

### 2. `ErrorStatus_t NVIC_DisableIRQ(IRQn_Type IRQn)`

**Description:**  
Disables the interrupt for a specified IRQ number.

**Parameters:**  
- `IRQn`: The IRQ number to disable (of type `IRQn_Type`).

**Returns:**  
- `OK`: Successfully disabled the IRQ.
- `ERROR`: Failed to disable the IRQ due to invalid input.

---

### 3. `ErrorStatus_t NVIC_SetPendingIRQ(IRQn_Type IRQn)`

**Description:**  
Sets the pending flag for the specified IRQ number.

**Parameters:**  
- `IRQn`: The IRQ number for which the pending flag is to be set (of type `IRQn_Type`).

**Returns:**  
- `OK`: Successfully set the pending flag.
- `ERROR`: Failed to set the pending flag due to invalid input.

---

### 4. `ErrorStatus_t NVIC_ClearPendingIRQ(IRQn_Type IRQn)`

**Description:**  
Clears the pending flag for the specified IRQ number.

**Parameters:**  
- `IRQn`: The IRQ number for which the pending flag is to be cleared (of type `IRQn_Type`).

**Returns:**  
- `OK`: Successfully cleared the pending flag.
- `ERROR`: Failed to clear the pending flag due to invalid input.

---

### 5. `ErrorStatus_t NVIC_GetActiveFlag(IRQn_Type IRQn, uint8_t *FlagStatus)`

**Description:**  
Gets the active flag for the specified IRQ number.

**Parameters:**  
- `IRQn`: The IRQ number to check for active status (of type `IRQn_Type`).
- `FlagStatus`: A pointer to store the active status (1 if active, 0 otherwise).

**Returns:**  
- `OK`: Successfully retrieved the active status.
- `ERROR`: Failed to retrieve the active status due to invalid input.
- `NULL_PTR`: The provided pointer was null.

---

### 6. `ErrorStatus_t NVIC_SetPriority(IRQn_Type IRQn, uint8_t priority)`

**Description:**  
Sets the priority for the specified IRQ number.

**Parameters:**  
- `IRQn`: The IRQ number to set the priority for (of type `IRQn_Type`).
- `priority`: The priority level (0-15).

**Returns:**  
- `OK`: Successfully set the priority.
- `ERROR`: Failed to set the priority due to invalid input.

---

### 7. `ErrorStatus_t NVIC_SetPriorityGrouping(PriGp_t priority_grouping)`

**Description:**  
Sets the priority grouping of the interrupts.

**Parameters:**  
- `priority_grouping`: The priority grouping value (of type `PriGp_t`).

**Returns:**  
- `OK`: Successfully set the priority grouping.
- `ERROR`: Failed to set the priority grouping due to invalid input.

## Files

- **STM32f103_NVIC.c**: Source code for the NVIC driver implementation.
- **STM32f103_NVIC.h**: Header file containing function declarations and macros.

## Usage

To use the NVIC driver, include the `STM32f103_NVIC.h` file in your project and link the `STM32f103_NVIC.c` file during compilation.

## Future Work

- Advanced error handling for invalid IRQ numbers.
- Implement priority level checking.
- Add support for custom interrupt handlers.

## Author

**Ahmed Osama**  
Biomedical Engineer & Embedded Systems Developer

Stay tuned for more driver updates!
