//
// Created by student on 01.05.23.
//

#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H

#include <boost/date_time.hpp>

#include "typedefs.h"
#include "repositories/RentRepository.h"

namespace pt = boost::posix_time;

class RentManager {
private:
    RentRepositoryPtr currentRents;
    RentRepositoryPtr archiveRents;

public:
    RentManager();

    virtual ~RentManager();

    std::vector<RentPtr> getAllClientRents(ClientPtr client);

    RentPtr getVehicleRent(VehiclePtr vehicle);

    std::vector<RentPtr> findRent(RentPredicate predicate);

    std::vector<RentPtr> findAllRents();

    double checkClientRentBalance(ClientPtr client);

    RentPtr rentVehicle(ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime);

    void returnVehicle(VehiclePtr vehicle);

    void changeClientType(ClientPtr client);
};


#endif //CARRENTAL_RENTMANAGER_H
