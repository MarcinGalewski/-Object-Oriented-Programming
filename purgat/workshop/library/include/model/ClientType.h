//
// Created by student on 26.04.23.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>

class ClientType {
public:
    virtual ~ClientType() = default;
    virtual unsigned int getMaxVehicles() const = 0;
    virtual double applyDiscount(double price) const = 0;
    virtual std::string getTypeInfo() const;
};


#endif //CARRENTAL_CLIENTTYPE_H
