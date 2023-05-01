//
// Created by student on 27.04.23.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H

#include "typedefs.h"
#include "repositories/ClientRepository.h"

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;

public:
    ClientManager();

    virtual ~ClientManager();

    ClientPtr getClient(std::string id);

    ClientPtr registerClient(const std::string &firstName, const std::string &lastName,
                             const std::string &personalId, AddressPtr address,
                             ClientTypePtr clientType);

    void unregisterClient(ClientPtr client);

    std::vector<ClientPtr> findClients(ClientPredicate predicate);
};


#endif //CARRENTAL_CLIENTMANAGER_H
