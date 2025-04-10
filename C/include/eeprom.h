#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

void     eeprom_init();
uint8_t  eeprom_read(uint8_t addr);
void     eeprom_write(uint8_t addr, uint8_t value);
void     eeprom_mock(uint8_t revision, const char* serial);

#endif