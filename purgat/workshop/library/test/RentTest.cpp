//
// Created by student on 11.04.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Bronze.h"

namespace gr = boost::gregorian;

struct TestSuiteRentFixture {
    const unsigned int testRentId = 1;
    pt::ptime testTime1 = pt::ptime(gr::date(2023, 1, 1), pt::hours(12) + pt::minutes(30));
    pt::ptime testTime2 = pt::ptime(gr::date(2023, 1, 1), pt::hours(12) + pt::minutes(31));// 1 minute
    pt::ptime testTime3 = pt::ptime(gr::date(2023, 1, 2), pt::hours(12) + pt::minutes(30));// 24 hours
    pt::ptime testTime4 = pt::ptime(gr::date(2023, 1, 2), pt::hours(12) + pt::minutes(31));// 24 hours 1 minute


    AddressPtr testAddress;
    ClientPtr testClient;
    ClientTypePtr testClientType;
    VehiclePtr testVehicle;

    TestSuiteRentFixture() {
        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClientType = std::make_shared<Bronze>();
        testClient = std::make_shared<Client>("Leon", "Zakrzewski", "010101", testAddress, testClientType);
        testVehicle = std::make_shared<Vehicle>("EL 0000", 100);
    }

    ~TestSuiteRentFixture() {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)
    BOOST_AUTO_TEST_CASE(rentConstructorTest_ProvidedBeginTime) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        BOOST_TEST(rent.getId() == testRentId);
        BOOST_TEST(rent.getClient() == testClient);
        BOOST_TEST(rent.getVehicle() == testVehicle);
        BOOST_TEST(rent.getBeginTime() == testTime1);
    }

    BOOST_AUTO_TEST_CASE(rentConstructorTest_DefaultBeginTime) {
        Rent rent(testRentId, testClient, testVehicle, pt::not_a_date_time);
        pt::ptime now = pt::second_clock::local_time();

        BOOST_TEST(rent.getId() == testRentId);
        BOOST_TEST(rent.getClient() == testClient);
        BOOST_TEST(rent.getVehicle() == testVehicle);
        BOOST_TEST(rent.getBeginTime() == now);
    }

//    BOOST_AUTO_TEST_CASE(rentSetRentedTest_Positive) {
//        Rent rent(testRentId, testClient, testVehicle, testTime1);
//        BOOST_TEST(testVehicle->isRented() == true);
//    }
//
//    BOOST_AUTO_TEST_CASE(rentEndRentTest_ReturnVehicle) {
//        Rent rent(testRentId, testClient, testVehicle, testTime1);
//        rent.endRent(testTime3);
//        BOOST_TEST(testVehicle->isRented() == false);
//    }

//    BOOST_AUTO_TEST_CASE(rentEndRentTest_DeleteRentFromCurrentRents) {
//        Rent rent(testRentId, testClient, testVehicle, testTime1);
//        BOOST_TEST(testClient->getCurrentRents().size() == 1);
//
//        rent.endRent(testTime3);
//        BOOST_TEST(testClient->getCurrentRents().size() == 0);
//    }

    BOOST_AUTO_TEST_CASE(rentEndRentTest_ProvidedEndTime) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime2);
        BOOST_TEST(rent.getEndTime() == testTime2);
    }

    BOOST_AUTO_TEST_CASE(rentEndRentTest_EndRentTwice) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime3);

        pt::ptime now = pt::second_clock::local_time();
        rent.endRent(now);

        BOOST_TEST(rent.getEndTime() == testTime3);
    }

    BOOST_AUTO_TEST_CASE(rentEndRentTest_EndTimeNotADate) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(pt::not_a_date_time);
        pt::ptime now = pt::second_clock::local_time();
        BOOST_TEST(rent.getEndTime() == now);
    }

    BOOST_AUTO_TEST_CASE(rentEndRentTest_EndTimeBeforeBeginTime) {
        Rent rent(testRentId, testClient, testVehicle, testTime3);
        rent.endRent(testTime1);
        BOOST_TEST(rent.getEndTime() == testTime3);
    }

    BOOST_AUTO_TEST_CASE(rentGetRentDaysTest_WholeDay) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime3);
        BOOST_TEST(rent.getRentDays() == 2);
    }

    BOOST_AUTO_TEST_CASE(rentGetRentDaysTest_LessThanDay) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime2);
        BOOST_TEST(rent.getRentDays() == 1);
    }

    BOOST_AUTO_TEST_CASE(rentGetRentDaysTest_MoreThanDay) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime4);
        BOOST_TEST(rent.getRentDays() == 2);
    }

    BOOST_AUTO_TEST_CASE(rentGetRentCostTest_ZeroDays) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime1);
        BOOST_TEST(rent.getRentCost() == 0);
    }

    BOOST_AUTO_TEST_CASE(rentGetRentCostTest_MoreThanDay) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime3);
        BOOST_TEST(rent.getRentCost() == (testVehicle->getBasePrice() * 2) - 3);
    }

    BOOST_AUTO_TEST_CASE(rentGetRentCostTest_ChangeRentCostAfterEndRent) {
        Rent rent(testRentId, testClient, testVehicle, testTime1);
        rent.endRent(testTime3);
        double firstCost = rent.getRentCost();
        testVehicle->setBasePrice(200);
        BOOST_TEST(rent.getRentCost() == firstCost);
    }


BOOST_AUTO_TEST_SUITE_END()