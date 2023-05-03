//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include "typedefs.h"
#include "model/Vehicle.h"
#include "Repository.h"

class VehicleRepository : public Repository<Vehicle>{
public:
    VehiclePtr findByPlateNumber(const std::string &plateNumber) const;
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
