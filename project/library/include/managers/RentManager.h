//
// Created by student on 12.06.23.
//

#ifndef HOTEL_RENTMANAGER_H
#define HOTEL_RENTMANAGER_H

#include "typedefs.h"
#include "repositories/RentRepository.h"


class RentManager {
private:
    RentRepositoryPtr rentRepository;

    void changeClientType(const ClientPtr& client);

public:
    RentManager();

    virtual ~RentManager();

    std::vector<RentPtr> getAllClientRents(const ClientPtr& client);

    RentPtr rentRoom(const ClientPtr& client, const RoomPtr& room, unsigned int numberOfDays);

    RentPtr getRent(boost::uuids::uuid id);

    std::vector<RentPtr> findRents(RentPredicate predicate);

    std::string reportRents();

};


#endif //HOTEL_RENTMANAGER_H
