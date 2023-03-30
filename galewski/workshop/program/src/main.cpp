#include <iostream>
#include "model/Client.h"
using namespace std;
int main() {
    Client first("Witold", "Nowak", "010101");
    Client* second = new Client("Grazyna", "Kowalska", "111111");

    cout << first.getClientInfo() << endl;
    cout << second->getClientInfo() << endl;

    first.setFirstName("");

    cout << first.getClientInfo() << endl;


    delete second;
    return 0;
}
