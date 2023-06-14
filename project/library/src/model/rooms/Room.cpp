//
// Created by student on 13.06.23.
//

#include "model/rooms/Room.h"
#include "exceptions/RoomException.h"


const std::string &Room::getNumber() const {
    return number;
}

int Room::getRoomCapacity() const {
    return roomCapacity;
}

bool Room::isArchived() const {
    return archived;
}

int Room::getPrice() const {
    return price;
}

std::string Room::getInfo() {
    return number+" has capacity: "+ std::to_string(roomCapacity)+". Price for this room is: "+std::to_string(price)+".";
}

Room::Room(const std::string &number, int price, int roomCapacity) : number(number),price(price),roomCapacity(roomCapacity){
    if(number.empty())
        throw RoomException("Incorrect room number");
    if(price<50 || price > 1000 )
        throw RoomException("Incorrect room price");
    if (roomCapacity<1 || roomCapacity > 5)
        throw RoomException("Incorrect room capacity");
}
const std::string &Room::getId() const {
    return number;
}

void Room::setNumber(const std::string &number) {
    if(number.empty())
        throw RoomException("Incorrect room number");
    Room::number = number;
}

void Room::setRoomCapacity(int roomCapacity) {
    if(roomCapacity<1 || roomCapacity > 5)
        throw RoomException("Incorrect room capacity");
    Room::roomCapacity = roomCapacity;
}

void Room::setArchived(bool archived) {
    Room::archived = archived;
}

void Room::setPrice(int price) {
    if(price<50 || price > 1000)
        throw RoomException("Incorrect room price");
    Room::price = price;
}