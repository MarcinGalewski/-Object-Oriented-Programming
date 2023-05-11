//
// Created by student on 27.04.23.
//
#include <iostream>
#include "model/Address.h"
using namespace std;

Address::Address(const string &city, const string &street, const string &number) : city(city), street(street),
                                                                                   number(number) {}

Address::~Address() {

}

const string &Address::getCity() const {
    return city;
}

void Address::setCity(const string &city) {
    Address::city = city;
}

const string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &street) {
    Address::street = street;
}

const string &Address::getNumber() const {
    return number;
}

void Address::setNumber(const string &number) {
    Address::number = number;
}

std::string Address::getAddressInfo() {
    return "Address:  city: "+ city + ", street: " + street+ ", number: " + number;
}
