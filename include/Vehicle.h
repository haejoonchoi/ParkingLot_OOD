#pragma once

#include "pch.h"  // Include the precompiled header first

enum VehicleSize
{
    SMALL,
    MEDIUM,
    LARGE
};

enum VehicleType
{
    CAR,
    TRUCK,
    MOTORCYCLE
};

class Vehicle
{
public:
    Vehicle(
        VehicleSize size,
        VehicleType type,
        std::string make,
        std::string model,
        std::string licensePlate,
        std::string color);

    VehicleSize getSize();
    VehicleType getType();
    std::string getMake();
    std::string getModel();
    std::string getLicensePlate();
    std::string getColor();
    void park();
    void leave();
    void print();

private:
    VehicleSize size;
    VehicleType type;
    std::string make;
    std::string model;
    std::string licensePlate;
    std::string color;
    bool parked;
};