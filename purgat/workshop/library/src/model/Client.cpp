//
// Created by student on 18.03.23.
//

#include "model/Client.h"

using namespace std;

Client::Client(const string &firstName,
               const string &lastName,
               const string &personalId) :
        firstName(firstName),
        lastName(lastName),
        personalId(personalId) {}

Client::~Client() {}

std::string Client::getClientInfo() {
    return "Client: " + firstName + " " + lastName + ", id: " + personalId;
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

