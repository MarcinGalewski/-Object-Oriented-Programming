//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H

#include <memory>
#include <functional>

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

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;
typedef std::function<bool(VehiclePtr)> VehiclePredicate;

class ClientRepository;
class RentRepository;
class VehicleRepository;

typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<RentRepository> RentRepositoryPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepositoryPtr;

class StorageContainer;

typedef std::shared_ptr<StorageContainer> StorageContainerPtr;

class LogicContainer;
class ClientManager;
class VehicleManager;
class RentManager;

typedef std::shared_ptr<LogicContainer> LogicContainerPtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<VehicleManager> VehicleManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;



#endif //CARRENTAL_TYPEDEFS_H
