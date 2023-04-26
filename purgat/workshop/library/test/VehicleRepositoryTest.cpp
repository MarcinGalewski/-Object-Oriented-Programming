//
// Created by student on 16.04.23.
//
#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"

struct TestSuiteVehicleRepositoryFixture {
    StorageContainerPtr storageContainer;
    VehicleRepositoryPtr vehicleRepository;
    VehiclePtr testVehicle;

    TestSuiteVehicleRepositoryFixture(){
        storageContainer = std::make_shared<StorageContainer>();
        vehicleRepository = storageContainer->getVehicleRepository();
        testVehicle = std::make_shared<Vehicle>("EL 0000", 100);
    }

    ~TestSuiteVehicleRepositoryFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleRepository, TestSuiteVehicleRepositoryFixture)

    BOOST_AUTO_TEST_CASE(VehicleRepositorySizeTest) {
        BOOST_TEST(vehicleRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetTest_Positive) {
        BOOST_TEST(vehicleRepository->get(0) != nullptr);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryGetTest_Negative) {
        BOOST_TEST(vehicleRepository->get(vehicleRepository->size()) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddTest_Positive) {
        unsigned int startingSize = vehicleRepository->size();
        vehicleRepository->add(testVehicle);
        BOOST_TEST(vehicleRepository->size() == startingSize + 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddTest_Negative) {
        unsigned int startingSize = vehicleRepository->size();
        vehicleRepository->add(nullptr);
        BOOST_TEST(vehicleRepository->size() == startingSize);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveTest_Positive) {
        vehicleRepository->add(testVehicle);
        unsigned int startingSize = vehicleRepository->size();
        vehicleRepository->remove(testVehicle);
        BOOST_TEST(vehicleRepository->size() == startingSize - 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryRemoveTest_Negative) {
        unsigned int startingSize = vehicleRepository->size();
        vehicleRepository->remove(nullptr);
        BOOST_TEST(vehicleRepository->size() == startingSize);
    }


    BOOST_AUTO_TEST_CASE(VehicleRepositoryFindByTest_OneItem) {
        BOOST_TEST(vehicleRepository->findBy([](VehiclePtr vehicle){
            return vehicle->getBasePrice() == 200;
        }).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryFindByTest_ZeroItems) {
        BOOST_TEST(vehicleRepository->findBy([](VehiclePtr vehicle){
            return vehicle->getBasePrice() == 300;
        }).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryFindAllTest) {
        BOOST_TEST(vehicleRepository->findAll().size() == 2);
    }


BOOST_AUTO_TEST_SUITE_END()
