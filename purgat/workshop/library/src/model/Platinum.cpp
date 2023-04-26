//
// Created by student on 26.04.23.
//

#include "model/Platinum.h"

unsigned int Platinum::getMaxVehicles() const {
    return 5;
}

double Platinum::applyDiscount(double price) const {
    return price * 0.1;
}

std::string Platinum::getTypeInfo() const {
    return ClientType::getTypeInfo() + "Platinum.\n";
}
