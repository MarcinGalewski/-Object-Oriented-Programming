//
// Created by student on 31.05.23.
//

#include "model/clientTypes/DefaultClient.h"

double DefaultClient::applyDiscount(double price) {
    return 0;
}

std::string DefaultClient::getInfo() {
    return ClientType::getInfo() + "Default";
}
