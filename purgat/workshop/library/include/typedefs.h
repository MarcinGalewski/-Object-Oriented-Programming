//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <memory>

class Address;
class Bicycle;
class Car;
class Client;
class Moped;
class MotorVehicle;
class Rent;
class Vehicle;

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Moped> MopedPtr;
typedef std::shared_ptr<MotorVehicle> MotorVehiclePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;

class ClientType;

typedef std::shared_ptr<ClientType> ClientTypePtr;

class Default;
class Bronze;
class Silver;
class Gold;
class Platinum;
class Diamond;

typedef std::shared_ptr<Default> DefaultPtr;
typedef std::shared_ptr<Bronze> BronzePtr;
typedef std::shared_ptr<Silver> SilverPtr;
typedef std::shared_ptr<Gold> GoldPtr;
typedef std::shared_ptr<Platinum> PlatinumPtr;
typedef std::shared_ptr<Diamond> DiamondPtr;

typedef bool (*ClientPredicate)(ClientPtr);
typedef bool (*RentPredicate)(RentPtr);
typedef bool (*VehiclePredicate)(VehiclePtr);

class ClientRepository;
class RentRepository;
class VehicleRepository;

typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;

class StorageContainer;

typedef std::shared_ptr<StorageContainer> StorageContainerPtr;


#endif //CARRENTAL_TYPEDEFS_H
