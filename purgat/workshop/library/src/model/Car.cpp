//
// Created by student on 16.04.23.
//

#include "model/Car.h"

Car::Car(const std::string &plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment) {}

Car::~Car() {

}

SegmentType Car::getSegment() const {
    return segment;
}

void Car::setSegment(SegmentType segment) {
    Car::segment = segment;
}

double Car::getActualRentalPrice() const {
    return MotorVehicle::getActualRentalPrice() * (segment / 10);
}

std::string Car::getVehicleInfo() const {
    return "Car: " + MotorVehicle::getVehicleInfo() + ", segment: " + std::to_string(segment);
}
