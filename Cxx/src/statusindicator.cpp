#include "../include/statusindicator.hpp"
#include <iostream>

// Initialize the StatusIndicator by setting up GPIOs
void StatusIndicator::init() {
    std::cout << "[StatusIndicator] Initialize GPIOs" << std::endl << std::endl;
}

// Reset the status indicator to its default state
void StatusIndicator::resetState() {
    std::cout << "[StatusIndicator] Status reset" << std::endl << std::endl;
}

// Display the "OK" status (e.g., green light)
void StatusIndicator::showOk() {
    std::cout << "[StatusIndicator] Status Green" << std::endl << std::endl;
}

// Display the "Warning" status (e.g., yellow light)
void StatusIndicator::showWarning() {
    std::cout << "[StatusIndicator] Status Yellow" << std::endl << std::endl;
}

// Display the "Critical" status (e.g., red light)
void StatusIndicator::showCritical() {
    std::cout << "[StatusIndicator] Status Red" << std::endl << std::endl;
}