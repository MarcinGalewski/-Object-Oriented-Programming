//
// Created by student on 31.05.23.
//

#include "model/Address.h"

Address::Address(const std::string &city, const std::string &street, const std::string &number) : city(city),
                                                                                                  street(street),
                                                                                                  number(number) {}

Address::~Address() {}

const std::string &Address::getCity() const {
    return city;
}

const std::string &Address::getStreet() const {
    return street;
}

const std::string &Address::getNumber() const {
    return number;
}

std::string Address::getInfo() const {
    return "Address: " + city + ", " + street + ", number: " + number;
}
