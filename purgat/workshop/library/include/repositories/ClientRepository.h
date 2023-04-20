//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include "vector"

#include "typedefs.h"
#include "model/Client.h"

class ClientRepository {
private:
    std::vector<ClientPtr> clientRepository;

public:
    ClientRepository();

    virtual ~ClientRepository();

    unsigned int size() const;

    ClientPtr get(unsigned int index) const;

    void add(ClientPtr client);

    void remove(ClientPtr client);

    std::string report();

    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;

    std::vector<ClientPtr> findAll() const;
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
