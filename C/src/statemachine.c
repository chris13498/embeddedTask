#include "statemachine.h"
#include <stdio.h>
#include <stdint.h>
#include "mcu_registers.h"
#include "led.h"

// Global variable to track the current state of the machine
volatile uint8_t machine_state = STATE_INIT;

// Function to apply the state machine logic based on temperature input
void apply_state_machine(float temp) {
    static uint8_t previous_state = STATE_INIT; // Tracks the previous state
    uint8_t led_state = 0; // Tracks the LED state change result

    // Determine the machine state based on temperature thresholds
    if (temp < TEMP_CRIT_LOW_C) {
        machine_state = STATE_CRITICAL_LEVEL;
    } else if (temp >= TEMP_CRIT_LOW_C && temp < TEMP_WARN_C) {
        machine_state = STATE_OPERATION_LEVEL;
    } else if (temp >= TEMP_WARN_C && temp < TEMP_CRIT_HIGH_C) {
        machine_state = STATE_WARNING_LEVEL;
    } else {
        machine_state = STATE_CRITICAL_LEVEL;     
    }

    // Check if the state has changed
    if (machine_state != previous_state) {
        // Handle state transitions
        switch (machine_state) {
            case STATE_INIT:
                printf("[STATESWITCH] INIT\n");
                break;
            case STATE_OPERATION_LEVEL:
                printf("[STATESWITCH] OPERATION LEVEL\n");
                led_state = led_focus(LED_GREEN);
                break;
            case STATE_WARNING_LEVEL:
                printf("[STATESWITCH] WARNING LEVEL\n");
                led_state = led_focus(LED_YELLOW);
                break;
            case STATE_CRITICAL_LEVEL:
                printf("[STATESWITCH] CRITICAL LEVEL\n");
                led_state = led_focus(LED_RED);
                break;
        }

        // Log the result of the LED state change
        if (!led_state) {
            printf("[LED] LED state changed successfully\n");
        } else {
            printf("[LED] Failed to change LED state\n");
        }

        // Update the previous state
        previous_state = machine_state;
    }
}