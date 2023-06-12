//
// Created by student on 31.05.23.
//

#ifndef HOTEL_TYPEDEFS_H
#define HOTEL_TYPEDEFS_H

#include <functional>
#include "memory"

class Address;
class Client;
class ClientType;
class Rent;
class Room;

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Room> RoomPtr;

class StorageContainer;
class ClientRepository;
class RentRepository;

typedef std::shared_ptr<StorageContainer> StorageContainerPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;

class LogicContainer;
class ClientManager;
class RentManager;

typedef std::shared_ptr<LogicContainer> LogicContainerPtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;


typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;

#endif //HOTEL_TYPEDEFS_H
