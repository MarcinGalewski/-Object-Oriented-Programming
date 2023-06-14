//
// Created by student on 14.06.23.
//

#ifndef HOTEL_ROOMMANAGER_H
#define HOTEL_ROOMMANAGER_H

#include "typedefs.h"
#include "repositories/RoomRepository.h"
#include "model/rooms/DoubleRoom.h"

class RoomManager {
private:
    RoomRepositoryPtr roomRepository;
public:
    RoomManager();

    virtual ~RoomManager();

    RoomPtr getRoom(const std::string& name);
    RoomPtr registerSingle(const std::string& number, int price, int roomCapacity);
    RoomPtr registerDouble(const std::string& number, int price, int roomCapacity, BedType bedType);
    RoomPtr registerApartment(const std::string& number, int price, int roomCapacity, int numberOfAmenities);
    void unregisterRoom(const RoomPtr& room);
    std::vector<RoomPtr> findRooms(RoomPredicate predicate);
    std::string reportRooms();
};


#endif //HOTEL_ROOMMANAGER_H
