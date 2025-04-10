#ifndef LED_H
#define LED_H

#include "mcu_registers.h"

void led_init();
uint8_t led_focus(LED led);
void led_off_all();

#endif