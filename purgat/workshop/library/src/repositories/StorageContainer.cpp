//
// Created by student on 14.04.23.
//
#include <boost/date_time.hpp>

#include "repositories/StorageContainer.h"

namespace pt = boost::posix_time;

StorageContainer::StorageContainer(){
    this->clientRepository = new ClientRepository();
    this->rentRepository = new RentRepository();
    this->vehicleRepository = new VehicleRepository();

    clientRepository->add(new Client("Leon", "Zakrzewski", "010101", new Address("London", "Accacia Avenue", "22")));
    clientRepository->add(new Client("Judyta", "Kozlowska", "101010", new Address("London", "Rue Morgue", "13")));

    vehicleRepository->add(new Vehicle("EL 0000", 100));
    vehicleRepository->add(new Vehicle("EL 1111", 200));

    rentRepository->add(new Rent(1, new Client("Leon", "Zakrzewski", "010101", new Address("London", "Accacia Avenue", "22")), new Vehicle("EL 0000", 100), pt::not_a_date_time));
    rentRepository->add(new Rent(2, new Client("Judyta", "Kozlowska", "101010", new Address("London", "Rue Morgue", "13")), new Vehicle("EL 1111", 200), pt::not_a_date_time));
}

StorageContainer::~StorageContainer(){
    delete clientRepository;
    delete rentRepository;
    delete vehicleRepository;
}

ClientRepositoryPtr StorageContainer::getClientRepository() {
    return clientRepository;
}

RentRepositoryPtr StorageContainer::getRentRepository() {
    return rentRepository;
}

VehicleRepositoryPtr StorageContainer::getVehicleRepository() {
    return vehicleRepository;
}
