//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

class Address;
class Client;
class Rent;
class Vehicle;

typedef Address *AddressPtr;
typedef Client *ClientPtr;
typedef Rent *RentPtr;
typedef Vehicle *VehiclePtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*RentPredicate)(RentPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);

class ClientRepository;
class RentRepository;
class VehicleRepository;

typedef ClientRepository *ClientRepositoryPtr;
typedef RentRepository *RentRepositoryPtr;
typedef VehicleRepository *VehicleRepositoryPtr;

class StorageContainer;

typedef StorageContainer *StorageContainerPtr;


#endif //CARRENTAL_TYPEDEFS_H
