//
// Created by student on 13.06.23.
//

#include "model/rooms/Apartment.h"
#include "exceptions/RoomException.h"

Apartment::Apartment(const std::string &number, int price,int roomCapacity, int numberOfAmenities )
        : Room(number, price,roomCapacity), numberOfAmenities(numberOfAmenities) {
    if(numberOfAmenities<0 || numberOfAmenities > 9)
        throw RoomException("Incorrect numberOfAmenities");
}

Apartment::~Apartment() = default;

std::string Apartment::getInfo() {
    return "Apartment "+Room::getInfo()+" Apartment has "+ std::to_string(numberOfAmenities)+" amenities";
}

int Apartment::getNumberOfAmenities() const {
    return numberOfAmenities;
}

void Apartment::setNumberOfAmenities(int numberOfAmenities) {
    if(numberOfAmenities<0 || numberOfAmenities > 9)
        throw RoomException("Incorrect numberOfAmenities");
    Apartment::numberOfAmenities = numberOfAmenities;
}

int Apartment::getActualPrice() {
    return price + (10 * numberOfAmenities);
}
