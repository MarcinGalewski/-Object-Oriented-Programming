//
// Created by student on 27.04.23.
//

#include "managers/LogicContainer.h"
#include "model/Default.h"
#include "model/Bicycle.h"
#include "model/Moped.h"

namespace gr = boost::gregorian;

LogicContainer::LogicContainer() {
    this->clientManager = std::make_shared<ClientManager>();
    this->vehicleManager = std::make_shared<VehicleManager>();
    this->rentManager = std::make_shared<RentManager>();

    clientManager->registerClient("Leon", "Zakrzewski", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"), std::make_shared<Default>());
    clientManager->registerClient("Judyta", "Kozlowska", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"), std::make_shared<Default>());

    vehicleManager->registerBicycle("EL 0101", 20);
    vehicleManager->registerMoped("EL 1010", 100, 1000);

    rentManager->rentVehicle(std::make_shared<Client>("Leon", "Zakrzewski", "010101", std::make_shared<Address>("London", "Accacia Avenue", "22"),std::make_shared<Default>()),
                             std::make_shared<Bicycle>("EL 0101", 20), pt::ptime(gr::date(2023, 1, 1), pt::hours(12) + pt::minutes(30)));
    rentManager->rentVehicle(std::make_shared<Client>("Judyta", "Kozlowska", "101010", std::make_shared<Address>("London", "Rue Morgue", "13"), std::make_shared<Default>()),
                             std::make_shared<Moped>("EL 1010", 100, 1000), pt::ptime(gr::date(2023, 1, 1), pt::hours(12) + pt::minutes(30)));
}

LogicContainer::~LogicContainer() {}

const ClientManagerPtr &LogicContainer::getClientManager() const {
    return clientManager;
}

const VehicleManagerPtr &LogicContainer::getVehicleManager() const {
    return vehicleManager;
}

const RentManagerPtr &LogicContainer::getRentManager() const {
    return rentManager;
}
