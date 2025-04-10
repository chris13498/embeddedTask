#include "../include/thermometer.hpp"

// Initialize the thermometer with the specified hardware revision
void Thermometer::init(uint8_t hw_rev) {
    m_hw_rev = hw_rev;
    m_interruptFlagRaised = false;
    std::cout << "[Thermometer] Set ADC sample depth for HW-REV: " << hw_rev << std::endl;
    std::cout << "[Thermometer] Set ADC Clock source: Clk0"<< std::endl;
    std::cout << "[Thermometer] Set ADC sample frequency: 10kHz"<< std::endl << std::endl;
}

// Start the thermometer by enabling necessary components
void Thermometer::start() {
    std::cout << "[Thermometer] Enable ADC Clock"<< std::endl;
    std::cout << "[Thermometer] Enable ADC Interrupt"<< std::endl << std::endl;
}

// Register a listener to receive temperature updates
uint8_t Thermometer::registerListener(Thermometer* listener) {
    std::cout << "[Thermometer] Register listener"<< std::endl;
    if (listener == nullptr) {
        std::cout << "[Thermometer] Listener is null"<< std::endl;
        return 1; // Return error code if listener is null
    }

    m_listener = listener;
    return 0; // Return success code
}

// Update the temperature (to be called from by Interrupt Service Routine)
void Thermometer::__updateTemperature__() {
    m_interruptFlagRaised = true;
    std::cout << "[Thermometer] ISR"<< std::endl;
    std::cout << "[Thermometer] Read ADC value"<< std::endl;
    std::cout << "[Thermometer] Update temperature"<< std::endl;

    // Simulate ADC value and notify the listener
    uint16_t temperature = rand() % 150; 
    m_listener->receiveTemperature(temperature);
}

// Check if the interrupt flag is raised
bool Thermometer::isInterruptFlagRaised() {
    std::cout << "[Thermometer] Check interrupt flag"<< std::endl;
    return m_interruptFlagRaised;
}

// Reset the interrupt flag
void Thermometer::resetInterruptFlag() {
    std::cout << "[Thermometer] Reset interrupt flag"<< std::endl;
    m_interruptFlagRaised = false;
}

// Placeholder function to be overridden by derived classes for handling temperature updates
void Thermometer::receiveTemperature(uint16_t temperature) {
    // To be overridden by the derived class
}