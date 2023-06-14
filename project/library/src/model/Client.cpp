//
// Created by student on 31.05.23.
//

#include "model/Client.h"
#include "model/Address.h"
#include "model/clientTypes/ClientType.h"
#include "exceptions/ClientException.h"

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const AddressPtr &address, const ClientTypePtr &clientType) : firstName(firstName), lastName(lastName),
                                                                             personalId(personalId), address(address),
                                                                             clientType(clientType) {
    if(firstName.empty() || lastName.empty() || personalId.empty())
        throw ClientException("Empty string");
    if(address == nullptr || clientType == nullptr)
        throw ClientException("Pointer is nullptr");
}

Client::~Client() = default;

const std::string &Client::getFirstName() const {
    return firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

const std::string &Client::getPersonalId() const {
    return personalId;
}

const std::string &Client::getId() const {
    return getPersonalId();
}


bool Client::isArchived() const {
    return archived;
}

const AddressPtr &Client::getAddress() const {
    return address;
}

void Client::setFirstName(const std::string &firstName) {
    if(firstName.empty())
        throw ClientException("Empty string");
    Client::firstName = firstName;
}

void Client::setLastName(const std::string &lastName) {
    if(lastName.empty())
        throw ClientException("Empty string");
    Client::lastName = lastName;
}

void Client::setArchived(bool archived) {
    Client::archived = archived;
}

void Client::setAddress(const AddressPtr &address) {
    if(address == nullptr)
        throw ClientException("Pointer is nullptr");
    Client::address = address;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    if(clientType == nullptr)
        throw ClientException("Pointer is nullptr");
    Client::clientType = clientType;
}

double Client::applyDiscount(double price) {
    return clientType->applyDiscount(price);
}

std::string Client::getInfo() const {
    return "Client: " + firstName + " " + lastName + ", id: " + personalId
           + ", " + address->getInfo() + ", " + clientType->getInfo();
}
