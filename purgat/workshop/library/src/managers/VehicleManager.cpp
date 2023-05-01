//
// Created by student on 29.04.23.
//

#include "managers/VehicleManager.h"
#include "model/Bicycle.h"
#include "model/Moped.h"

VehicleManager::VehicleManager() {
    this->vehicleRepository = std::make_shared<VehicleRepository>();
}

VehicleManager::~VehicleManager() {}

VehiclePtr VehicleManager::getVehicle(std::string plateNumber) {
    return vehicleRepository->findByPlateNumber(plateNumber);
}

VehiclePtr VehicleManager::registerBicycle(const std::string &plateNumber, unsigned int basePrice) {
    VehiclePtr check = getVehicle(plateNumber);
    if(!check){
        VehiclePtr vehicle = std::make_shared<Bicycle>(plateNumber, basePrice);
        vehicleRepository->add(vehicle);
        return vehicle;
    }else
        return check;
}

VehiclePtr VehicleManager::registerMoped(const std::string &plateNumber,
                                         unsigned int basePrice, unsigned int engineDisplacement) {
    VehiclePtr check = getVehicle(plateNumber);
    if(!check){
        VehiclePtr vehicle = std::make_shared<Moped>(plateNumber, basePrice, engineDisplacement);
        vehicleRepository->add(vehicle);
        return vehicle;
    } else
        return check;
}

VehiclePtr VehicleManager::registerCar(const std::string &plateNumber,
                                       unsigned int basePrice, unsigned int engineDisplacement,
                                       SegmentType segment) {
    VehiclePtr check = getVehicle(plateNumber);
    if(!check){
        VehiclePtr vehicle = std::make_shared<Car>(plateNumber, basePrice, engineDisplacement, segment);
        vehicleRepository->add(vehicle);
        return vehicle;
    } else
        return check;
}

void VehicleManager::unregisterVehicle(VehiclePtr vehicle) {
    VehiclePtr repositoryVehicle = getVehicle(vehicle->getPlateNumber());
    if(repositoryVehicle){
        repositoryVehicle->setArchive(true);
    }
}

std::vector<VehiclePtr> VehicleManager::findVehicles(VehiclePredicate predicate) {
    return vehicleRepository->findBy([predicate](VehiclePtr vehicle){return predicate(vehicle) && !vehicle->isArchive();});
}
