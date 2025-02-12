//
// Created by student on 12.06.23.
//

#include "managers/RentManager.h"
#include "model/Client.h"
#include "model/rooms/Room.h"
#include "model/clientTypes/RegularClient.h"
#include "exceptions/RentException.h"

void RentManager::changeClientType(const ClientPtr& client) {
    client->setClientType(std::make_shared<RegularClient>());
}

RentManager::RentManager() {
    this->rentRepository = std::make_shared<RentRepository>();
}

RentManager::~RentManager() = default;

std::vector<RentPtr> RentManager::getAllClientRents(const ClientPtr& client) {
    return rentRepository->findBy([client](const RentPtr& r){
        return r->getClient()->getPersonalId() == client->getPersonalId();
    });
}

RentPtr RentManager::rentRoom(const ClientPtr& client, const RoomPtr& room, unsigned int numberOfDays) {
    if(client->isArchived()) throw RentException("Client is archived");
    if(room->isArchived()) throw RentException("Room is archived");

    if(!client->isArchived() && !room->isArchived()){
        RentPtr newRent = std::make_shared<Rent>(boost::uuids::random_generator()(), client, room, numberOfDays);
        rentRepository->add(newRent);
        return  newRent;
    }
}

RentPtr RentManager::getRent(boost::uuids::uuid id) {
    return rentRepository->findBy([id](const RentPtr& r){
        return r->getId() == id;
    })[0];
}

std::vector<RentPtr> RentManager::findRents(RentPredicate predicate) {
    return rentRepository->findBy(predicate);
}

std::string RentManager::reportRents() {
    return rentRepository->report();
}
