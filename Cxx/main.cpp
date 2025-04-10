// Include necessary headers for the application
#include "include/temperaturevisualizer.hpp"
#include <iostream>
#include <string>
#include <memory>
#include "configurator.hpp"
#include "thermometer.hpp"
#include "statusindicator.hpp"

int main() {
    // Create an instance of TemperatureVisualizer
    TemperatureVisualizer* tempVisualizer = new TemperatureVisualizer();

    // Initialize the temperature visualizer
    tempVisualizer->init();

    // Run the temperature visualizer
    tempVisualizer->run();

    // Return 0 to indicate successful execution
    return 0;
}
