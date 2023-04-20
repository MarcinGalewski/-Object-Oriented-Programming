//
// Created by student on 16.04.23.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "model/Vehicle.h"

class Bicycle : public Vehicle{
public:
    Bicycle(const std::string &plateNumber, unsigned int basePrice);

    ~Bicycle() override;

    double getActualRentalPrice() const;

    std::string getVehicleInfo() const override;
};


#endif //CARRENTAL_BICYCLE_H
