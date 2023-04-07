//
// Created by student on 18.03.23.
//

#include "model/Client.h"

using namespace std;
Client::Client(const string &firstName, const string &lastName, const string &personalId, Address *address) :
firstName(firstName), lastName(lastName), personalId(personalId), address(address) {}

Client::~Client() {}

std::string Client::getClientInfo() const{
    return "Client: " + firstName + " " + lastName + ", id: " + personalId + ", " + address->getAddressInfo();
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

Address *Client::getAddress() const {
    return address;
}

void Client::setFirstName(const string &firstName) {
    if(!firstName.empty())
    Client::firstName = firstName;
}

void Client::setLastName(const string &lastName) {
    if(!lastName.empty())
    Client::lastName = lastName;
}

void Client::setAddress(Address *address) {
    if(address)
    Client::address = address;
}

