//
// Created by student on 14.06.23.
//

#ifndef HOTEL_ROOMEXCEPTION_H
#define HOTEL_ROOMEXCEPTION_H
#include <stdexcept>

class RoomException :public std::logic_error{
public:
    explicit RoomException(const std::string &arg);
};


#endif //HOTEL_ROOMEXCEPTION_H
