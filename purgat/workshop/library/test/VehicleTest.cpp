//
// Created by student on 07.04.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"

struct TestSuiteVehicleFixture {
    const std::string plateNumber1 = "EL 0000";
    const unsigned int basePrice1 = 100;

    const std::string plateNumber2 = "EL 1111";
    const unsigned int basePrice2 = 200;



};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle, TestSuiteVehicleFixture)

    BOOST_AUTO_TEST_CASE(vehicleConstructorTest_Positive){
        Vehicle vehicle(plateNumber1, basePrice1);
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber1);
        BOOST_TEST(vehicle.getBasePrice() == basePrice1);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetPlateNumberTest_Positive){
        Vehicle vehicle(plateNumber1, basePrice1);
        vehicle.setPlateNumber(plateNumber2);
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber2);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetPlateNumberTest_Negative){
        Vehicle vehicle(plateNumber1, basePrice1);
        vehicle.setPlateNumber("");
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber1);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetBasePriceTest_Positive){
        Vehicle vehicle(plateNumber1, basePrice1);
        vehicle.setBasePrice(basePrice2);
        BOOST_TEST(vehicle.getBasePrice() == basePrice2);
    }

BOOST_AUTO_TEST_SUITE_END()