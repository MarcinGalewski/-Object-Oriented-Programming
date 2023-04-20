//
// Created by student on 16.04.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Car.h"

struct TestSuiteCarFixture {
    const std::string plateNumber = "EL 0000";
    const unsigned int basePrice = 100;
    const unsigned int engineDisplacement1 = 1500;
    const SegmentType segment1 = A;

    const unsigned int engineDisplacement2 = 2000;
    const SegmentType segment2 = B;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteCar, TestSuiteCarFixture)

    BOOST_AUTO_TEST_CASE(CarConstructorTest_Positive){
            Car car(plateNumber, basePrice, engineDisplacement1, segment1);
            BOOST_TEST(car.getEngineDisplacement() == engineDisplacement1);
    }

    BOOST_AUTO_TEST_CASE(CarSetEngineDisplacementTest_Positive){
            Car car(plateNumber, basePrice, engineDisplacement1, segment1);
            car.setEngineDisplacement(engineDisplacement2);
            BOOST_TEST(car.getEngineDisplacement() == engineDisplacement2);
    }

    BOOST_AUTO_TEST_CASE(CarSetSegmentTest_Positive){
        Car car(plateNumber, basePrice, engineDisplacement1, segment1);
        car.setSegment(segment2);
        BOOST_TEST(car.getSegment() == segment2);
    }

    BOOST_AUTO_TEST_CASE(CarGetActualRentalPriceTest_Positive){
            Car car(plateNumber, basePrice, engineDisplacement1, segment1);
            BOOST_TEST(car.getActualRentalPrice() == car.getBasePrice() * 1.25 * (segment1 / 10));
    }

BOOST_AUTO_TEST_SUITE_END()