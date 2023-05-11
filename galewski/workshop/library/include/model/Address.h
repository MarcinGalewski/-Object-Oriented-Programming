//
// Created by student on 27.04.23.
//

#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include "string"

class Address {
private:
    std::string city;
    std::string street;
    std::string number;

public:
    Address(const std::string &city, const std::string &street, const std::string &number);

    virtual ~Address();

    std::string getAddressInfo();

    const std::string &getCity() const;

    void setCity(const std::string &city);

    const std::string &getStreet() const;

    void setStreet(const std::string &street);

    const std::string &getNumber() const;

    void setNumber(const std::string &number);

};


#endif //CARRENTAL_Address_H
