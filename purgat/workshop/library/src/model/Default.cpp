//
// Created by student on 26.04.23.
//

#include "model/Default.h"

unsigned int Default::getMaxVehicles() const {
    return 1;
}

double Default::applyDiscount(double price) const {
    return 0;
}

std::string Default::getTypeInfo() const {
    return ClientType::getTypeInfo() + "Default.\n";
}

