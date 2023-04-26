#include <iostream>

#include "repositories/StorageContainer.h"
#include "model/Moped.h"
#include "model/Bronze.h"

using namespace std;

int main() {
    StorageContainerPtr storageContainer = make_shared<StorageContainer>();
    cout << storageContainer->getClientRepository()->report() << endl << endl;
    cout << storageContainer->getVehicleRepository()->report() << endl << endl;
    cout << storageContainer->getRentRepository()->report() << endl << endl;

    storageContainer->getRentRepository()->add(
            make_shared<Rent>(1, make_shared<Client>("Antonina", "Kozlowska", "111111", make_shared<Address>("London", "Accacia Avenue", "22"),
                                                     make_shared<Bronze>()),
                     make_shared<Moped>("EL 1001", 100, 1500),pt::not_a_date_time));

    cout << "---------------------------------------------------------\n";
    cout << storageContainer->getClientRepository()->report() << endl << endl;
    cout << storageContainer->getVehicleRepository()->report() << endl << endl;
    cout << storageContainer->getRentRepository()->report() << endl << endl;

    return 0;
}