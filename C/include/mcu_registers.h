#ifndef MCU_REGISTERS_H
#define MCU_REGISTERS_H

#include <stdint.h>

//MOCK MCU REGISTER DEFINITIONS
extern volatile uint8_t mock_mcu_registers[256];

// ADC Registers
#define ADC_CONFIG_REG              (*(volatile uint8_t *)&mock_mcu_registers[0x30])
#define ADC_VAL_REG_HIGH            (*(volatile uint8_t *)&mock_mcu_registers[0x31])
#define ADC_VAL_REG_LOW             (*(volatile uint8_t *)&mock_mcu_registers[0x32])

#define ADC_RESOLUTION_10BIT        0x20
#define ADC_RESOLUTION_8BIT_MASK    ~0x20
#define ADC_TRIGGER_CLK_MASK        ~0x08 //0xF7
#define ADC_ISR_CLEAR               0x04
#define ADC_ISR_ENABLE              0x02
#define ADC_ENABLE                  0x01

// CLK0 Registers
#define CLK0_CONFIG_REG       (*(volatile uint8_t *)&mock_mcu_registers[0x40])
#define CLK_FREQ_10KHZ        ~0x06
#define CLK_ENABLE            0x01

// GPIO Registers
#define GPIO_REG_0      (*(volatile uint8_t *)&mock_mcu_registers[0x50])
#define GPIO_REG_1      (*(volatile uint8_t *)&mock_mcu_registers[0x51])
#define GPIO_REG_2      (*(volatile uint8_t *)&mock_mcu_registers[0x52])

#define GPIO_FUNC_MASK        ~0x20 //0xDF
#define GPIO_RESET            0x08
#define GPIO_SET              0x04
#define GPIO_OUTPUT           0x02
#define GPIO_ENABLE           0x01

// EEPROM/I2C mock
#define EEPROM_I2C_CONFIG_REG       (*(volatile uint8_t *)&mock_mcu_registers[0x60])
#define EEPROM_I2C_REG_ADDRESS      (*(volatile uint8_t *)&mock_mcu_registers[0x61])
#define EEPROM_SIZE                 256
#define EEPROM_HW_REV_ADDR          0x00
#define EEPROM_SERIAL_ENABLE        0x01
#define EEPROM_SERIAL_LENGTH        0x08
#define EEPROM_I2C_ADDRESS_READ     0x81


// EEPROM mock functions
void mcu_mock_registers_init(); 

//Define GPIOs and LEDs
typedef enum {
    GPIO_0,
    GPIO_1,
    GPIO_2
} GPIO;

typedef enum {
    LED_RED,
    LED_YELLOW,
    LED_GREEN
} LED;

#endif