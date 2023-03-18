//
// Created by student on 18.03.23.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "string"


class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalId;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId);
    virtual ~Client();

    std::string getClientInfo();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);


};


#endif //CARRENTAL_CLIENT_H
