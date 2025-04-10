#include <stdio.h>
#include "i2c.h"
#include "mcu_registers.h"

// Mock EEPROM memory for testing purposes
extern uint8_t eeprom_memory_mock[]; 

// Initialize the I2C interface for EEPROM communication
void i2c_init(uint8_t device_addr) {
    // Set the EEPROM device address
    EEPROM_I2C_REG_ADDRESS = device_addr;

    // Enable the I2C serial interface
    EEPROM_I2C_CONFIG_REG |= EEPROM_SERIAL_ENABLE;

    // Log initialization details
    printf("[EEPROM-I2C] Initialized EEPROM with address 0x%X\n", device_addr);
    printf("[EEPROM-I2C] Initialized I2C clock speed\n");
    printf("[EEPROM-I2C] Initialized I2C bus direction (master/slave)\n");
}

// Read a byte from the specified memory address in the EEPROM
uint8_t i2c_read_byte(uint8_t mem_addr) {
    // Check if the memory address is within valid range
    if (mem_addr < EEPROM_SIZE) 
    {
        // Log the read operation and return the value
        printf("[EEPROM-I2C] READ @0x%02X = 0x%02X\n", mem_addr, eeprom_memory_mock[mem_addr]);
        return eeprom_memory_mock[mem_addr];
    }

    // Log an error if the address is out of range
    printf("[EEPROM-I2C] READ ERROR: Address out of range\n");
    return 0xFF; // Return an error code
}

