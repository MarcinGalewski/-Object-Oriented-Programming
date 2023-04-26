//
// Created by student on 14.04.23.
//
#include "algorithm"

#include "repositories/ClientRepository.h"

ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {}

unsigned int ClientRepository::size() const {
    return clientRepository.size();
}

ClientPtr ClientRepository::get(unsigned int index) const {
    if(index >= size())
        return nullptr;
    else
        return clientRepository[index];
}

void ClientRepository::add(ClientPtr client) {
    if(client)
        clientRepository.push_back(client);
}

void ClientRepository::remove(ClientPtr client) {
    if(client)
        clientRepository.erase(
                std::remove(clientRepository.begin(), clientRepository.end(), client)
                , clientRepository.end());
}

std::string ClientRepository::report() {
    std::string report;
    for(int i = 0; i < size(); i++){
        report += std::to_string(i + 1) + ". " + clientRepository[i]->getClientInfo() + "\n";
    }
    return report;
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < size(); i++) {
        ClientPtr client = get(i);
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

std::vector<ClientPtr> ClientRepository::findAll() const {
    return findBy([](ClientPtr client){return true;});
}


