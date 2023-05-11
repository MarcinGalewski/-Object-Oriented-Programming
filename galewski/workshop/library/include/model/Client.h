//
// Created by student on 30.03.23.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "string"
#include "vector"
#include "model/Address.h"
#include "model/Rent.h"

class Rent;

class Client {
private:

    std::string firstName;
    std::string lastName;
    std::string personalId;
    Address *address;
    std::vector<Rent*> currentRents;
public:
    virtual ~Client();

    std::string getClientInfo();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    Address *getAddress() const;

    std::vector<Rent *> &getCurrentRents();

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setAddress(Address *address);

    std::string getClientInfo() const;
    std::string getFullClientInfo() const;

    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId, Address *address);
    void addRent( Rent * rent);
};


#endif //CARRENTAL_CLIENT_H
