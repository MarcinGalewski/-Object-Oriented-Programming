//
// Created by student on 14.06.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/clientTypes/RegularClient.h"
#include "model/rooms/DoubleRoom.h"
#include "exceptions/RentException.h"
struct TestSuiteRentFixture {
    boost::uuids::uuid testRentId = boost::uuids::random_generator()();
    int testNumberOfDays = 3;

    AddressPtr testAddress;
    ClientPtr testClient;
    ClientTypePtr testClientType;
    RoomPtr testRoom;

    TestSuiteRentFixture() {
        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClientType = std::make_shared<RegularClient>();
        testClient = std::make_shared<Client>("John", "Doe", "010101", testAddress, testClientType);
        testRoom = std::make_shared<DoubleRoom>("12", 200, 3, QueenSize);
    }

    ~TestSuiteRentFixture() {
    }

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(rentConstructorTest_Positive) {
        Rent rent(testRentId, testClient, testRoom, testNumberOfDays);
        BOOST_TEST(rent.getId() == testRentId);
        BOOST_TEST(rent.getClient() == testClient);
        BOOST_TEST(rent.getRoom() == testRoom);
        BOOST_TEST(rent.getNumberOfDays() == testNumberOfDays);
    }

    BOOST_AUTO_TEST_CASE(rentConstructorTest_Negative) {
        BOOST_CHECK_THROW( Rent rent(testRentId, testClient, nullptr, testNumberOfDays), RentException);
        BOOST_CHECK_THROW( Rent rent(testRentId, testClient, testRoom, 0), RentException);
    }

    BOOST_AUTO_TEST_CASE(rentCalculateCostTest) {
        Rent rent(testRentId, testClient, testRoom, testNumberOfDays);
        BOOST_TEST(rent.getRentCost() == 528);
    }

BOOST_AUTO_TEST_SUITE_END()