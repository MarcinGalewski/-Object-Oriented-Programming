#include <iostream>

#include "typedefs.h"
#include "managers/LogicContainer.h"
#include "model/Client.h"
#include "model/Default.h"
#include "model/Moped.h"

using namespace std;
namespace gr = boost::gregorian;

int main() {
    LogicContainerPtr logicContainer = make_shared<LogicContainer>();

    AddressPtr address = std::make_shared<Address>("London", "Accacia Avenue", "22");
    ClientTypePtr clientType = std::make_shared<Default>();

    ClientPtr client = logicContainer->getClientManager()->registerClient("Antonina", "Kozlowska", "111111", address, clientType);
    VehiclePtr vehicle = logicContainer->getVehicleManager()->registerMoped("EL 1111", 150, 1500);
    RentPtr rent = logicContainer->getRentManager()->rentVehicle(client, vehicle, pt::ptime(gr::date(2023, 1, 1), pt::hours(12) + pt::minutes(30)));

    logicContainer->getRentManager()->returnVehicle(logicContainer->getRentManager()->getVehicleRent(make_shared<Moped>("EL 1010", 100, 1000))->getVehicle());

    cout << logicContainer->getClientManager()->findClients([](ClientPtr c){return true;}).size() << endl;
    cout << logicContainer->getVehicleManager()->getVehicle("EL 0101")->getVehicleInfo() << endl;
    cout << logicContainer->getRentManager()->findAllRents().size();

    return 0;
}