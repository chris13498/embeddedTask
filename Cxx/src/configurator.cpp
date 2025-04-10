#include "../include/configurator.hpp"

// Constructor to initialize the Configurator object
Configurator::Configurator() {
    m_hardwareRevision = 0; // Initialize hardware revision to 0
    strncpy(m_serialNumber, "ABC1234\n", sizeof(m_serialNumber) - 1);
}

// Initialize the Configurator by simulating hardware setup
void Configurator::init() {
    std::cout << "[Configurator] Initialize I2C" << std::endl;
    std::cout << "[Configurator] Write Clock frequency" << std::endl;
    std::cout << "[Configurator] Configure I2C address" << std::endl << std::endl; 
}

// Read configuration data (e.g., hardware revision and serial number) from EEPROM
void Configurator::readConfiguration() {
    std::cout << "[Configurator] Read HW-Rev and Serial Number from EEPROM" << std::endl << std::endl;

    // Simulate reading hardware revision and serial number
    m_hardwareRevision = HW_REV_0; // Mock hardware revision value
    strncpy(m_serialNumber, HW_SERIAL_NUMBER, sizeof(m_serialNumber) - 1); // Copy mock serial number
    m_serialNumber[sizeof(m_serialNumber) - 1] = '\0'; // Ensure null-termination
}

// Get the hardware revision
uint8_t Configurator::getHardwareRevision() {
    // Return the hardware revision
    return 0; // Mock return value
}

