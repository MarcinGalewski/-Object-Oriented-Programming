//
// Created by student on 02.05.23.
//

#include "exceptions/ClientException.h"

ClientException::ClientException(const std::string &arg) : logic_error(arg) {}
