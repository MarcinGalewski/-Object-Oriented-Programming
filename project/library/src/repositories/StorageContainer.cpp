//
// Created by student on 12.06.23.
//

#include "repositories/StorageContainer.h"
#include "model/clientTypes/DefaultClient.h"
#include "model/clientTypes/RegularClient.h"
#include "model/Address.h"

StorageContainer::StorageContainer(){
    this->clientRepository = std::make_shared<ClientRepository>();

    clientRepository->add(std::make_shared<Client>("John", "Doe", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                                   std::make_shared<DefaultClient>()));
    clientRepository->add(std::make_shared<Client>("Sarah", "Smith", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"),
                                                   std::make_shared<RegularClient>()));
}

StorageContainer::~StorageContainer(){}

ClientRepositoryPtr StorageContainer::getClientRepository() {
    return clientRepository;
}
