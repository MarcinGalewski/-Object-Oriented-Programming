//
// Created by student on 07.04.23.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H

#include "string"

class Vehicle {
protected:
    unsigned int basePrice;

private:
    std::string plateNumber;

public:
    Vehicle(const std::string &plateNumber, unsigned int basePrice);

    virtual ~Vehicle();

    virtual std::string getVehicleInfo() const;

    const std::string &getPlateNumber() const;

    unsigned int getBasePrice() const;

    void setPlateNumber(const std::string &plateNumber);

    void setBasePrice(unsigned int basePrice);
};


#endif //CARRENTAL_VEHICLE_H
