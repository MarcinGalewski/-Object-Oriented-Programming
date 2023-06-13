//
// Created by student on 13.06.23.
//

#include "model/rooms/SingleRoom.h"

std::string SingleRoom::getInfo() {
    return "SingleRoom "+Room::getInfo();
}

SingleRoom::SingleRoom(const std::string &number, int price, int roomCapactiy, bool inArchived) : Room(number,price,
                                                                                                       roomCapactiy,
                                                                                                       inArchived
                                                                                                       ) {}
