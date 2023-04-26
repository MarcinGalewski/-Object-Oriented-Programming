//
// Created by student on 26.04.23.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H


#include "ClientType.h"

class Gold : public ClientType{
public:
    Gold() = default;
    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getTypeInfo() const override;
};


#endif //CARRENTAL_GOLD_H
