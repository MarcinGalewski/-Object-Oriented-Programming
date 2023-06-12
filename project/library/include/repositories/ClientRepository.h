//
// Created by student on 12.06.23.
//

#ifndef HOTEL_CLIENTREPOSITORY_H
#define HOTEL_CLIENTREPOSITORY_H

#include "typedefs.h"
#include "model/Client.h"
#include "Repository.h"

class ClientRepository : public Repository<Client>{
public:
    ClientPtr findByPersonalId(const std::string &id) const;
};


#endif //HOTEL_CLIENTREPOSITORY_H
