//
// Created by student on 26.04.23.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H


#include "ClientType.h"

class Platinum : public ClientType{
public:
    Platinum() = default;
    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getTypeInfo() const override;
};


#endif //CARRENTAL_PLATINUM_H
