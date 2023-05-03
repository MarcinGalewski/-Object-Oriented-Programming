//
// Created by student on 02.05.23.
//

#ifndef CARRENTAL_VEHICLEEXCEPTION_H
#define CARRENTAL_VEHICLEEXCEPTION_H

#include <stdexcept>

class VehicleException : public std::logic_error{
public:
    explicit VehicleException(const std::string &arg);
};


#endif //CARRENTAL_VEHICLEEXCEPTION_H
