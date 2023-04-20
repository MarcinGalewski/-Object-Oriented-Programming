//
// Created by student on 16.04.23.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H

#include "model/MotorVehicle.h"

class Moped : public MotorVehicle{
public:
    Moped(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);

    ~Moped() override;

    double getActualRentalPrice() const override;

    std::string getVehicleInfo() const override;

};


#endif //CARRENTAL_MOPED_H
