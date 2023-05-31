//
// Created by student on 31.05.23.
//

#ifndef HOTEL_ADDRESS_H
#define HOTEL_ADDRESS_H

#include "string"

class Address {
private:
    std::string city;
    std::string street;
    std::string number;

public:
    Address(const std::string &city, const std::string &street, const std::string &number);

    virtual ~Address();

    const std::string &getCity() const;

    const std::string &getStreet() const;

    const std::string &getNumber() const;
};


#endif //HOTEL_ADDRESS_H
