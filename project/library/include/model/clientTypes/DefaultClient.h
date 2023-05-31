//
// Created by student on 31.05.23.
//

#ifndef HOTEL_DEFAULTCLIENT_H
#define HOTEL_DEFAULTCLIENT_H


#include "ClientType.h"

class DefaultClient : public ClientType{
public:
    DefaultClient() = default;

    ~DefaultClient() override = default;

    double applyDiscount(double price) override;

    std::string getInfo() override;
};


#endif //HOTEL_DEFAULTCLIENT_H
