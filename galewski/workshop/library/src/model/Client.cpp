//
// Created by student on 30.03.23.
//
#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
using namespace std;

Client::Client(const string &firstName,
               const string &lastName,
               const string &personalId,
               Address *address) :
        firstName(firstName),
        lastName(lastName),
        personalId(personalId),
        address(address){}

Client::~Client() {}

std::string Client::getClientInfo() const{
    return "Client: " + firstName + " " + lastName + ", id: " + personalId
           + ", \n" + address->getAddressInfo();
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

void Client::setFirstName(const string &firstName) {
    if(firstName != "")
        Client::firstName = firstName;
}

void Client::setLastName(const string &lastName) {
    if(lastName != "")
        Client::lastName = lastName;
}
std::vector<Rent *> &Client::getCurrentRents(){
    return currentRents;
}
void Client::addRent(Rent *rent) {
    currentRents.push_back(rent);
}