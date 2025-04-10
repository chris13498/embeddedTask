#include <stdio.h>
#include <string.h>
#include "eeprom.h"
#include "i2c.h"
#include "mcu_registers.h"

// Mock EEPROM memory
uint8_t eeprom_memory_mock[EEPROM_SIZE] = {0};

// Initialize EEPROM
void eeprom_init() {
    printf("[EEPROM] INIT\n");
    i2c_init(EEPROM_I2C_ADDRESS_READ);
}

// Read a byte from EEPROM
uint8_t eeprom_read(uint8_t addr) {
    printf("[EEPROM] READ @0x%02X\n", addr);
    return i2c_read_byte(addr);
}

// Mock EEPROM data
void eeprom_mock(uint8_t revision, const char* serial) {
    eeprom_memory_mock[EEPROM_HW_REV_ADDR] = revision;
    strncpy((char*)eeprom_memory_mock, serial, 8);
    printf("[EEPROM] initialize mocked revision %X\n", revision);
    printf("[EEPROM] initialize mocked serial %s\n", serial);
}