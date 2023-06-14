//
// Created by student on 14.06.23.
//
#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"
#include "managers/RentManager.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/rooms/DoubleRoom.h"
#include "model/clientTypes/DefaultClient.h"
#include "exceptions/RentException.h"


struct TestSuiteRentManagerFixture {
    LogicContainerPtr logicContainer;
    RentManagerPtr rentManager;
    ClientPtr testClient;
    RoomPtr testRoom;

    unsigned int testNumberOfDays = 3;

    TestSuiteRentManagerFixture(){
        logicContainer = std::make_shared<LogicContainer>();
        rentManager = logicContainer->getRentManager();
        testClient = std::make_shared<Client>("May", "Jonson", "111111",
                                              std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                              std::make_shared<DefaultClient>());
        testRoom = std::make_shared<DoubleRoom>("14", 200, 3, QueenSize);
    }

    ~TestSuiteRentManagerFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(RentManagerGetALlClientRentsTest) {
        ClientPtr client = std::make_shared<Client>("John", "Doe", "010101",
                                                    std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                                    std::make_shared<DefaultClient>());
        BOOST_TEST(rentManager->getAllClientRents(client).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentManagerRentRoomTest) {
        rentManager->rentRoom(testClient, testRoom, testNumberOfDays);
        BOOST_TEST(rentManager->getAllClientRents(testClient).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentManagerFindRentTest) {
        rentManager->rentRoom(testClient, testRoom, testNumberOfDays);
        BOOST_TEST(rentManager->findRents([](RentPtr r){return r->getRoom()->getNumber() == "12";}).size() == 1);
    }


BOOST_AUTO_TEST_SUITE_END()