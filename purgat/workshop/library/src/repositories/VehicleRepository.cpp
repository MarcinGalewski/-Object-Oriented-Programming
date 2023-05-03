//
// Created by student on 14.04.23.
//
#include "repositories/VehicleRepository.h"

VehiclePtr VehicleRepository::findByPlateNumber(const std::string &plateNumber) const {
    return findById<const std::string &>(plateNumber);
}
