#ifndef TEMPERATUREVISUALIZER_HPP
#define TEMPERATUREVISUALIZER_HPP
#include <iostream>
#include "configurator.hpp"
#include "thermometer.hpp"
#include "statusindicator.hpp"

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#endif


#define TEMP_WARN_C        85.0
#define TEMP_CRIT_HIGH_C   105.0
#define TEMP_CRIT_LOW_C    5.0

class TemperatureVisualizer : private Thermometer{
private:
    static uint8_t m_hardwareRevision;
    static char m_serialNumber[HW_SERIAL_NUMBER_SIZE];

    uint16_t m_temperature;

    Configurator* m_configurator;
    StatusIndicator* m_statusIndicator;
    Thermometer* m_thermometer;

    ~TemperatureVisualizer();

    void receiveTemperature(uint16_t temperature) override;

public:
    void init();
    void run();
};


#endif // TEMPERATUREVISUALIZER_HPP