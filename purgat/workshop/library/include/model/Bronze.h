//
// Created by student on 26.04.23.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "ClientType.h"

class Bronze : public ClientType{
public:
    Bronze() = default;
    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getTypeInfo() const override;
};


#endif //CARRENTAL_BRONZE_H
