cmake_minimum_required(VERSION 3.10)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fdiagnostics-color=always)
endif()

# Project name and version
project(ParkingLot VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_OSX_ARCHITECTURES "arm64")

# Add the include directory
include_directories(include)
include_directories(/opt/homebrew/Cellar/fmt/11.0.2/include/fmt)
include_directories(/opt/homebrew/Cellar/spdlog/1.14.1_1/include/spdlog)

# Add the executable
add_executable(
    ParkingLot_Simulator
    src/main.cpp
    src/Simulator.cpp
    src/ParkingLot.cpp
    src/Vehicle.cpp
    )

# Create the precompiled header
target_precompile_headers(ParkingLot_Simulator PRIVATE include/pch.h)


# Find and link the fmt library
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
target_link_libraries(ParkingLot_Simulator fmt::fmt spdlog::spdlog)