//
// Created by student on 07.04.23.
//

#include "model/Rent.h"

Rent::Rent(unsigned int id, Client *client, Vehicle *vehicle) :
id(id), client(client), vehicle(vehicle) {}

Rent::~Rent() {

}

std::string Rent::getRentInfo() const {
    return "Rent: " + std::to_string(id) + " " + client->getClientInfo() + " " + vehicle->getVehicleInfo();
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
