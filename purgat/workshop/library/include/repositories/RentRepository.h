//
// Created by student on 14.04.23.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H

#include "vector"

#include "typedefs.h"
#include "model/Rent.h"


class RentRepository {
private:
    std::vector<RentPtr> rentRepository;

public:
    RentRepository();

    virtual ~RentRepository();

    RentPtr get(unsigned int index) const;

    void add(RentPtr rent);

    void remove(RentPtr rent);

    std::string report();

    unsigned int size() const;

    std::vector<RentPtr> findBy(RentPredicate predicate) const;

    std::vector<RentPtr> findAll() const;
};


#endif //CARRENTAL_RENTREPOSITORY_H
