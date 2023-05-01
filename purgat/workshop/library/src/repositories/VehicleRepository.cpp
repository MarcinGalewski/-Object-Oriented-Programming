//
// Created by student on 14.04.23.
//
#include "algorithm"

#include "repositories/VehicleRepository.h"

VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {}

VehiclePtr VehicleRepository::get(unsigned int index) const {
    if(index >= size())
        return nullptr;
    else
        return vehicleRepository[index];
}

void VehicleRepository::add(VehiclePtr vehicle) {
    if(vehicle)
        vehicleRepository.push_back(vehicle);

}

void VehicleRepository::remove(VehiclePtr vehicle) {
    if(vehicle)
        vehicleRepository.erase(
                std::remove(vehicleRepository.begin(), vehicleRepository.end(), vehicle)
                , vehicleRepository.end());
}

std::string VehicleRepository::report() {
    std::string report;
    for(int i = 0; i < size() ; i++){
        report += std::to_string(i + 1) + ". " + vehicleRepository[i]->getVehicleInfo() + "\n";
    }
    return report;
}

unsigned int VehicleRepository::size() const {
    return vehicleRepository.size();
}

std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const {
    std::vector<VehiclePtr> found;
    for(unsigned int i = 0; i < size(); i++){
        VehiclePtr vehicle = get(i);
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

std::vector<VehiclePtr> VehicleRepository::findAll() const {
    return findBy([](VehiclePtr vehicle){return true;});
}

VehiclePtr VehicleRepository::findByPlateNumber(std::string plateNumber) const {
    std::vector<VehiclePtr> foundVehicles = findBy([&plateNumber](VehiclePtr vehicle){return vehicle->getPlateNumber() == plateNumber;});
    if(!foundVehicles.empty())
        return foundVehicles[0];
    else
        return nullptr;
}
