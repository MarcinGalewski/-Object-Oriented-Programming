//
// Created by student on 26.04.23.
//

#include "model/Gold.h"

unsigned int Gold::getMaxVehicles() const {
    return 4;
}

double Gold::applyDiscount(double price) const {
    return price * 0.05;
}

std::string Gold::getTypeInfo() const {
    return ClientType::getTypeInfo() + "Gold.\n";
}
