//
// Created by student on 13.06.23.
//

#ifndef HOTEL_ROOM_H
#define HOTEL_ROOM_H
#include "string"
#include "typedefs.h"

class Room {
private:
    std::string number;
    int roomCapacity;
    bool archived = false;
protected:
    int price;
public:
    Room(const std::string &number, int price,int roomCapacity);

    virtual std::string getInfo();
    virtual ~Room() = default;

    const std::string &getNumber() const;

    int getRoomCapacity() const;

    bool isArchived() const;

    int getPrice() const;

    const std::string &getId() const;

    void setNumber(const std::string &number);

    void setRoomCapacity(int roomCapacity);

    void setArchived(bool archived);

    void setPrice(int price);
};


#endif //HOTEL_ROOM_H
