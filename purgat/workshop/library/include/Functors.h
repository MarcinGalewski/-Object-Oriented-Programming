//
// Created by student on 03.05.23.
//

#ifndef CARRENTAL_FUNCTORS_H
#define CARRENTAL_FUNCTORS_H

#include "typedefs.h"
#include "model/Client.h"

class FirstNamePredicate {
private:
    std::string firstName;

public:
    explicit FirstNamePredicate(const std::string &firstName) : firstName(firstName) {}

    bool operator()(const ClientPtr &client) const{
        return client->getFirstName() == firstName;
    }
};

class LastNamePredicate {
private:
    std::string lastName;

public:
    explicit LastNamePredicate(const std::string &lastName) : lastName(lastName) {}

    bool operator()(const ClientPtr &client) const{
        return client->getLastName() == lastName;
    }
};

#endif //CARRENTAL_FUNCTORS_H
