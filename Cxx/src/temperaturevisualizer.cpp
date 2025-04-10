#include "../include/temperaturevisualizer.hpp"

// Initialize the TemperatureVisualizer and its components
void TemperatureVisualizer::init() {
    std::cout << "[TemperatureVisualizer] Init" << std::endl;

    // Construct and initialize the Configurator
    m_configurator = new Configurator();
    m_configurator->init();
    m_configurator->readConfiguration();

    // Construct and initialize the StatusIndicator
    m_statusIndicator = new StatusIndicator();
    m_statusIndicator->init();

    // Construct and initialize the Thermometer
    m_thermometer = new Thermometer();
    m_thermometer->init(m_configurator->getHardwareRevision());

    // Register the TemperatureVisualizer as a listener for the Thermometer
    m_thermometer->registerListener(this);
}

// Run the TemperatureVisualizer's main loop
void TemperatureVisualizer::run() {
    std::cout << "[TemperatureVisualizer] running" << std::endl << std::endl;

    // Start the thermometer
    m_thermometer->start();

    // Main loop to monitor temperature and update status
    while (true) {
        // Wait for the interrupt flag to be raised
        std::cout << std::endl << "[TemperatureVisualizer] Wait for Interrupt flag" << std::endl;
        while (!m_thermometer->isInterruptFlagRaised()) {
            sleep(1); // Simulate waiting
            m_thermometer->__updateTemperature__(); // Simulate temperature update by ISR
            std::cout << "[TemperatureVisualizer] Interrupt flag raised" << std::endl;
        }
        m_thermometer->resetInterruptFlag(); // Reset the interrupt flag

        // Check temperature and update the status indicator
        if (m_temperature < TEMP_CRIT_LOW_C || m_temperature > TEMP_CRIT_HIGH_C) {
            std::cout << "[TemperatureVisualizer] Critical temperature" << std::endl << std::endl;
            m_statusIndicator->showCritical();
        } else if (m_temperature > TEMP_WARN_C) {
            std::cout << "[TemperatureVisualizer] Warning temperature" << std::endl << std::endl;
            m_statusIndicator->showWarning();
        } else {
            std::cout << "[TemperatureVisualizer] OK temperature" << std::endl << std::endl;
            m_statusIndicator->showOk();
        }
    }
}

// Receive temperature updates from the Thermometer
void TemperatureVisualizer::receiveTemperature(uint16_t temperature) {
    m_temperature = temperature;
    std::cout << "[TemperatureVisualizer] Temperature: " << m_temperature << "°C" << std::endl;
}

// Destructor to clean up resources
TemperatureVisualizer::~TemperatureVisualizer() {
    std::cout << "[TemperatureVisualizer] Destructor" << std::endl;
    delete m_configurator;
    delete m_statusIndicator;
    delete m_thermometer;
}
