//
// Created by student on 31.05.23.
//

#ifndef INTRODUCTIONPROJECT_CLIENT_H
#define INTRODUCTIONPROJECT_CLIENT_H

#include "string"

#include "typedefs.h"

class Client {
private:
   std::string firstName;
   std::string lastName;
   std::string personalId;
   bool isArchived;
   AddressPtr address;
   ClientTypePtr clientType;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           const AddressPtr &address, const ClientTypePtr &clientType);

    virtual ~Client();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    bool isArchived1() const;

    const AddressPtr &getAddress() const;

    const ClientTypePtr &getClientType() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    void setIsArchived(bool isArchived);

    void setAddress(const AddressPtr &address);

    void setClientType(const ClientTypePtr &clientType);
};


#endif //INTRODUCTIONPROJECT_CLIENT_H
