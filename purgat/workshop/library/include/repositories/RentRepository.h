//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H

#include "typedefs.h"
#include "model/Rent.h"
#include "Repository.h"

class RentRepository : public Repository<Rent>{
public:
    RentPtr findByUUID(const boost::uuids::uuid &id) const;
};


#endif //CARRENTAL_RENTREPOSITORY_H
