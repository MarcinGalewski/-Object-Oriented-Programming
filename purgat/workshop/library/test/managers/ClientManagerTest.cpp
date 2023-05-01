//
// Created by student on 27.04.23.
//
#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"
#include "model/Bronze.h"
#include "model/Default.h"

struct TestSuiteClientManagerFixture {
    LogicContainerPtr logicContainer;
    ClientManagerPtr clientManager;

    AddressPtr  testAddress;
    ClientTypePtr testClientType;
    std::string testFirstName = "Antonina";
    std::string testLastName = "Kozlowska";
    std::string testPersonalId = "111111";

    TestSuiteClientManagerFixture(){
        logicContainer = std::make_shared<LogicContainer>();
        clientManager = logicContainer->getClientManager();

        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClientType = std::make_shared<Bronze>();
    }

    ~TestSuiteClientManagerFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ClientManagerGetClientTest_Positive) {
        BOOST_TEST(clientManager->getClient("101010")->getFirstName() == "Judyta");
    }

    BOOST_AUTO_TEST_CASE(ClientManagerGetClientTest_Negative) {
        BOOST_TEST(clientManager->getClient("000000") == nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerRegisterClientTest) {
       clientManager->registerClient
        (testFirstName, testLastName, testPersonalId, testAddress, testClientType);
        BOOST_TEST(clientManager->getClient(testPersonalId)->getFirstName() == testFirstName);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerUnregisterClientTest) {
        ClientPtr newClient = clientManager->registerClient
                (testFirstName, testLastName, testPersonalId, testAddress, testClientType);
        clientManager->unregisterClient(newClient);
        BOOST_TEST(newClient->isArchive() == true);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerFindClientsTest) {
        BOOST_TEST(clientManager->findClients([](ClientPtr c){return c->getFirstName() == "Judyta";}).size() == 1);
    }

BOOST_AUTO_TEST_SUITE_END()