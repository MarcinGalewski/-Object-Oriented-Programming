//
// Created by student on 12.06.23.
//

#ifndef HOTEL_FUNCTORS_H
#define HOTEL_FUNCTORS_H

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

#endif //HOTEL_FUNCTORS_H
