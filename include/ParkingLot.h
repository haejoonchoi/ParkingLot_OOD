#pragma once

#include "pch.h"  // Include the precompiled header first

#include "Vehicle.h"

class ParkingSpot
{
public:
    ParkingSpot(VehicleSize size);
    bool parkVehicle(Vehicle *vehicle);
    bool removeVehicle(Vehicle *vehicle);
    void print();

private:
    VehicleSize size;
    Vehicle *vehicle;
};

class ParkingFloor
{
public:
    ParkingFloor(int numSpots);
    bool parkVehicle(Vehicle *vehicle);
    bool removeVehicle(Vehicle *vehicle);
    void print();

private:
    std::vector<ParkingSpot> spots;
};

class ParkingLot
{
public:
    ParkingLot(int numFloors, int numSpotsPerFloor);
    bool parkVehicle(Vehicle *vehicle);
    bool removeVehicle(Vehicle *vehicle);
    void print();

private:
    std::vector<ParkingFloor> floors;
};