//
// Created by student on 31.05.23.
//

#include "model/clientTypes/RegularClient.h"

double RegularClient::applyDiscount(double price) {
    return price * 0.2;
}

std::string RegularClient::getInfo() {
    return ClientType::getInfo() + "Regular\n";
}
