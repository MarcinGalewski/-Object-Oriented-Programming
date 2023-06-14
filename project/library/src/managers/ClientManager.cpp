//
// Created by student on 12.06.23.
//

#include <iostream>
#include "managers/ClientManager.h"
#include "exceptions/ClientException.h"

ClientManager::ClientManager() {
    this->clientRepository = std::make_shared<ClientRepository>();
}

ClientManager::~ClientManager() = default;

ClientPtr ClientManager::getClient(const std::string& id) {
    return clientRepository->findByPersonalId(id);
}

ClientPtr ClientManager::registerClient(const std::string &firstName, const std::string &lastName,
                                        const std::string &personalId, const AddressPtr& address, const ClientTypePtr& clientType) {
    ClientPtr check = clientRepository->findByPersonalId(personalId);
    if(!check){
        try {
            check = std::make_shared<Client>(firstName, lastName, personalId, address, clientType);
            clientRepository->add(check);
        }catch(ClientException &exception) {
            std::cout << std::endl << exception.what() << std::endl;
            return ClientPtr();
        }
        return check;
    } else
        return check;
}

void ClientManager::unregisterClient(const ClientPtr& client) {
    ClientPtr repositoryClient = getClient(client->getPersonalId());
    if(repositoryClient){
        repositoryClient->setArchived(true);
    }
}

std::vector<ClientPtr> ClientManager::findClients(const ClientPredicate& predicate) {
    return clientRepository->findBy([predicate](const ClientPtr& client){
        return predicate(client) && !client->isArchived();
    });
}

std::string ClientManager::reportClients() {
    return clientRepository->report();
}
