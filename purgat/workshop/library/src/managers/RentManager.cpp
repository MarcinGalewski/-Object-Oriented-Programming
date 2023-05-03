//
// Created by student on 01.05.23.
//

#include "managers/RentManager.h"
#include "model/Default.h"
#include "model/Bronze.h"
#include "model/Silver.h"
#include "model/Gold.h"
#include "model/Platinum.h"
#include "model/Diamond.h"
#include "exceptions/RentException.h"

RentManager::RentManager() {
    this->currentRents = std::make_shared<RentRepository>();
    this->archiveRents = std::make_shared<RentRepository>();
}

RentManager::~RentManager() {}

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) {
    return currentRents->findBy([client](RentPtr r){
        return r->getClient()->getPersonalId() == client->getPersonalId();
    });
}

RentPtr RentManager::getVehicleRent(VehiclePtr vehicle) {
    std::vector<RentPtr> foundRents =  currentRents->findBy([vehicle](RentPtr r){
        return r->getVehicle()->getPlateNumber() == vehicle->getPlateNumber();
    });
    if(!foundRents.empty()){
        return foundRents[0];
    } else
        return nullptr;
}

std::vector<RentPtr> RentManager::findRent(RentPredicate predicate) {
    return currentRents->findBy(predicate);
}

std::vector<RentPtr> RentManager::findAllRents() {
    return currentRents->findBy([](RentPtr r){return true;});
}

double RentManager::checkClientRentBalance(ClientPtr client) {
    std::vector<RentPtr> clientRents = archiveRents->findBy([client](RentPtr r){
        return r->getClient()->getPersonalId() == client->getPersonalId();
    });
    double clientBalance = 0;
    for(int i = 0; i < clientRents.size(); i++){
        clientBalance += clientRents[i]->getRentCost();
    }
    return clientBalance;
}

RentPtr RentManager::rentVehicle(ClientPtr client, VehiclePtr vehicle, pt::ptime beginTime) {
    if(client->isArchive()) throw RentException("Client is archived");
    if(vehicle->isArchive()) throw RentException("Vehicle is archived");
    if(getAllClientRents(client).size() >= client->getMaxVehicles()) throw RentException("Client is over the rent limit");
    if(getVehicleRent(vehicle)) throw RentException("Vehicle is already rented");

    if(!client->isArchive() && !vehicle->isArchive() &&
    getAllClientRents(client).size() < client->getMaxVehicles() &&
    !getVehicleRent(vehicle)){
        RentPtr newRent = std::make_shared<Rent>(boost::uuids::random_generator()(), client, vehicle, beginTime);
        currentRents->add(newRent);
        return  newRent;
    }
}

void RentManager::returnVehicle(VehiclePtr vehicle) {
    RentPtr vehicleRent = getVehicleRent(vehicle);
    if(vehicleRent){
        archiveRents->add(vehicleRent);
        vehicleRent->endRent(pt::not_a_date_time);
        currentRents->remove(vehicleRent);
        changeClientType(vehicleRent->getClient());
    }
}

void RentManager::changeClientType(ClientPtr client) {
    double balance = checkClientRentBalance(client);
    if(balance >= 1600) client->setClientType(std::make_shared<Diamond>());
    else if(balance >= 800) client->setClientType(std::make_shared<Platinum>());
    else if(balance >= 400) client->setClientType(std::make_shared<Gold>());
    else if(balance >= 200) client->setClientType(std::make_shared<Silver>());
    else if(balance >= 100) client->setClientType(std::make_shared<Bronze>());
    else client->setClientType(std::make_shared<Default>());
}

