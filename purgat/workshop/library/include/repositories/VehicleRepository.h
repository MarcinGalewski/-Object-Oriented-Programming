//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H

#include "vector"

#include "typedefs.h"
#include "model/Vehicle.h"

class VehicleRepository {
private:
    std::vector<VehiclePtr> vehicleRepository;

public:
    VehicleRepository();

    virtual ~VehicleRepository();

    VehiclePtr get(unsigned int index) const;

    void add(VehiclePtr vehicle);

    void remove(VehiclePtr vehicle);

    std::string report();

    unsigned int size() const;

    std::vector<VehiclePtr> findBy(VehiclePredicate predicate) const;

    std::vector<VehiclePtr> findAll() const;
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
