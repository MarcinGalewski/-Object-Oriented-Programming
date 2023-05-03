//
// Created by student on 18.03.23.
//

#include "model/Client.h"
#include "exceptions/ClientException.h"

using namespace std;

Client::Client(const string &firstName, const string &lastName, const string &personalId, AddressPtr address, ClientTypePtr clientType) :
firstName(firstName), lastName(lastName), personalId(personalId), address(address), clientType(clientType) {
    if(firstName.empty() || lastName.empty() || personalId.empty())
        throw ClientException("Empty string");
    if(address == nullptr || clientType == nullptr)
        throw ClientException("Pointer is nullptr");
}

Client::~Client() {}

std::string Client::getClientInfo() const{

    return "Client: " + firstName + " " + lastName + ", id: " + personalId
    + ", " + address->getAddressInfo() + ", " + clientType->getTypeInfo();
}

std::string Client::getInfo() const {
    return getClientInfo();
}

const string &Client::getFirstName() const {
    return firstName;
}

const string &Client::getLastName() const {
    return lastName;
}

const string &Client::getPersonalId() const {
    return personalId;
}

const std::string &Client::getId() const {
    return getPersonalId();
}

AddressPtr Client::getAddress() const {
    return address;
}

unsigned int Client::getMaxVehicles() const {
    return clientType->getMaxVehicles();
}

void Client::setFirstName(const string &firstName) {
    if(!firstName.empty())
    Client::firstName = firstName;
}

void Client::setLastName(const string &lastName) {
    if(!lastName.empty())
    Client::lastName = lastName;
}

void Client::setAddress(AddressPtr address) {
    if(address)
    Client::address = address;
}

void Client::setClientType(ClientTypePtr clientType) {
    if(clientType)
    Client::clientType = clientType;
}

double Client::applyDiscount(double price) const {
    return clientType->applyDiscount(price);
}

bool Client::isArchive() const {
    return archive;
}

void Client::setArchive(bool archive) {
    Client::archive = archive;
}

