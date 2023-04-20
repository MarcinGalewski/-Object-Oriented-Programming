//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H

#include "typedefs.h"
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"

class StorageContainer {
private:
    ClientRepositoryPtr clientRepository;
    RentRepositoryPtr rentRepository;
    VehicleRepositoryPtr vehicleRepository;

public:
    StorageContainer();

    virtual ~StorageContainer();

    ClientRepositoryPtr getClientRepository();

    RentRepositoryPtr getRentRepository();

    VehicleRepositoryPtr getVehicleRepository();
};


#endif //CARRENTAL_STORAGECONTAINER_H
