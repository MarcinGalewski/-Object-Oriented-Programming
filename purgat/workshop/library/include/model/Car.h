//
// Created by student on 16.04.23.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H

#include "model/MotorVehicle.h"

enum SegmentType{
    A = 10,
    B = 11,
    C = 12,
    D = 13,
    E = 15
};

class Car : public MotorVehicle {
private:
    SegmentType segment;
public:
    Car(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment);

    ~Car() override;

    SegmentType getSegment() const;

    void setSegment(SegmentType segment);

    double getActualRentalPrice() const override;

    std::string getVehicleInfo() const override;
};


#endif //CARRENTAL_CAR_H
