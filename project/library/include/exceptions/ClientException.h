//
// Created by student on 01.06.23.
//

#ifndef HOTEL_CLIENTEXCEPTION_H
#define HOTEL_CLIENTEXCEPTION_H

#include <stdexcept>

class ClientException : public std::logic_error{
public:
    explicit ClientException(const std::string &arg);
};


#endif //HOTEL_CLIENTEXCEPTION_H
