//
// Created by student on 13.06.23.
//

#include "model/rooms/SingleRoom.h"
#include "exceptions/RoomException.h"

std::string SingleRoom::getInfo() {
    return "SingleRoom "+Room::getInfo();
}

SingleRoom::SingleRoom(const std::string &number, int price, int roomCapacity) : Room(number,price,roomCapacity) {

}

int SingleRoom::getActualPrice() {
    return price;
}
