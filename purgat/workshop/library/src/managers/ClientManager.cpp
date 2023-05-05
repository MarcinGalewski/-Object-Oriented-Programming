//
// Created by student on 27.04.23.
//

#include "managers/ClientManager.h"
#include "exceptions/ClientException.h"

ClientManager::ClientManager() {
    this->clientRepository = std::make_shared<ClientRepository>();
}

ClientManager::~ClientManager() {}

ClientPtr ClientManager::getClient(std::string id) {
    return clientRepository->findByPersonalId(id);
}

ClientPtr ClientManager::registerClient(const std::string &firstName, const std::string &lastName,
                                        const std::string &personalId, AddressPtr address, ClientTypePtr clientType) {
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

void ClientManager::unregisterClient(ClientPtr client) {
    ClientPtr repositoryClient = getClient(client->getPersonalId());
    if(repositoryClient){
        repositoryClient->setArchive(true);
    }
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate) {
    return clientRepository->findBy([predicate](ClientPtr client){
        return predicate(client) && !client->isArchive();
    });
}






