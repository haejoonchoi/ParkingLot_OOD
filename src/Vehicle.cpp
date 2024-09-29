#include "Vehicle.h"

Vehicle::Vehicle(
    VehicleSize size,
    VehicleType type,
    std::string make,
    std::string model,
    std::string licensePlate,
    std::string color) : size(size),
                         type(type),
                         make(make),
                         model(model),
                         licensePlate(licensePlate),
                         color(color),
                         parked(false)
{
    auto logger = spdlog::get("console");
    logger->info("Vehicle created");
}

VehicleSize Vehicle::getSize()
{
    return this->size;
}

VehicleType Vehicle::getType()
{
    return this->type;
}

std::string Vehicle::getMake()
{
    return this->make;
}

std::string Vehicle::getModel()
{
    return this->model;
}

std::string Vehicle::getLicensePlate()
{
    return this->licensePlate;
}

std::string Vehicle::getColor()
{
    return this->color;
}

void Vehicle::print()
{
    auto logger = spdlog::get("console");
    logger->info("Vehicle Information");
    logger->debug(fmt::format("Make: {}", this->make));
    logger->debug(fmt::format("Model: {}", this->model));
    logger->debug(fmt::format("License Plate: {}", this->licensePlate));
    logger->debug(fmt::format("Color: {}", this->color));
}
