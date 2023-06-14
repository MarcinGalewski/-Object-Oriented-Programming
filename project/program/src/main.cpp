#include "string"

#include "managers/LogicContainer.h"
#include "managers/ClientManager.h"
#include "model/Hotel.h"

using namespace std;

int main() {
    LogicContainer l;
    Hotel hotel("The Grand Hotel", l.getClientManager(), l.getRoomManager(), l.getRentManager());

    return 0;
}