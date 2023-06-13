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
    int roomCapactiy;
    bool inArchived;
protected:
    int price;
public:
    Room(const std::string &number, int price,int roomCapactiy, bool inArchived);

    virtual std::string getInfo();
    virtual ~Room() = default;

    const std::string &getNumber() const;

    int getRoomCapactiy() const;

    bool isInArchived() const;

    int getPrice() const;
};


#endif //HOTEL_ROOM_H
