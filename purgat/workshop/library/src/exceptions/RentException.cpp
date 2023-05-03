//
// Created by student on 02.05.23.
//

#include "exceptions/RentException.h"

RentException::RentException(const std::string &arg) : logic_error(arg) {}
