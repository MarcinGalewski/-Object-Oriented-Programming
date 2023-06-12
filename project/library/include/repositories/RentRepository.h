//
// Created by student on 12.06.23.
//

#ifndef HOTEL_RENTREPOSITORY_H
#define HOTEL_RENTREPOSITORY_H

#include "typedefs.h"
#include "model/Rent.h"
#include "Repository.h"

class RentRepository : public Repository<Rent>{
public:
    RentPtr findByUUID(const boost::uuids::uuid &id) const;
};



#endif //HOTEL_RENTREPOSITORY_H
