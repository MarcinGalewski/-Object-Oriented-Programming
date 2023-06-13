//
// Created by student on 13.06.23.
//

#ifndef HOTEL_APARTMENT_H
#define HOTEL_APARTMENT_H


#include "Room.h"

class Apartment : public Room{
private:
    int numberOfAmenities;
public:
    Apartment(const std::string &number, int price,int roomCapactiy, bool inArchived,  int numberOfAmenities);
    std::string getInfo() override;

    ~Apartment() override;
};


#endif //HOTEL_APARTMENT_H
