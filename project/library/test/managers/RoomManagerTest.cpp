//
// Created by student on 14.06.23.
//
#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/rooms/SingleRoom.h"
#include "managers/RoomManager.h"

struct TestSuiteRoomManagerFixture {
    RoomManagerPtr roomManager;
    const std::string testNumber1 = "320A";
    const int testPrice1 = 150;
    const int testRoomCapacity1=1;
    const std::string testNumber2 = "220B";
    const int testPrice2 = 100;
    const int testRoomCapacity2 = 1;
    const std::string testNumber3 = "110D";
    const int testPrice3 = 220;
    const int testRoomCapacity3 = 2;
    const BedType testBedType = QueenSize;
    const std::string testNumber4 = "A4";
    const int testPrice4 = 800;
    const int testRoomCapacity4 = 4;
    const int testNumberOfAmenities = 4;

    TestSuiteRoomManagerFixture(){
        roomManager = std::make_shared<RoomManager>();
        roomManager->registerSingle(testNumber1,testPrice1,testRoomCapacity1);
    }

    ~TestSuiteRoomManagerFixture()= default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoomManager, TestSuiteRoomManagerFixture)

    BOOST_AUTO_TEST_CASE(RoomManagerGetRoomTest_Positive) {
        BOOST_TEST(roomManager->getRoom("320A") != nullptr);
    }

    BOOST_AUTO_TEST_CASE(RoomManagerGetRoomTest_Negative) {
        BOOST_TEST(roomManager->getRoom("000000") == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RoomManagerRegisterSingleRoomTest) {
        roomManager->registerSingle(testNumber2,testPrice2,testRoomCapacity2);
        BOOST_TEST(roomManager->getRoom(testNumber2)->getPrice() == testPrice2);
    }
    BOOST_AUTO_TEST_CASE(RoomManagerRegisterDoubleRoomTest) {
        roomManager->registerDouble(testNumber3,testPrice3,testRoomCapacity3,testBedType);
        BOOST_TEST(roomManager->getRoom(testNumber3)->getPrice() == testPrice3);
    }
    BOOST_AUTO_TEST_CASE(RoomManagerRegisterApartmentTest) {
        roomManager->registerApartment(testNumber4,testPrice4,testRoomCapacity4,testNumberOfAmenities);
        BOOST_TEST(roomManager->getRoom(testNumber4)->getPrice() == testPrice4);
    }

    BOOST_AUTO_TEST_CASE(RoomManagerUnregisterRoomTest) {
        RoomPtr newRoom = roomManager->registerDouble(testNumber3,testPrice3,testRoomCapacity3,testBedType);
        roomManager->unregisterRoom(newRoom);
        BOOST_TEST(newRoom->isArchived() == true);
    }

    BOOST_AUTO_TEST_CASE(RoomManagerFindRoomsTest) {
        BOOST_TEST(roomManager->findRooms([](const RoomPtr &c){return c->getNumber() == "320A";}).size() == 1);
    }
    BOOST_AUTO_TEST_CASE(RoomManagerReportRoomsTest) {
        BOOST_TEST(roomManager->reportRooms()!="");
    }

BOOST_AUTO_TEST_SUITE_END()