//
// Created by student on 14.04.23.
//
#include <boost/date_time.hpp>

#include "repositories/StorageContainer.h"
#include "model/Default.h"

namespace pt = boost::posix_time;

StorageContainer::StorageContainer(){
    this->clientRepository = std::make_shared<ClientRepository>();
    this->rentRepository = std::make_shared<RentRepository>();
    this->vehicleRepository = std::make_shared<VehicleRepository>();

    clientRepository->add(std::make_shared<Client>("Leon", "Zakrzewski", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"), std::make_shared<Default>()));
    clientRepository->add(std::make_shared<Client>("Judyta", "Kozlowska", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"), std::make_shared<Default>()));

    vehicleRepository->add(std::make_shared<Vehicle>("EL 0000", 100));
    vehicleRepository->add(std::make_shared<Vehicle>("EL 1111", 200));

    rentRepository->add(std::make_shared<Rent>(boost::uuids::random_generator()(), std::make_shared<Client>("Leon", "Zakrzewski", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"), std::make_shared<Default>()), std::make_shared<Vehicle>("EL 0000", 100), pt::not_a_date_time));
    rentRepository->add(std::make_shared<Rent>(boost::uuids::random_generator()(), std::make_shared<Client>("Judyta", "Kozlowska", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"), std::make_shared<Default>()), std::make_shared<Vehicle>("EL 1111", 200), pt::not_a_date_time));
}

StorageContainer::~StorageContainer(){}

ClientRepositoryPtr StorageContainer::getClientRepository() {
    return clientRepository;
}

RentRepositoryPtr StorageContainer::getRentRepository() {
    return rentRepository;
}

VehicleRepositoryPtr StorageContainer::getVehicleRepository() {
    return vehicleRepository;
}
