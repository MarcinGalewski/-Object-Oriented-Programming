//
// Created by student on 12.06.23.
//

#ifndef HOTEL_LOGICCONTAINER_H
#define HOTEL_LOGICCONTAINER_H

#include "typedefs.h"

class LogicContainer {
private:
    ClientManagerPtr clientManager;
    RoomManagerPtr roomManager;
    RentManagerPtr rentManager;

public:
    LogicContainer();

    virtual ~LogicContainer();

    const ClientManagerPtr &getClientManager() const;

    const RoomManagerPtr &getRoomManager() const;

    const RentManagerPtr &getRentManager() const;

};



#endif //HOTEL_LOGICCONTAINER_H
