//
// Created by student on 16.04.23.
//

#include "model/Moped.h"

Moped::Moped(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement) : MotorVehicle(
        plateNumber, basePrice, engineDisplacement) {}

Moped::~Moped() {

}

double Moped::getActualRentalPrice() const {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getVehicleInfo() const {
    return "Moped: " + MotorVehicle::getVehicleInfo();
}
