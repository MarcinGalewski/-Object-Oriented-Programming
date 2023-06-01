//
// Created by student on 31.05.23.
//
#include <boost/test/unit_test.hpp>

#include "typedefs.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/clientTypes/RegularClient.h"
#include "model/clientTypes/DefaultClient.h"
#include "exceptions/ClientException.h"


struct TestSuiteClientFixture {
    const std::string testFirstName1 = "John";
    const std::string testLastName1 = "Doe";
    const std::string testPersonalID1 = "010101";

    const std::string testFirstName2 = "Sarah";
    const std::string testLastName2= "Smith";

    AddressPtr testAddress1;
    AddressPtr testAddress2;

    ClientTypePtr testClientType1;
    ClientTypePtr testClientType2;

    TestSuiteClientFixture() {
        testAddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testAddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");
        testClientType1 = std::make_shared<DefaultClient>();
        testClientType2 = std::make_shared<RegularClient>();
    }

    ~TestSuiteClientFixture() {}

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(clientConstructorTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        BOOST_TEST(client.getFirstName() == testFirstName1);
        BOOST_TEST(client.getLastName() == testLastName1);
        BOOST_TEST(client.getPersonalId() == testPersonalID1);
        BOOST_TEST(client.getAddress() == testAddress1);
        BOOST_TEST(client.isArchived() == false);
    }

    BOOST_AUTO_TEST_CASE(clientConstructorTest_Negative) {
        BOOST_CHECK_THROW(Client client("", testLastName1, testPersonalID1, testAddress1, testClientType1), ClientException);
        BOOST_CHECK_THROW(Client client(testFirstName1, testLastName1, testPersonalID1, nullptr, testClientType1), ClientException);
    }

    BOOST_AUTO_TEST_CASE(clientSetFirstNameTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setFirstName(testFirstName2);
        BOOST_TEST(client.getFirstName() == testFirstName2);
    }

    BOOST_AUTO_TEST_CASE(clientSetFirstNameTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        BOOST_CHECK_THROW(client.setFirstName(""), ClientException);
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setLastName(testLastName2);
        BOOST_TEST(client.getLastName() == testLastName2);
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        BOOST_CHECK_THROW(client.setLastName(""), ClientException);
    }

    BOOST_AUTO_TEST_CASE(clientSetAddressTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setAddress(testAddress2);
        BOOST_TEST(client.getAddress() == testAddress2);
    }

    BOOST_AUTO_TEST_CASE(clientSetAddressTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        BOOST_CHECK_THROW(client.setAddress(nullptr), ClientException);
    }

    BOOST_AUTO_TEST_CASE(clientSetClientTypeTest_Positive){
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setClientType(testClientType2);
        BOOST_TEST(client.applyDiscount(100) == 20);
    }

    BOOST_AUTO_TEST_CASE(clientSetClientTypeTest_Negative){
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        BOOST_CHECK_THROW(client.setClientType(nullptr), ClientException);
    }

    BOOST_AUTO_TEST_CASE(clientSetArchiveTest){
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setArchived(true);
        BOOST_TEST(client.isArchived() == true);
    }
BOOST_AUTO_TEST_SUITE_END()