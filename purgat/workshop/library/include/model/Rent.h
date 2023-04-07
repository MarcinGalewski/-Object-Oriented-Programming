//
// Created by student on 07.04.23.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H

#include "string"
#include "model/Client.h"
#include "model/Vehicle.h"

class Rent {
private:
    unsigned int id;
    Client* client;
    Vehicle* vehicle;

public:
    Rent(unsigned int id, Client *client, Vehicle *vehicle);

    virtual ~Rent();

    std::string getRentInfo() const;

    unsigned int getId() const;

    Client *getClient() const;

    Vehicle *getVehicle() const;
};


#endif //CARRENTAL_RENT_H
