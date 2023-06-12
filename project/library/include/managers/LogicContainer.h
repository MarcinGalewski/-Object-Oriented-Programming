//
// Created by student on 12.06.23.
//

#ifndef HOTEL_LOGICCONTAINER_H
#define HOTEL_LOGICCONTAINER_H

#include "typedefs.h"
#include "managers/ClientManager.h"

class LogicContainer {
private:
    ClientManagerPtr clientManager;

public:
    LogicContainer();

    virtual ~LogicContainer();

    const ClientManagerPtr &getClientManager() const;

};



#endif //HOTEL_LOGICCONTAINER_H
