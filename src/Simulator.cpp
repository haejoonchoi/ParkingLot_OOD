#include "Simulator.h"
#include "Vehicle.h"
#include "ParkingLot.h"

void Simulator::run()
{
    // initialize parking lot
    ParkingLot *parkingLot = new ParkingLot(3, 10);

    // create vehicles
    Vehicle *car1 = new Vehicle(SMALL, CAR, "Toyota", "Corolla", "1234", "Red");
    Vehicle *car2 = new Vehicle(MEDIUM, CAR, "Toyota", "Camry", "5678", "Blue");
    Vehicle *car3 = new Vehicle(LARGE, CAR, "Toyota", "RAV4", "9876", "Green");
    Vehicle *truck1 = new Vehicle(LARGE, TRUCK, "Ford", "F150", "5432", "Black");
    Vehicle *truck2 = new Vehicle(LARGE, TRUCK, "Ford", "F250", "8765", "White");
    Vehicle *motorcycle1 = new Vehicle(SMALL, MOTORCYCLE, "Harley", "Davidson", "1357", "Black");
    Vehicle *motorcycle2 = new Vehicle(SMALL, MOTORCYCLE, "Honda", "CBR", "2468", "Red");

    // park vehicles
    parkingLot->parkVehicle(car1);
    parkingLot->parkVehicle(car2);
    parkingLot->parkVehicle(car3);
    parkingLot->parkVehicle(truck1);
    parkingLot->parkVehicle(truck2);
    parkingLot->parkVehicle(motorcycle1);
    parkingLot->parkVehicle(motorcycle2);


    // remove vehicles
    parkingLot->removeVehicle(car1);
    parkingLot->removeVehicle(car2);
    parkingLot->removeVehicle(car3);
    parkingLot->removeVehicle(truck1);
    parkingLot->removeVehicle(truck2);
    parkingLot->removeVehicle(motorcycle1);
    parkingLot->removeVehicle(motorcycle2);
}
