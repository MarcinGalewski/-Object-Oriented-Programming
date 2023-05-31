//
// Created by student on 31.05.23.
//

#include "model/clientTypes/DefaultClient.h"

double DefaultClient::applyDiscount(double price) {
    return price;
}

std::string DefaultClient::getInfo() {
    return ClientType::getInfo() + "Default\n";
}
