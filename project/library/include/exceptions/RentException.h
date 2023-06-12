//
// Created by student on 12.06.23.
//

#ifndef HOTEL_RENTEXCEPTION_H
#define HOTEL_RENTEXCEPTION_H

#include <stdexcept>

class RentException : public std::logic_error{
public:
    explicit RentException(const std::string &arg);
};



#endif //HOTEL_RENTEXCEPTION_H
