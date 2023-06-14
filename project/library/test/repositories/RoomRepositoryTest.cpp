//
// Created by student on 14.06.23.
//
#include <boost/test/unit_test.hpp>

#include "typedefs.h"
#include "repositories/RoomRepository.h"
#include "model/rooms/SingleRoom.h"
#include "model/rooms/DoubleRoom.h"
#include "model/rooms/Apartment.h"

struct TestSuiteRoomRepositoryFixture {
    RoomRepositoryPtr roomRepository;
    RoomPtr  testRoom1;
    RoomPtr  testRoom2;
    RoomPtr  testRoom3;
    RoomPtr  testRoom4;
    RoomPtr  testRoom5;

    TestSuiteRoomRepositoryFixture(){
        roomRepository = std::make_shared<RoomRepository>();
        testRoom1 = std::make_shared<SingleRoom>("215A", 150, 1);
        testRoom2 = std::make_shared<DoubleRoom>("220B", 200, 2,QueenSize);
        testRoom3 = std::make_shared<Apartment>("450C", 800, 4,5);
        testRoom4 = std::make_shared<DoubleRoom>("450C", 800, 4,KingSize);
        testRoom5 = std::make_shared<Apartment>("450C", 700, 4,4);
        roomRepository->add(testRoom1);
        roomRepository->add(testRoom2);
    }

    ~TestSuiteRoomRepositoryFixture()= default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoomRepository, TestSuiteRoomRepositoryFixture)

    BOOST_AUTO_TEST_CASE(RoomRepositorySizeTest) {
        BOOST_TEST(roomRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryGetTest_Positive) {
        BOOST_TEST(roomRepository->get(0) != nullptr);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryGetTest_Negative) {
        BOOST_TEST(roomRepository->get(roomRepository->size()) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryAddTest_Positive) {
        unsigned int startingSize = roomRepository->size();
        roomRepository->add(testRoom3);
        BOOST_TEST(roomRepository->size() == startingSize + 1);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryAddTest_Negative) {
        unsigned int startingSize = roomRepository->size();
        roomRepository->add(nullptr);
        BOOST_TEST(roomRepository->size() == startingSize);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryRemoveTest_Positive) {
        roomRepository->add(testRoom4);
        unsigned int startingSize = roomRepository->size();
        roomRepository->remove(testRoom4);
        BOOST_TEST(roomRepository->size() == startingSize - 1);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryRemoveTest_Negative) {
        unsigned int startingSize = roomRepository->size();
        roomRepository->remove(nullptr);
        BOOST_TEST(roomRepository->size() == startingSize);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryFindAllTest) {
        BOOST_TEST(roomRepository->findAll().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryFindByRoomNumberTest_Positive) {
        roomRepository->add(testRoom5);
        BOOST_TEST(roomRepository->findByRoomNumber(testRoom5->getNumber())->getPrice() == testRoom5->getPrice());
    }

    BOOST_AUTO_TEST_CASE(RoomRepositoryFindByRoomNumberTest_Negative) {
        BOOST_TEST( roomRepository->findByRoomNumber("000000") == nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()