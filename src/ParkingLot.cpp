#include "ParkingLot.h"

//// ParkingLot /////////////////////////////////////////////

ParkingLot::ParkingLot(int numFloors, int numSpotsPerFloor)
{
    // create floors
    for (size_t i = 0; i < numFloors; i++)
    {
        ParkingFloor floor(numSpotsPerFloor);
        floors.push_back(floor);
    }
}

bool ParkingLot::parkVehicle(Vehicle *vehicle)
{
    for (size_t i = 0; i < floors.size(); i++)
    {
        if (floors[i].parkVehicle(vehicle))
        {
            return true;
        }
    }
    return false;
}

bool ParkingLot::removeVehicle(Vehicle *vehicle)
{
    // find vehicle and remove it
    for (size_t i = 0; i < floors.size(); i++)
    {
        if (floors[i].removeVehicle(vehicle))
        {
            return true;
        }
    }
    return false;
}

void ParkingLot::print()
{
    // print all floors
    for (size_t i = 0; i < floors.size(); i++)
    {
        floors[i].print();
    }
}

//// ParkingFloor /////////////////////////////////////////////

ParkingFloor::ParkingFloor(int numSpots)
{
    // create spots for floor
    // default ratio of SMALL, MEDIUM, LARGE spots is 1:3:1
    for (size_t i = 0; i < numSpots; i++)
    {
        VehicleSize size;
        if (i % 5 == 1 || i % 5 == 2 || i % 5 == 3)
        {
            size = MEDIUM;
        }
        else if (i % 5 == 0)
        {
            size = SMALL;
        }
        else
        {
            size = LARGE;
        }
        ParkingSpot spot(size);
        spots.push_back(spot);
    }
}

bool ParkingFloor::parkVehicle(Vehicle *vehicle)
{
    for (size_t i = 0; i < spots.size(); i++)
    {
        if (spots[i].parkVehicle(vehicle))
        {
            return true;
        }
    }
    return false;
}

bool ParkingFloor::removeVehicle(Vehicle *vehicle)
{
    for (size_t i = 0; i < spots.size(); i++)
    {
        if (spots[i].removeVehicle(vehicle))
        {
            return true;
        }
    }
    return false;
}

void ParkingFloor::print()
{
    // print all spots
    for (size_t i = 0; i < spots.size(); i++)
    {
        spots[i].print();
    }
}

//// ParkingSpot /////////////////////////////////////////////

ParkingSpot::ParkingSpot(VehicleSize size)
{
    this->size = size;
    vehicle = nullptr;
}

bool ParkingSpot::parkVehicle(Vehicle *vehicle)
{
    auto logger = spdlog::get("console");
    if (this->vehicle == nullptr)
    {
        logger->info("Parking vehicle in spot");
        logger->debug(fmt::format("{} {}", vehicle->getMake(), vehicle->getModel()));
        this->vehicle = vehicle;
        return true;
    }

    return false;
}

bool ParkingSpot::removeVehicle(Vehicle *vehicle)
{
    auto logger = spdlog::get("console");
    logger->info("Removing vehicle from spot");
    if (this->vehicle == vehicle)
    {
        logger->debug("Vehicle removed from spot");
        logger->debug(fmt::format("{} {}", vehicle->getMake(), vehicle->getModel()));
        this->vehicle = nullptr;
        return true;
    }
    return false;
}

void ParkingSpot::print()
{
    auto logger = spdlog::get("console");
    if (vehicle == nullptr)
    {
        logger->info("Spot is empty");
    }
    else
    {
        logger->info("Spot is occupied");
        this->vehicle->print();
    }
}
