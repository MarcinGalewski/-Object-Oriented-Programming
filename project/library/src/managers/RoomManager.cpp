//
// Created by student on 14.06.23.
//
#include <iostream>
#include "managers/RoomManager.h"
#include "model/rooms/Room.h"
#include "exceptions/RoomException.h"
#include "model/rooms/SingleRoom.h"
#include "model/rooms/Apartment.h"

RoomManager::RoomManager() {
    this->roomRepository = std::make_shared<RoomRepository>();
}

RoomManager::~RoomManager() = default;

RoomPtr RoomManager::registerSingle(const std::string& number, int price, int roomCapacity) {
    RoomPtr check = roomRepository->findByRoomNumber(number);
    if(!check){
        try {
            check = std::make_shared<SingleRoom>(number, price, roomCapacity);
            roomRepository->add(check);
        }catch(RoomException &exception) {
            std::cout << std::endl << exception.what() << std::endl;
            return RoomPtr();
        }
        return check;
    } else
        return check;
}

RoomPtr RoomManager::registerDouble(const std::string& number, int price, int roomCapacity, BedType bedType) {
    RoomPtr check = roomRepository->findByRoomNumber(number);
    if(!check){
        try {
            check = std::make_shared<DoubleRoom>(number, price, roomCapacity, bedType);
            roomRepository->add(check);
        }catch(RoomException &exception) {
            std::cout << std::endl << exception.what() << std::endl;
            return RoomPtr();
        }
        return check;
    } else
        return check;
}
RoomPtr RoomManager::registerApartment(const std::string& number, int price, int roomCapacity, int numberOfAmenities) {
    RoomPtr check = roomRepository->findByRoomNumber(number);
    if(!check){
        try {
            check = std::make_shared<Apartment>(number, price, roomCapacity, numberOfAmenities);
            roomRepository->add(check);
        }catch(RoomException &exception) {
            std::cout << std::endl << exception.what() << std::endl;
            return RoomPtr();
        }
        return check;
    } else
        return check;
}

RoomPtr RoomManager::getRoom(const std::string& number) {
    return roomRepository->findByRoomNumber(number);
}

std::vector<RoomPtr> RoomManager::findRooms(RoomPredicate predicate) {
    return roomRepository->findBy(predicate);
}

std::string RoomManager::reportRooms() {
    return roomRepository->report();
}

void RoomManager::unregisterRoom(const RoomPtr& room) {
    RoomPtr repositoryRoom = getRoom(room->getNumber());
    if(repositoryRoom){
        repositoryRoom->setArchived(true);
    }
}