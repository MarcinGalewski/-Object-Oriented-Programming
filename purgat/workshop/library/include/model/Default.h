//
// Created by student on 26.04.23.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "ClientType.h"

class Default : public ClientType{
public:
    Default() = default;
    unsigned int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getTypeInfo() const override;

};


#endif //CARRENTAL_DEFAULT_H
