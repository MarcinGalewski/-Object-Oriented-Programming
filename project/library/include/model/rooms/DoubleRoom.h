//
// Created by student on 13.06.23.
//

#ifndef HOTEL_DOUBLEROOM_H
#define HOTEL_DOUBLEROOM_H
#include "Room.h"

enum BedType{
    QueenSize=0,
    KingSize=1
};

class DoubleRoom : public Room{
private:
    BedType bedType;
public:
    DoubleRoom(const std::string &number, int price,int roomCapacity, BedType bedType);


    std::string getInfo() override;
    ~DoubleRoom() override;
};


#endif //HOTEL_DOUBLEROOM_H
