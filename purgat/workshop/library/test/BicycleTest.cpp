//
// Created by student on 16.04.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Bicycle.h"

struct TestSuiteBicycleFixture {
    const std::string plateNumber = "EL 0000";
    const unsigned int basePrice = 100;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBicycle, TestSuiteBicycleFixture)

    BOOST_AUTO_TEST_CASE(BicycleGetActualRentalPriceTest){
        Bicycle bicycle(plateNumber, basePrice);
        BOOST_TEST(bicycle.getActualRentalPrice() == basePrice);
    }


BOOST_AUTO_TEST_SUITE_END()