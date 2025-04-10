#include <stdio.h>
#include "gpio.h"
#include "mcu_registers.h"

// Define error return value
#define RETURN_ERROR 1

// Function to initialize a GPIO pin
void gpio_init_pin(GPIO gpio) 
{
    switch(gpio) {
        case GPIO_0:
            // Configure GPIO_0 as output and enable it
            GPIO_REG_0 &= GPIO_FUNC_MASK; // Clear function bits
            GPIO_REG_0 |= GPIO_ENABLE | GPIO_OUTPUT; // Set as output and enable
            printf("[LED-GPIO] GPIO functionality enabled at register address 0x%x\n", 
                   (uint8_t) (&GPIO_REG_0 - mock_mcu_registers));
            break;
        case GPIO_1:
            // Configure GPIO_1 as output and enable it
            GPIO_REG_1 &= GPIO_FUNC_MASK; // Clear function bits
            GPIO_REG_1 |= GPIO_ENABLE | GPIO_OUTPUT; // Set as output and enable
            printf("[LED-GPIO] GPIO functionality enabled at register address 0x%x\n", 
                   (uint8_t) (&GPIO_REG_1 - mock_mcu_registers));
            break;
        case GPIO_2:
            // Configure GPIO_2 as output and enable it
            GPIO_REG_2 &= GPIO_FUNC_MASK; // Clear function bits
            GPIO_REG_2 |= GPIO_ENABLE | GPIO_OUTPUT; // Set as output and enable
            printf("[LED-GPIO] GPIO functionality enabled at register address 0x%x\n", 
                   (uint8_t) (&GPIO_REG_2 - mock_mcu_registers));
            break;
        default:
            // Handle invalid GPIO number
            printf("[LED-GPIO] Invalid GPIO number\n");
            break;
    }
}

// Function to set a GPIO pin to HIGH
uint8_t gpio_set_pin(GPIO gpio) {
    switch (gpio) {
        case GPIO_0:
            // Set GPIO_0 to HIGH
            GPIO_REG_0 |= GPIO_SET;
            printf("[LED-GPIO] GPIO at address 0x%X set to HIGH\n", 
                   (uint8_t) (&GPIO_REG_0 - mock_mcu_registers));
            break;
        case GPIO_1:
            // Set GPIO_1 to HIGH
            GPIO_REG_1 |= GPIO_SET;
            printf("[LED-GPIO] GPIO at address 0x%X set to HIGH\n", 
                   (uint8_t) (&GPIO_REG_1 - mock_mcu_registers));
            break;
        case GPIO_2:
            // Set GPIO_2 to HIGH
            GPIO_REG_2 |= GPIO_SET;
            printf("[LED-GPIO] GPIO at address 0x%X set to HIGH\n", 
                   (uint8_t) (&GPIO_REG_2 - mock_mcu_registers));
            break;
        default:
            // Handle invalid GPIO number
            printf("[LED-GPIO] Invalid GPIO number\n");
            return RETURN_ERROR;
    }
    return 0;
}

// Function to reset a GPIO pin to LOW
uint8_t gpio_reset_pin(GPIO gpio) {
    switch (gpio) {
        case GPIO_0:
            // Reset GPIO_0 to LOW
            GPIO_REG_0 &= GPIO_RESET;
            printf("[LED-GPIO] GPIO at address 0x%X set to LOW\n", 
                   (uint8_t) (&GPIO_REG_0 - mock_mcu_registers));
            break;
        case GPIO_1:
            // Reset GPIO_1 to LOW
            GPIO_REG_1 &= GPIO_RESET;
            printf("[LED-GPIO] GPIO at address 0x%X set to LOW\n", 
                   (uint8_t) (&GPIO_REG_1 - mock_mcu_registers));
            break;
        case GPIO_2:
            // Reset GPIO_2 to LOW
            GPIO_REG_2 &= GPIO_RESET;
            printf("[LED-GPIO] GPIO at address 0x%X set to LOW\n", 
                   (uint8_t) (&GPIO_REG_2 - mock_mcu_registers));
            break;
        default:
            // Handle invalid GPIO number
            printf("[LED-GPIO] Invalid GPIO number\n");
            return RETURN_ERROR;
    }
    return 0;
}