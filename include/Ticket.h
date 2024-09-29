#pragma once
#include "pch.h"  // Include the precompiled header first


struct ParkingTicket {
    int ticketNumber;
    int vehicleNumber;
    int parkingSpot;
    int timeIn;
    int timeOut;
    int fee;
    bool paid;
};