//
// Created by student on 13.06.23.
//

#ifndef HOTEL_SINGLEROOM_H
#define HOTEL_SINGLEROOM_H


#include "Room.h"

class SingleRoom : public Room{
public:
    std::string getInfo() override;
    SingleRoom(const std::string &number, int price, int roomCapacity);
};


#endif //HOTEL_SINGLEROOM_H
