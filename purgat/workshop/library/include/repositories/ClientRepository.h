//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include "typedefs.h"
#include "model/Client.h"
#include "Repository.h"

class ClientRepository : public Repository<Client>{
public:
    ClientPtr findByPersonalId(const std::string &id) const;
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
