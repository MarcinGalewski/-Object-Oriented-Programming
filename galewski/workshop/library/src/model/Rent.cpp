//
// Created by student on 11.05.23.
//
#include "model/Rent.h"
#include "algorithm"
Rent::Rent(unsigned int id, Client *client, Vehicle *vehicle, const pt::ptime &beginTime)
        : id(id), client(client), vehicle(vehicle), beginTime(beginTime) {
    client->addRent(this);
    vehicle->setRented(true);
    if(beginTime == pt::not_a_date_time)
        Rent::beginTime = pt::second_clock::local_time();
}
Rent::~Rent() {

}

std::string Rent::getRentInfo() const {
    std::stringstream beginTimeString;
    beginTimeString << getBeginTime();

    std::stringstream endTimeString;
    endTimeString << getEndTime();

    return "Rent: \n" + std::to_string(id) +
           " begin time: " + beginTimeString.str() + " end time: " + endTimeString.str() + "\n"
           + client->getClientInfo() + "\n" + vehicle->getVehicleInfo() + "\n";
}

unsigned int Rent::getId() const {
    return id;
}

Client *Rent::getClient() const {
    return client;
}

Vehicle *Rent::getVehicle() const {
    return vehicle;
}
const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

unsigned int Rent::getRentDays() const {
    pt::time_period rentTime(beginTime, endTime);
    if(endTime == pt::not_a_date_time ||
       (rentTime.length().hours() == 0 && rentTime.length().minutes() == 0))
        return 0;
    else
        return rentTime.length().hours() / 24 + 1;

}

unsigned int Rent::getRentCost() const {
    return rentCost;
}

void Rent::endRent(pt::ptime endTime) {
    if(Rent::endTime == pt::not_a_date_time) {
        if (endTime == pt::not_a_date_time)
            Rent::endTime = pt::second_clock::local_time();
        else if (endTime < beginTime)
            Rent::endTime = beginTime;
        else
            Rent::endTime = endTime;

        vehicle->setRented(false);
        client->getCurrentRents().erase(
                remove(client->getCurrentRents().begin(), client->getCurrentRents().end(), this),
                client->getCurrentRents().end());
        rentCost = (getRentDays() * vehicle->getBasePrice());
    }
}
