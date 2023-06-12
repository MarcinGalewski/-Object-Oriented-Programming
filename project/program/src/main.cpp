#include <iostream>
#include "managers/LogicContainer.h"

using namespace std;

int main() {
    LogicContainer l;
    cout << l.getClientManager()->reportClients();
    return 0;
}