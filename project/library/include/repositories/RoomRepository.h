//
// Created by student on 14.06.23.
//

#ifndef HOTEL_ROOMREPOSITORY_H
#define HOTEL_ROOMREPOSITORY_H

#include "typedefs.h"
#include "model/rooms/Room.h"
#include "Repository.h"

class RoomRepository :public Repository<Room>{
public:
    RoomPtr findByRoomNumber(const std::string &number) const;
};


#endif //HOTEL_ROOMREPOSITORY_H