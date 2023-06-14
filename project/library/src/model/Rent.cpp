//
// Created by student on 12.06.23.
//

#include "model/Rent.h"
#include "model/Client.h"
#include "model/rooms/Room.h"
#include "exceptions/RentException.h"

Rent::Rent(const boost::uuids::uuid &id, const ClientPtr &client, const RoomPtr &room, unsigned int numberOfDays) : id(
        id), client(client), room(room), numberOfDays(numberOfDays) {
    if(numberOfDays <= 0){
        throw RentException("Incorrect number of days");
    }
    else if(client == nullptr || room == nullptr){
        throw RentException("Pointer is nullptr");
    }
    else{
        calculateCost();
    }

}

Rent::~Rent() = default;

std::string Rent::getInfo() const {
    return "Rent: \n" + boost::uuids::to_string(id) + "\n"
           + client->getInfo() + "\n"  + room->getInfo() + "\n";
}

const boost::uuids::uuid &Rent::getId() const {
    return id;
}

const ClientPtr &Rent::getClient() const {
    return client;
}

const RoomPtr &Rent::getRoom() const {
    return room;
}

unsigned int Rent::getNumberOfDays() const {
    return numberOfDays;
}

double Rent::getRentCost() const {
    return rentCost;
}

void Rent::calculateCost() {
    rentCost = room->getActualPrice() * numberOfDays;
    rentCost -= client->applyDiscount(rentCost);
    if(rentCost < 0) rentCost = 0;
}

