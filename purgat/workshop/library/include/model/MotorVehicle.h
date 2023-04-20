//
// Created by student on 16.04.23.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include "model/Vehicle.h"

class MotorVehicle : public Vehicle{
private:
    unsigned int engineDisplacement;

public:
    MotorVehicle(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement);

    ~MotorVehicle() override;

    unsigned int getEngineDisplacement() const;

    void setEngineDisplacement(unsigned int engineDisplacement);

    virtual double getActualRentalPrice() const;

    std::string getVehicleInfo() const override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
