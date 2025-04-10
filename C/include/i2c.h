#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#define I2C_WRITE 0
#define I2C_READ  1

// Init function for completeness
void i2c_init(uint8_t device_addr);

// Basic I2C functions
uint8_t i2c_read_byte(uint8_t mem_addr);
void    i2c_write_byte(uint8_t mem_addr, uint8_t data);

#endif