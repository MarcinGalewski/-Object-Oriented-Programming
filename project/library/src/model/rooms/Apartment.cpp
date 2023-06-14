//
// Created by student on 13.06.23.
//

#include "model/rooms/Apartment.h"

Apartment::Apartment(const std::string &number, int price,int roomCapactiy, int numberOfAmenities )
        : Room(number, price,roomCapactiy), numberOfAmenities(numberOfAmenities) {}

Apartment::~Apartment() {

}

std::string Apartment::getInfo() {
    return "Apartment "+Room::getInfo()+" Apartment has "+ std::to_string(numberOfAmenities)+" amenities";
}
