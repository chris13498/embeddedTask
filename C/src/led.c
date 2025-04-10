#include <stdio.h>
#include "led.h"
#include "gpio.h"

// Define constants
#define RETURN_ERROR 1

// Initialize LED pins
void led_init() {
    printf("[LED] INIT\n");
    gpio_init_pin(LED_RED);
    gpio_init_pin(LED_YELLOW);
    gpio_init_pin(LED_GREEN);
}

// Turn off all LEDs
void led_off_all() {
    gpio_reset_pin(LED_RED);
    gpio_reset_pin(LED_YELLOW);
    gpio_reset_pin(LED_GREEN);
}

// Focus on a specific LED
uint8_t led_focus(LED led) {
    led_off_all(); // Ensure all LEDs are off
    switch (led) {
        case LED_RED:
            gpio_set_pin(LED_RED); // Turn on red LED
            break;
        case LED_YELLOW:
            gpio_set_pin(LED_YELLOW); // Turn on yellow LED
            break;
        case LED_GREEN:
            gpio_set_pin(LED_GREEN); // Turn on green LED
            break;
        default:
            printf("[LED] Invalid LED\n"); // Handle invalid input
            return RETURN_ERROR;
    }
    return 0; // Success
}