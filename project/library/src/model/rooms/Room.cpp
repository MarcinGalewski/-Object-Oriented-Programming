//
// Created by student on 13.06.23.
//

#include <ios>
#include "model/rooms/Room.h"


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

Room::Room(const std::string &number, int price, int roomCapacity) : number(number),price(price),roomCapacity(roomCapacity){}
const std::string &Room::getId() const {
    return number;
}

void Room::setNumber(const std::string &number) {
    Room::number = number;
}

void Room::setRoomCapacity(int roomCapacity) {
    Room::roomCapacity = roomCapacity;
}

void Room::setArchived(bool archived) {
    Room::archived = archived;
}

void Room::setPrice(int price) {
    Room::price = price;
}
