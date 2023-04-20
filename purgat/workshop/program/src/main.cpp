#include <iostream>

#include "repositories/StorageContainer.h"
#include "model/Moped.h"

using namespace std;

int main() {
    StorageContainerPtr storageContainer = new StorageContainer;
    cout << storageContainer->getClientRepository()->report() << endl << endl;
    cout << storageContainer->getVehicleRepository()->report() << endl << endl;
    cout << storageContainer->getRentRepository()->report() << endl << endl;

    storageContainer->getRentRepository()->add(
            new Rent(1, new Client("Antonina", "Kozlowska", "111111", new Address("London", "Accacia Avenue", "22")),
                     new Moped("EL 1001", 100, 1500),pt::not_a_date_time));

    cout << "---------------------------------------------------------\n";
    cout << storageContainer->getClientRepository()->report() << endl << endl;
    cout << storageContainer->getVehicleRepository()->report() << endl << endl;
    cout << storageContainer->getRentRepository()->report() << endl << endl;

    delete storageContainer;
    return 0;
}