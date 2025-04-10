#ifndef CONFIGURATOR_HPP
#define CONFIGURATOR_HPP

#include <cstdint>
#include <cstring>
#include <iostream>

constexpr uint8_t HW_REV_0 = 0x00;
constexpr uint8_t HW_REV_1 = 0x01;

constexpr char HW_SERIAL_NUMBER[] = "ABC1234\n";
constexpr uint8_t HW_SERIAL_NUMBER_SIZE = sizeof(HW_SERIAL_NUMBER) / sizeof(HW_SERIAL_NUMBER[0]);

class Configurator {
private:
    uint8_t m_hardwareRevision;
    char m_serialNumber[HW_SERIAL_NUMBER_SIZE];

public:
    Configurator();
    void init();
    void readConfiguration();

    uint8_t getHardwareRevision();
    const char* getSerialNumber();
};

#endif // CONFIGURATOR_HPP