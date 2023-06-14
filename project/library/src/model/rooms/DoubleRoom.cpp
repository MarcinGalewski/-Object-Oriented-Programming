//
// Created by student on 13.06.23.
//

#include "model/rooms/DoubleRoom.h"
#include "string"

DoubleRoom::~DoubleRoom() {

}

std::string DoubleRoom::getInfo() {
    return "DoubleRoom "+Room::getInfo()+" Room has "+ (bedType ? "QueenSize" : "KingSize")+ " bed";
}

DoubleRoom::DoubleRoom(const std::string &number, int price, int roomCapacity, BedType bedType)
    : Room(number, price, roomCapacity), bedType(bedType) {}

int DoubleRoom::getActualPrice() {
    if(bedType == QueenSize)
        return price * 1.1;
    if(bedType == KingSize)
        return price * 1.2;
}


