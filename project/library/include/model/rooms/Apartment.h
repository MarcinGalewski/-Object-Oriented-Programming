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
    Apartment(const std::string &number, int price,int roomCapacity, int numberOfAmenities);
    std::string getInfo() override;

    int getNumberOfAmenities() const;

    void setNumberOfAmenities(int numberOfAmenities);

    ~Apartment() override;

    int getActualPrice() override;
};


#endif //HOTEL_APARTMENT_H
