#include <stdio.h>
#include <stdlib.h>
#include "adc.h"
#include "mcu_registers.h"

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#endif

// Constants
#define ADC_TEMP_START 4

// Global Variables
volatile uint16_t adc_value = 0;

// Function to initialize the ADC
void adc_init(uint8_t hw_rev) {
    printf("[ADC] INIT for HW-Rev: 0x%02x\n", hw_rev);

    // Initialize Timer
    printf("[ADC-CLOCK] Configure/Enable Clk0\n");
    CLK0_CONFIG_REG |= CLK_FREQ_10KHZ; // Set clock frequency to 10kHz
    CLK0_CONFIG_REG |= CLK_ENABLE;    // Enable clock

    // Select ADC clock
    ADC_CONFIG_REG |= ADC_TRIGGER_CLK_MASK;

    // Configure ADC resolution based on hardware revision
    if (hw_rev == 0) {
        ADC_CONFIG_REG |= ADC_RESOLUTION_10BIT; // 10-bit resolution
    } else {
        ADC_CONFIG_REG &= ADC_RESOLUTION_8BIT_MASK; // 8-bit resolution
    }

    // Enable ADC interrupt and ADC
    printf("[ADC] Enable Interrupt\n");
    printf("[ADC] Enable ADC\n");
    ADC_CONFIG_REG |= ADC_ISR_ENABLE; // Enable ADC interrupt
    ADC_CONFIG_REG |= ADC_ENABLE;     // Enable ADC
}

// Function to get temperature from ADC value
float adc_get_temp(uint8_t hw_rev) {
    float temp_value = 0;

    // Convert ADC value to temperature based on hardware revision
    if (hw_rev == 0) {
        temp_value = (float) adc_value + (float) ADC_TEMP_START; // 8-bit resolution
    } else {
        temp_value = (0.1f * (float) adc_value) + (float)ADC_TEMP_START; // 10-bit resolution
    }

    return temp_value;
}

// ADC interrupt handler (static function)
static void adc_IRQHandler() {
    // Clear interrupt flag
    ADC_CONFIG_REG |= ADC_ISR_CLEAR;

    // Read ADC value from high and low registers
    adc_value = ADC_VAL_REG_HIGH << 8 | ADC_VAL_REG_LOW;

    // Print ADC value for debugging
    printf("\n[ADC-IRQ] Interrupt called. ADC value: %i\n", adc_value);
}

// Function to simulate an ADC interrupt (for testing purposes)
void adc_simulate_interrupt(uint8_t hw_rev) {
    sleep(1); // Simulate delay

    // Generate a mock ADC value based on hardware revision
    uint16_t mock_adc_value = 0;
    if (hw_rev == 0) {
        mock_adc_value = rand() % 256; // Mock 8-bit ADC value
    } else {
        mock_adc_value = rand() % 1024; // Mock 10-bit ADC value
    }

    // Simulate ADC interrupt
    ADC_CONFIG_REG |= ADC_ISR_CLEAR; // Set interrupt flag
    ADC_VAL_REG_HIGH = (0xFF00 & mock_adc_value) >> 8; // Mock high byte
    ADC_VAL_REG_LOW = 0x00FF & mock_adc_value;         // Mock low byte
    adc_IRQHandler(); // Call the ADC interrupt handler
}