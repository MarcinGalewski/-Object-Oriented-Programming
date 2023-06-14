//
// Created by student on 12.06.23.
//

#ifndef HOTEL_CLIENTMANAGER_H
#define HOTEL_CLIENTMANAGER_H

#include "string"

#include "typedefs.h"
#include "repositories/ClientRepository.h"

class ClientManager {
private:
    ClientRepositoryPtr clientRepository;

public:
    ClientManager();

    virtual ~ClientManager();

    ClientPtr getClient(const std::string& id);

    ClientPtr registerClient(const std::string &firstName, const std::string &lastName,
                             const std::string &personalId, const AddressPtr& address,
                             const ClientTypePtr& clientType);

    void unregisterClient(const ClientPtr& client);

    std::vector<ClientPtr> findClients(const ClientPredicate& predicate);

    std::string reportClients();
};


#endif //HOTEL_CLIENTMANAGER_H
