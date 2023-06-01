//
// Created by student on 01.06.23.
//

#include "exceptions/ClientException.h"

ClientException::ClientException(const std::string &arg) : logic_error(arg) {}
