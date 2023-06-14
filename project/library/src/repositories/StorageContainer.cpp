//
// Created by student on 12.06.23.
//

#include "repositories/StorageContainer.h"
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/RoomRepository.h"
#include "model/clientTypes/DefaultClient.h"
#include "model/clientTypes/RegularClient.h"
#include "model/Address.h"
#include "model/rooms/DoubleRoom.h"
#include "model/rooms/Apartment.h"

StorageContainer::StorageContainer(){
    this->clientRepository = std::make_shared<ClientRepository>();
    this->roomRepository = std::make_shared<RoomRepository>();
    this->rentRepository = std::make_shared<RentRepository>();

    clientRepository->add(std::make_shared<Client>("John", "Doe", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                                   std::make_shared<DefaultClient>()));
    clientRepository->add(std::make_shared<Client>("Sarah", "Smith", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"),
                                                   std::make_shared<RegularClient>()));

    roomRepository->add(std::make_shared<DoubleRoom>("12", 200, 3, QueenSize));
    roomRepository->add(std::make_shared<Apartment>("13", 300, 2, 5));

    rentRepository->add(std::make_shared<Rent>(boost::uuids::random_generator()(),
                                                std::make_shared<Client>("John", "Doe", "010101",
                                                std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                                std::make_shared<DefaultClient>()),
                                                std::make_shared<DoubleRoom>("12", 200, 3, QueenSize), 3));
    rentRepository->add(std::make_shared<Rent>(boost::uuids::random_generator()(),
                                                std::make_shared<Client>("Sarah", "Smith", "101010",
                                                std::make_shared<Address>("London", "Rue Morgue", "13"),
                                                std::make_shared<RegularClient>()),
                                                std::make_shared<Apartment>("13", 300, 2, 5), 4));
}

StorageContainer::~StorageContainer(){}

ClientRepositoryPtr StorageContainer::getClientRepository() {
    return clientRepository;
}

const RentRepositoryPtr &StorageContainer::getRentRepository() const {
    return rentRepository;
}

const RoomRepositoryPtr &StorageContainer::getRoomRepository() const {
    return roomRepository;
}
