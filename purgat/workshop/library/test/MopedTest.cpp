//
// Created by student on 16.04.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Moped.h"

struct TestSuiteMopedFixture {
    const std::string plateNumber = "EL 0000";
    const unsigned int basePrice = 100;
    const unsigned int engineDisplacement1 = 1500;

    const unsigned int engineDisplacement2 = 2000;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMoped, TestSuiteMopedFixture)

    BOOST_AUTO_TEST_CASE(MopedConstructorTest){
        Moped moped(plateNumber, basePrice, engineDisplacement1);
        BOOST_TEST(moped.getEngineDisplacement() == engineDisplacement1);
    }

    BOOST_AUTO_TEST_CASE(MopedSetEngineDisplacementTest){
        Moped moped(plateNumber, basePrice, engineDisplacement1);
        moped.setEngineDisplacement(engineDisplacement2);
        BOOST_TEST(moped.getEngineDisplacement() == engineDisplacement2);
    }

    BOOST_AUTO_TEST_CASE(MopedGetActualRentalPriceTest){
        Moped moped(plateNumber, basePrice, engineDisplacement1);
        BOOST_TEST(moped.getActualRentalPrice() == moped.getBasePrice() * 1.25);
    }

BOOST_AUTO_TEST_SUITE_END()