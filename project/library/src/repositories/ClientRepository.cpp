//
// Created by student on 12.06.23.
//

#include "repositories/ClientRepository.h"

ClientPtr ClientRepository::findByPersonalId(const std::string &id) const {
    return findById<const std::string &>(id);
}
