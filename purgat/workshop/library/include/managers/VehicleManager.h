//
// Created by student on 29.04.23.
//

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include "typedefs.h"
#include "repositories/VehicleRepository.h"
#include "model/Car.h"

class VehicleManager {
private:
    VehicleRepositoryPtr vehicleRepository;

public:
    VehicleManager();

    virtual ~VehicleManager();

    VehiclePtr getVehicle(std::string plateNumber);

    VehiclePtr registerBicycle(const std::string &plateNumber, unsigned int basePrice);

    VehiclePtr registerMoped(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);

    VehiclePtr registerCar(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment);

    void unregisterVehicle(VehiclePtr vehicle);

    std::vector<VehiclePtr> findVehicles(VehiclePredicate predicate);


};


#endif //CARRENTAL_VEHICLEMANAGER_H
