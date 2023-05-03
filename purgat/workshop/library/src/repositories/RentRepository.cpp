//
// Created by student on 14.04.23.
//
#include "repositories/RentRepository.h"

RentPtr RentRepository::findByUUID(const boost::uuids::uuid &id) const {
    return findById<const boost::uuids::uuid &>(id);
}
