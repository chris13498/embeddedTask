#ifndef ADC_H
#define ADC_H
#include <stdint.h>

void adc_init(uint8_t hv_rev);
float adc_get_temp(uint8_t hw_rev);
void adc_simulate_interrupt(uint8_t hw_rev);
static void adc_IRQHandler();

#endif