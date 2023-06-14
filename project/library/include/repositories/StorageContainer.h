//
// Created by student on 12.06.23.
//

#ifndef HOTEL_STORAGECONTAINER_H
#define HOTEL_STORAGECONTAINER_H

#include "typedefs.h"

class StorageContainer {
private:
    ClientRepositoryPtr clientRepository;
    RentRepositoryPtr rentRepository;
    RoomRepositoryPtr roomRepository;

public:
    StorageContainer();

    virtual ~StorageContainer();

    ClientRepositoryPtr getClientRepository();

    const RentRepositoryPtr &getRentRepository() const;

    const RoomRepositoryPtr &getRoomRepository() const;
};



#endif //HOTEL_STORAGECONTAINER_H
