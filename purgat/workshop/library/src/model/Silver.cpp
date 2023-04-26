//
// Created by student on 26.04.23.
//

#include "model/Silver.h"

unsigned int Silver::getMaxVehicles() const {
    return 3;
}

double Silver::applyDiscount(double price) const {
    return 6;
}

std::string Silver::getTypeInfo() const {
    return ClientType::getTypeInfo() + "Silver.\n";
}
