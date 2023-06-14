//
// Created by student on 14.06.23.
//
#include "iostream"
#include "model/Hotel.h"
#include "managers/ClientManager.h"
#include "managers/RoomManager.h"
#include "managers/RentManager.h"

Hotel::Hotel(const std::string &name, const ClientManagerPtr &clientManager, const RoomManagerPtr &roomManager,
             const RentManagerPtr &rentManager) : name(name), clientManager(clientManager), roomManager(roomManager),
             rentManager(rentManager){
    std::cout << "Hotel: " + name << "\n--------------------------------------------------------\n";
    std::cout << "Our clients: \n" << clientManager->reportClients() << std::endl;
    std::cout << "Our Rooms: \n" << roomManager->reportRooms() << std::endl;
}

const ClientManagerPtr &Hotel::getClientManager() const {
    return clientManager;
}

const RentManagerPtr &Hotel::getRentManager() const {
    return rentManager;
}

const RoomManagerPtr &Hotel::getRoomManager() const {
    return roomManager;
}


