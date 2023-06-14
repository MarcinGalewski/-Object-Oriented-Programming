//
// Created by student on 14.06.23.
//

#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include "typedefs.h"

class Hotel {
private:
    std::string name;
    ClientManagerPtr clientManager;
    RoomManagerPtr roomManager;
    RentManagerPtr rentManager;

public:
    Hotel(const std::string &name, const ClientManagerPtr &clientManager, const RoomManagerPtr &roomManager,
          const RentManagerPtr &rentManager);

    const ClientManagerPtr &getClientManager() const;

    const RentManagerPtr &getRentManager() const;

    const RoomManagerPtr &getRoomManager() const;
};


#endif //HOTEL_HOTEL_H
