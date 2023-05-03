//
// Created by student on 07.04.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "exceptions/VehicleException.h"

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
        BOOST_TEST(vehicle.isArchive() == false);
    }

    BOOST_AUTO_TEST_CASE(vehicleConstructorTest_Negative){
        BOOST_CHECK_THROW(Vehicle vehicle("", basePrice1), VehicleException);
        BOOST_CHECK_THROW(Vehicle vehicle(plateNumber1, 0), VehicleException);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetPlateNumberTest_Positive){
        Vehicle vehicle(plateNumber1, basePrice1);
        vehicle.setPlateNumber(plateNumber2);
        BOOST_TEST(vehicle.getPlateNumber() == plateNumber2);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetPlateNumberTest_Negative){
        Vehicle vehicle(plateNumber1, basePrice1);
        BOOST_CHECK_THROW(vehicle.setPlateNumber(""), VehicleException);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetBasePriceTest_Positive){
        Vehicle vehicle(plateNumber1, basePrice1);
        vehicle.setBasePrice(basePrice2);
        BOOST_TEST(vehicle.getBasePrice() == basePrice2);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetBasePriceTest_Negative){
        Vehicle vehicle(plateNumber1, basePrice1);
        BOOST_CHECK_THROW(vehicle.setBasePrice(0), VehicleException);
    }

    BOOST_AUTO_TEST_CASE(vehicleSetArchiveTest){
        Vehicle vehicle(plateNumber1, basePrice1);
        vehicle.setArchive(true);
        BOOST_TEST(vehicle.isArchive() == true);
    }

BOOST_AUTO_TEST_SUITE_END()