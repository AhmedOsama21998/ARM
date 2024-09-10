# ARM
# ARM
RCC Driver for STM32F103C8T6
Overview
This repository contains a driver for the Reset and Clock Control (RCC) of the STM32F103C8T6 microcontroller. The RCC driver provides functions to manage the reset and clock configurations of the microcontroller.

Files
rcc.c: Contains the implementation of RCC functions.
rcc.h: Contains the header file with function prototypes and necessary includes.
Functions
void RCC_Init(void)
Initializes the RCC with default settings.

Example Usage
c
Copy code
#include "rcc.h"

int main(void) {
    RCC_Init();
    // Your application code
}
void RCC_EnableClock(uint32_t peripheral)
Enables the clock for a specified peripheral.

Parameters:
peripheral: The peripheral for which to enable the clock. (e.g., RCC_APB2Periph_GPIOA)
Example Usage
c
Copy code
#include "rcc.h"

int main(void) {
    RCC_Init();
    RCC_EnableClock(RCC_APB2Periph_GPIOA);
    // Your application code
}
void RCC_DisableClock(uint32_t peripheral)
Disables the clock for a specified peripheral.

Parameters:
peripheral: The peripheral for which to disable the clock. (e.g., RCC_APB2Periph_GPIOA)
Example Usage
c
Copy code
#include "rcc.h"

int main(void) {
    RCC_Init();
    RCC_EnableClock(RCC_APB2Periph_GPIOA);
    // Your application code
    RCC_DisableClock(RCC_APB2Periph_GPIOA);
}
void RCC_Reset(void)
Performs a system reset.

Example Usage
c
Copy code
#include "rcc.h"

int main(void) {
    RCC_Init();
    // Your application code
    RCC_Reset();
    while (1) {
        // Loop forever
    }
}
