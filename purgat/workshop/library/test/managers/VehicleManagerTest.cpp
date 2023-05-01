//
// Created by student on 30.04.23.
//
#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"


struct TestSuiteVehicleManagerFixture {
    LogicContainerPtr logicContainer;
    VehicleManagerPtr vehicleManager;

    std::string testPlateNumber = "EL 1001";
    unsigned int testBasePrice = 30;

    TestSuiteVehicleManagerFixture(){
        logicContainer = std::make_shared<LogicContainer>();
        vehicleManager = logicContainer->getVehicleManager();

    }

    ~TestSuiteVehicleManagerFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleManager, TestSuiteVehicleManagerFixture)

    BOOST_AUTO_TEST_CASE(VehicleManagerGetVehicleTest_Positive) {
        BOOST_TEST(vehicleManager->getVehicle("EL 0101")->getBasePrice() == 20);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerGetVehicleTest_Negative) {
        BOOST_TEST(vehicleManager->getVehicle("EL 0000") == nullptr);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRegisterVehicleTest) {
        vehicleManager->registerBicycle(testPlateNumber, testBasePrice);
        BOOST_TEST(vehicleManager->getVehicle(testPlateNumber)->getBasePrice() == testBasePrice);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerUnregisterVehicleTest) {
        VehiclePtr newVehicle = vehicleManager->registerBicycle(testPlateNumber, testBasePrice);
        vehicleManager->unregisterVehicle(newVehicle);
        BOOST_TEST(newVehicle->isArchive() == true);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerFindVehiclesTest) {
        BOOST_TEST(vehicleManager->findVehicles([](VehiclePtr v){return v->getBasePrice() == 100;}).size() == 1);
    }

BOOST_AUTO_TEST_SUITE_END()