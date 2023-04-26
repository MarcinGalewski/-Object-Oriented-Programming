//
// Created by student on 26.04.23.
//

#include "model/Bronze.h"

unsigned int Bronze::getMaxVehicles() const {
    return 2;
}

double Bronze::applyDiscount(double price) const {
    return 3;
}

std::string Bronze::getTypeInfo() const {
    return ClientType::getTypeInfo() + "Bronze.\n";
}
