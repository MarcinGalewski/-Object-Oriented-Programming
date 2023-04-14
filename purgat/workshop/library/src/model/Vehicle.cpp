//
// Created by student on 07.04.23.
//

#include "model/Vehicle.h"

Vehicle::Vehicle(const std::string &plateNumber, unsigned int basePrice) :
plateNumber(plateNumber), basePrice(basePrice) {}

Vehicle::~Vehicle() {

}

std::string Vehicle::getVehicleInfo() const {
    return "Vehicle: " + plateNumber + ", base price: " + std::to_string(basePrice);
}

const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

bool Vehicle::isRented() const {
    return rented;
}

void Vehicle::setPlateNumber(const std::string &plateNumber) {
    if(!plateNumber.empty())
    Vehicle::plateNumber = plateNumber;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}

void Vehicle::setRented(bool rented) {
    Vehicle::rented = rented;
}




