//
// Created by student on 14.04.23.
//

#include "repositories/RentRepository.h"

RentRepository::RentRepository() {}

RentRepository::~RentRepository() {}

RentPtr RentRepository::get(unsigned int index) const {
    if(index >= size())
        return nullptr;
    else
        return rentRepository[index];
}

void RentRepository::add(RentPtr rent) {
    if(rent)
        rentRepository.push_back(rent);
}

void RentRepository::remove(RentPtr rent) {
    if(rent)
        rentRepository.erase(
                std::remove(rentRepository.begin(), rentRepository.end(), rent)
                , rentRepository.end());
}

std::string RentRepository::report() {
    std::string report;
    for(int i = 0; i < size(); i++){
        report += std::to_string(i + 1) + ". " + rentRepository[i]->getRentInfo() + "\n";
    }
    return report;
}

unsigned int RentRepository::size() const {
    return rentRepository.size();
}

std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const {
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < size(); i++) {
        RentPtr rent = get(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

std::vector<RentPtr> RentRepository::findAll() const {
    return findBy([](RentPtr rent){return true;});
}
