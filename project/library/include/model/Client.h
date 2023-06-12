//
// Created by student on 31.05.23.
//

#ifndef HOTEL_CLIENT_H
#define HOTEL_CLIENT_H

#include "string"

#include "typedefs.h"

class Client {
private:
   std::string firstName;
   std::string lastName;
   std::string personalId;
   bool archived = false;
   AddressPtr address;
   ClientTypePtr clientType;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           const AddressPtr &address, const ClientTypePtr &clientType);

    virtual ~Client();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    const std::string &getId() const;

    bool isArchived() const;

    const AddressPtr &getAddress() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setArchived(bool archived);

    void setAddress(const AddressPtr &address);

    void setClientType(const ClientTypePtr &clientType);

    double applyDiscount(double price);

    std::string getInfo() const;
};


#endif //HOTEL_CLIENT_H
