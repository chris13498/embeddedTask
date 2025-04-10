// Include standard and project-specific headers
#include <stdint.h>
#include <stdio.h>
#include "mcu_registers.h"
#include <string.h>

// Define a mock MCU register array
volatile uint8_t mock_mcu_registers[256];

// Initialize the mock MCU registers
void mcu_mock_registers_init() {
    printf("[MCU-REGISTERS] INIT\n");
    memset((void *) mock_mcu_registers, 0, sizeof(mock_mcu_registers));
}