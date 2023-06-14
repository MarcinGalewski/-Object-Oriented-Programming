//
// Created by student on 13.06.23.
//

#include "model/rooms/DoubleRoom.h"
#include "string"
#include "exceptions/RoomException.h"

DoubleRoom::~DoubleRoom() = default;

std::string DoubleRoom::getInfo() {
    return "DoubleRoom "+Room::getInfo()+" Room has "+ (bedType ? "QueenSize" : "KingSize")+ " bed";
}

DoubleRoom::DoubleRoom(const std::string &number, int price, int roomCapacity, BedType bedType)
        : Room(number, price,roomCapacity), bedType(bedType) {
    if (bedType!=0 && bedType !=1)
        throw RoomException("Incorrect room bedType");
}

BedType DoubleRoom::getBedType() const {
    return bedType;
}

void DoubleRoom::setBedType(BedType bedType) {
    if(bedType!= 0 && bedType != 1)
        throw RoomException("Incorrect betType");
    DoubleRoom::bedType = bedType;
}

int DoubleRoom::getActualPrice() {
    return (bedType==QueenSize) ? (price * 1.1) : (price * 1.2);
}


