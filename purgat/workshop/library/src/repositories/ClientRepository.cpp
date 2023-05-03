//
// Created by student on 14.04.23.
//
#include "repositories/ClientRepository.h"

ClientPtr ClientRepository::findByPersonalId(const std::string &id) const {
    return findById<const std::string &>(id);
}