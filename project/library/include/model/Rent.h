//
// Created by student on 12.06.23.
//

#ifndef HOTEL_RENT_H
#define HOTEL_RENT_H

#include "string"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "typedefs.h"


class  Client;
class Room;

class Rent {
private:
    boost::uuids::uuid id;
    ClientPtr client;
    RoomPtr room;
    unsigned int numberOfDays;
    double rentCost = 0;

public:
    Rent(const boost::uuids::uuid &id, const ClientPtr &client, const RoomPtr &room, unsigned int numberOfDays);

    virtual ~Rent();

    std::string getInfo() const;

    const boost::uuids::uuid &getId() const;

    const ClientPtr &getClient() const;

    const RoomPtr &getRoom() const;

    unsigned int getNumberOfDays() const;

    double getRentCost() const;

    void calculateCost();
};



#endif //HOTEL_RENT_H
