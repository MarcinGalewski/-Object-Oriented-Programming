//
// Created by student on 12.06.23.
//

#ifndef HOTEL_STORAGECONTAINER_H
#define HOTEL_STORAGECONTAINER_H

#include "typedefs.h"
#include "repositories/ClientRepository.h"

class StorageContainer {
private:
    ClientRepositoryPtr clientRepository;

public:
    StorageContainer();

    virtual ~StorageContainer();

    ClientRepositoryPtr getClientRepository();
};



#endif //HOTEL_STORAGECONTAINER_H
