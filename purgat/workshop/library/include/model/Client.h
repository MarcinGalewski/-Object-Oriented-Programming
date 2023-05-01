//
// Created by student on 18.03.23.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "string"
#include "vector"

#include "typedefs.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "model/ClientType.h"

class Rent;

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalId;
    AddressPtr address;
    ClientTypePtr clientType;
    bool archive = false;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId, AddressPtr address, ClientTypePtr clientType);

    virtual ~Client();

    std::string getClientInfo() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    AddressPtr getAddress() const;

    bool isArchive() const;

    unsigned int getMaxVehicles() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setAddress(AddressPtr address);

    void setClientType(ClientTypePtr clientType);

    void setArchive(bool archive);

    double applyDiscount(double price) const;


};


#endif //CARRENTAL_CLIENT_H
