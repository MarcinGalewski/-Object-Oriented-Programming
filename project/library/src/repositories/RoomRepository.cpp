//
// Created by student on 14.06.23.
//

#include "repositories/RoomRepository.h"

RoomPtr RoomRepository::findByRoomNumber(const std::string &number) const {
    return findById<const std::string &>(number);
}
