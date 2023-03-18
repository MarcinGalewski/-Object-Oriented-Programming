#include <iostream>
#include "model/Client.h"

using namespace std;

int main() {
    Client first("Leon", "Zakrzewski", "010101"); // constructs and destructs
    Client* second = new Client("Judyta", "Kozlowska", "111111"); // just constructs

    cout << first.getClientInfo() << endl;
    cout << second->getClientInfo() << endl;

    first.setFirstName("");

    cout << first.getClientInfo() << endl;


    delete second;
    return 0;
}