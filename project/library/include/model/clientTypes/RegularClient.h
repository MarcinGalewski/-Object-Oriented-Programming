//
// Created by student on 31.05.23.
//

#ifndef HOTEL_REGULARCLIENT_H
#define HOTEL_REGULARCLIENT_H


#include "ClientType.h"

class RegularClient : public ClientType{
public:
    RegularClient() = default;

    ~RegularClient() override = default;

    double applyDiscount(double price) override;

    std::string getInfo() override;

};


#endif //HOTEL_REGULARCLIENT_H
