//
// Created by student on 26.04.23.
//

#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "ClientType.h"

class Diamond : public ClientType{
public:
    Diamond() = default;
    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getTypeInfo() const override;
};


#endif //CARRENTAL_DIAMOND_H
