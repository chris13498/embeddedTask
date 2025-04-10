cmake_minimum_required(VERSION 3.10)

# Project name and version
project(TemperatureVisualizer VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    main.cpp
    src/configurator.cpp
    src/thermometer.cpp
    src/statusindicator.cpp
    src/temperaturevisualizer.cpp
)

# Add executable
add_executable(TemperatureVisualizer ${SOURCES})
