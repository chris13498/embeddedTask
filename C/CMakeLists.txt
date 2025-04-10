cmake_minimum_required(VERSION 3.10)
project(TemperatureVisualizer)

set(CMAKE_C_STANDARD 11)

include_directories(include)

file(GLOB SOURCES src/*.c main.c)


add_executable(${PROJECT_NAME} ${SOURCES})