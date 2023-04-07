//
// Created by student on 30.03.23.
//

#include "model/Address.h"

Address::Address(const std::string &city,
                 const std::string &street,
                 const std::string &number) :
                 city(city),
                 street(street),
                 number(number) {}

Address::~Address() {

}

std::string Address::getAddressInfo() const{
    return "Address: " + city + ", " + street + ", number: " + number;
}

const std::string &Address::getCity() const {
    return city;
}

const std::string &Address::getStreet() const {
    return street;
}

const std::string &Address::getNumber() const {
    return number;
}



