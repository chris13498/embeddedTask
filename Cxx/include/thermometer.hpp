#ifndef THERMOMETER_HPP
#define THERMOMETER_HPP

#include <cstdint>
#include <iostream>

class Thermometer {
private:
    Thermometer* m_listener;
    uint8_t m_hw_rev;

    bool m_interruptFlagRaised;

public:
    void init(uint8_t hw_rev);
    void start();
    void __updateTemperature__(); // to be called from ISR
    uint8_t registerListener(Thermometer* listener);
    void resetInterruptFlag();
    bool isInterruptFlagRaised();

    virtual void receiveTemperature(uint16_t temperature);

};


#endif // THERMOMETER_HPP