//
// Created by student on 31.05.23.
//

#ifndef HOTEL_CLIENTTYPE_H
#define HOTEL_CLIENTTYPE_H

#include "string"

class ClientType {
public:
    virtual ~ClientType() = default;

    virtual double applyDiscount(double price) = 0;

    virtual std::string getInfo();
};


#endif //HOTEL_CLIENTTYPE_H
