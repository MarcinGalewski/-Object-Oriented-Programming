//
// Created by student on 18.03.23.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "string"
#include "model/Address.h"


class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalId;
    Address *address;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId, Address *address);

    virtual ~Client();

    std::string getClientInfo() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    Address *getAddress() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setAddress(Address *address);


};


#endif //CARRENTAL_CLIENT_H
