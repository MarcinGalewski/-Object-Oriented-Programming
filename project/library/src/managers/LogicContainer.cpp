//
// Created by student on 12.06.23.
//
#include "managers/LogicContainer.h"
#include "model/Address.h"
#include "model/clientTypes/RegularClient.h"
#include "model/clientTypes/DefaultClient.h"

LogicContainer::LogicContainer() {
    this->clientManager = std::make_shared<ClientManager>();

    clientManager->registerClient("John", "Doe", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                  std::make_shared<DefaultClient>());
    clientManager->registerClient("Sarah", "Smith", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"),
                                  std::make_shared<RegularClient>());
}

LogicContainer::~LogicContainer() {}

const ClientManagerPtr &LogicContainer::getClientManager() const {
    return clientManager;
}
