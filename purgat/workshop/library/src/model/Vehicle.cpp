//
// Created by student on 07.04.23.
//

#include "model/Vehicle.h"
#include "exceptions/VehicleException.h"

Vehicle::Vehicle(const std::string &plateNumber, unsigned int basePrice) :
plateNumber(plateNumber), basePrice(basePrice) {
    if(plateNumber.empty())
        throw VehicleException("Empty string");
    if(basePrice <= 0)
        throw VehicleException("Negative number or zero");
}

Vehicle::~Vehicle() {

}

std::string Vehicle::getVehicleInfo() const {
    return "plate number: " + plateNumber + ", base price: " + std::to_string(basePrice);
}

std::string Vehicle::getInfo() const {
    return getVehicleInfo();
}

const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

const std::string &Vehicle::getId() const {
    return getPlateNumber();
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

bool Vehicle::isArchive() const {
    return archive;
}

void Vehicle::setPlateNumber(const std::string &plateNumber) {
    if(plateNumber.empty()) throw VehicleException("Empty string");
    Vehicle::plateNumber = plateNumber;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    if(basePrice <= 0) throw VehicleException("Negative number or zero");
    Vehicle::basePrice = basePrice;
}

void Vehicle::setArchive(bool archive) {
    Vehicle::archive = archive;
}






