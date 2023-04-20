//
// Created by student on 16.04.23.
//

#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement)
        : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}

MotorVehicle::~MotorVehicle() {

}

unsigned int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

void MotorVehicle::setEngineDisplacement(unsigned int engineDisplacement) {
    MotorVehicle::engineDisplacement = engineDisplacement;
}

double MotorVehicle::getActualRentalPrice() const {
    if(engineDisplacement < 1000) return getBasePrice();
    else if(engineDisplacement < 2000)
        return getBasePrice() * (0.0005 * getEngineDisplacement() + 0.5);
    else return getBasePrice() * 1.5;
}

std::string MotorVehicle::getVehicleInfo() const {
    return Vehicle::getVehicleInfo() + ", engine dicplacement: " + std::to_string(engineDisplacement);
}
