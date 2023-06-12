//
// Created by student on 12.06.23.
//
#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"
#include "model/Address.h"
#include "model/clientTypes/RegularClient.h"

struct TestSuiteClientManagerFixture {
    LogicContainerPtr logicContainer;
    ClientManagerPtr clientManager;

    AddressPtr  testAddress;
    ClientTypePtr testClientType;
    std::string testFirstName = "May";
    std::string testLastName = "Jonson";
    std::string testPersonalId = "111111";

    TestSuiteClientManagerFixture(){
        logicContainer = std::make_shared<LogicContainer>();
        clientManager = logicContainer->getClientManager();

        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClientType = std::make_shared<RegularClient>();
    }

    ~TestSuiteClientManagerFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(ClientManagerGetClientTest_Positive) {
        BOOST_TEST(clientManager->getClient("101010")->getFirstName() == "Sarah");
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
        BOOST_TEST(newClient->isArchived() == true);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerFindClientsTest) {
        BOOST_TEST(clientManager->findClients([](ClientPtr c){return c->getFirstName() == "Sarah";}).size() == 1);
    }

BOOST_AUTO_TEST_SUITE_END()