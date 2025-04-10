#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "mcu_registers.h"

void gpio_init_pin(GPIO gpio);
uint8_t gpio_set_pin(GPIO gpio);
uint8_t gpio_reset_pin(GPIO gpio);

#endif