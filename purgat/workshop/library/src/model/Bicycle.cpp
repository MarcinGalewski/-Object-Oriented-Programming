//
// Created by student on 16.04.23.
//

#include <iostream>
#include "model/Bicycle.h"
#include "exceptions/VehicleException.h"

Bicycle::Bicycle(const std::string &plateNumber, unsigned int basePrice) :
Vehicle(plateNumber, basePrice) {}

Bicycle::~Bicycle() {

}

double Bicycle::getActualRentalPrice() const {
    return getBasePrice();
}

std::string Bicycle::getVehicleInfo() const {
    return "Bicycle: " + Vehicle::getVehicleInfo();
}
