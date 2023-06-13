//
// Created by student on 13.06.23.
//

#include <ios>
#include "model/rooms/Room.h"


const std::string &Room::getNumber() const {
    return number;
}

int Room::getRoomCapactiy() const {
    return roomCapactiy;
}

bool Room::isInArchived() const {
    return inArchived;
}

int Room::getPrice() const {
    return price;
}

std::string Room::getInfo() {
    return number+" has capacity: "+ std::to_string(roomCapactiy)+" and "+ (inArchived ? "is archived" : "is not archived") +". Price for this room is: "+
                                                                                                                       std::to_string(price)+".";
}

Room::Room(const std::string &number, int price, int roomCapactiy, bool inArchived) : number(number),price(price),
                                                                                      roomCapactiy(roomCapactiy),
                                                                                      inArchived(inArchived)
                                                                                       {}
