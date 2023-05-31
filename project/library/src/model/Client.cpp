//
// Created by student on 31.05.23.
//

#include "model/Client.h"
#include "model/Address.h"

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const AddressPtr &address, const ClientTypePtr &clientType) : firstName(firstName), lastName(lastName),
                                                                             personalId(personalId), address(address),
                                                                             clientType(clientType) {}

Client::~Client() {}

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getPersonalId() const {
    return personalId;
}

bool Client::isArchived1() const {
    return isArchived;
}

const AddressPtr &Client::getAddress() const {
    return address;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

void Client::setFirstName(const std::string &firstName) {
    Client::firstName = firstName;
}

void Client::setLastName(const std::string &lastName) {
    Client::lastName = lastName;
}

void Client::setIsArchived(bool isArchived) {
    Client::isArchived = isArchived;
}

void Client::setAddress(const AddressPtr &address) {
    Client::address = address;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    Client::clientType = clientType;
}
