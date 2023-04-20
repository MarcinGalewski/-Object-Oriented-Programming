//
// Created by student on 18.03.23.
//

#include "model/Client.h"

using namespace std;

Client::Client(const string &firstName, const string &lastName, const string &personalId, AddressPtr address) :
firstName(firstName), lastName(lastName), personalId(personalId), address(address) {}

Client::~Client() {}

std::string Client::getClientInfo() const{

    return "Client: " + firstName + " " + lastName + ", id: " + personalId
    + ", " + address->getAddressInfo();
}

std::string Client::getFullClientInfo() const {
    string allRents;
    for(int i = 0; i < currentRents.size(); i++){
        allRents += currentRents[i]->getRentInfo() + "\n";
    }

    return getClientInfo() + "\n" + allRents;
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

AddressPtr Client::getAddress() const {
    return address;
}

std::vector<RentPtr> &Client::getCurrentRents(){
    return currentRents;
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

void Client::addRent(RentPtr rent) {
currentRents.push_back(rent);
}



