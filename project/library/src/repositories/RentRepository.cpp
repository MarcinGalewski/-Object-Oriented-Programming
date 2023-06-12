//
// Created by student on 12.06.23.
//

#include "repositories/RentRepository.h"

RentPtr RentRepository::findByUUID(const boost::uuids::uuid &id) const {
    return findById<const boost::uuids::uuid &>(id);
}
