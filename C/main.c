#include <stdio.h>
#include <stdint.h>
#include "mcu_registers.h"
#include "eeprom.h"
#include "adc.h"
#include "led.h"
#include "statemachine.h"


#define INTERRUPT_SIMULATION

#define HW_REV_0 0x00
#define HW_REV_1 0x01

#define HW_SERIAL_NUMBER "ABC1234"

int main() {
    uint8_t hw_rev = 0;

    //Dummy setup for MCU registers
    mcu_mock_registers_init();

    // Dummy setup for EEPROM
    eeprom_mock(HW_REV_0, HW_SERIAL_NUMBER); 

    // Start of main program
    eeprom_init();  
    hw_rev = eeprom_read(EEPROM_HW_REV_ADDR);
    if (hw_rev == 0xFF) {
        printf("[EEPROM] HW-Rev not found, using default value: 0x00\n");
        hw_rev = 0;
    }

    // Initialize peripherals
    led_init();
    adc_init(hw_rev);

    
    // Start Mainloop for Statemachine
    while (1) 
    {
        #ifndef INTERRUPT_SIMULATION
        while (!(ADC_CONFIG_REG & ADC_ISR_CLEAR)); // timer to exit not added
        
        #else
        //Mock Variant 
        while (!(ADC_CONFIG_REG & ADC_ISR_CLEAR)) 
        {
            adc_simulate_interrupt(hw_rev); // Simulate ADC interrupt
        };
        ADC_CONFIG_REG &= ~ADC_ISR_CLEAR; // clear interrupt flag
        #endif

        // Read temp value
        float temp = adc_get_temp(hw_rev);
        printf("[TEMP] %.1f°C\n", temp);

        //apply state machine
        apply_state_machine(temp);
    }

    return 0;
}