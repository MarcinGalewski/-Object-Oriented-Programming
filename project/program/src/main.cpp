#include <iostream>
#include "managers/LogicContainer.h"
#include "model/rooms/SingleRoom.h"
#include "string"
#include "model/rooms/DoubleRoom.h"
#include "model/rooms/Apartment.h"

using namespace std;

int main() {
    LogicContainer l;
    cout << l.getClientManager()->reportClients();
    SingleRoom r1("221B", 120, 1);
    DoubleRoom r2("121C", 200, 2,QueenSize);
    DoubleRoom r3("53D", 250, 2,KingSize);
    Apartment r4("321A", 1000, 4,5);
    cout << r1.getInfo()<<endl;
    cout << r2.getInfo()<<endl;
    cout << r3.getInfo()<<endl;
    cout << r4.getInfo()<<endl;

    return 0;
}