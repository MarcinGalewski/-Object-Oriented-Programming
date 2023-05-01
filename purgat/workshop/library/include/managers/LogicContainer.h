//
// Created by student on 27.04.23.
//

#ifndef CARRENTAL_LOGICCONTAINER_H
#define CARRENTAL_LOGICCONTAINER_H

#include "typedefs.h"
#include "managers/ClientManager.h"
#include "managers/VehicleManager.h"
#include "managers/RentManager.h"

class LogicContainer {
private:
    ClientManagerPtr clientManager;
    VehicleManagerPtr vehicleManager;
    RentManagerPtr rentManager;

public:
    LogicContainer();

    virtual ~LogicContainer();

    const ClientManagerPtr &getClientManager() const;

    const VehicleManagerPtr &getVehicleManager() const;

    const RentManagerPtr &getRentManager() const;
};


#endif //CARRENTAL_LOGICCONTAINER_H
