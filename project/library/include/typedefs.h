//
// Created by student on 31.05.23.
//

#ifndef HOTEL_TYPEDEFS_H
#define HOTEL_TYPEDEFS_H

#include "memory"

class Address;
class Client;
class ClientType;

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;

#endif //HOTEL_TYPEDEFS_H
