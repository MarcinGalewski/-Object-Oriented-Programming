//
// Created by student on 12.06.23.
//
#include "managers/LogicContainer.h"
#include "managers/ClientManager.h"
#include "managers/RoomManager.h"
#include "managers/RentManager.h"
#include "model/Address.h"
#include "model/clientTypes/RegularClient.h"
#include "model/clientTypes/DefaultClient.h"
#include "model/rooms/Apartment.h"

LogicContainer::LogicContainer() {
    this->clientManager = std::make_shared<ClientManager>();
    this->roomManager = std::make_shared<RoomManager>();
    this->rentManager = std::make_shared<RentManager>();

    clientManager->registerClient("John", "Doe", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                  std::make_shared<DefaultClient>());
    clientManager->registerClient("Sarah", "Smith", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"),
                                  std::make_shared<RegularClient>());

    roomManager->registerDouble("12", 200, 3, QueenSize);
    roomManager->registerApartment("13", 300, 2, 5);

    rentManager->rentRoom(std::make_shared<Client>("John", "Doe", "010101",
                                                    std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                                    std::make_shared<DefaultClient>()),
                                                    std::make_shared<DoubleRoom>("12", 200, 3, QueenSize), 3);
    rentManager->rentRoom(std::make_shared<Client>("Sarah", "Smith", "101010",
                                                    std::make_shared<Address>("London", "Rue Morgue", "13"),
                                                    std::make_shared<RegularClient>()),
                                                    std::make_shared<Apartment>("13", 300, 2, 5), 4);
}

LogicContainer::~LogicContainer() {}

const ClientManagerPtr &LogicContainer::getClientManager() const {
    return clientManager;
}

const RoomManagerPtr &LogicContainer::getRoomManager() const {
    return roomManager;
}

const RentManagerPtr &LogicContainer::getRentManager() const {
    return rentManager;
}
