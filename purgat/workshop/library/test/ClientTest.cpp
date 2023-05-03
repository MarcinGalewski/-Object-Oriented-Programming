//
// Created by student on 23.03.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Bronze.h"
#include "model/Default.h"
#include "exceptions/ClientException.h"

struct TestSuiteClientFixture {
    const std::string testFirstName1 = "Leon";
    const std::string testLastName1 = "Zakrzewski";
    const std::string testPersonalID1 = "010101";

    const std::string testFirstName2 = "Judyta";
    const std::string testLastName2= "Kozlowska";

    AddressPtr testAddress1;
    AddressPtr testAddress2;

    ClientTypePtr testClientType1;
    ClientTypePtr testClientType2;

    TestSuiteClientFixture() {
        testAddress1 = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testAddress2 = std::make_shared<Address>("London", "Rue Morgue", "13");
        testClientType1 = std::make_shared<Default>();
        testClientType2 = std::make_shared<Bronze>();
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
        BOOST_TEST(client.isArchive() == false);
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
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == testFirstName1);
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setLastName(testLastName2);
        BOOST_TEST(client.getLastName() == testLastName2);
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setLastName("");
        BOOST_TEST(client.getLastName() == testLastName1);
    }

    BOOST_AUTO_TEST_CASE(clientSetAddressTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setAddress(testAddress2);
        BOOST_TEST(client.getAddress() == testAddress2);
    }

    BOOST_AUTO_TEST_CASE(clientSetAddressTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setAddress(nullptr);
        BOOST_TEST(client.getAddress() == testAddress1);
    }

    BOOST_AUTO_TEST_CASE(clientSetClientTypeTest_Positive){
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setClientType(testClientType2);
        BOOST_TEST(client.getMaxVehicles() == 2);
    }

    BOOST_AUTO_TEST_CASE(clientSetClientTypeTest_Negative){
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setClientType(nullptr);
        BOOST_TEST(client.getMaxVehicles() == 1);
    }

    BOOST_AUTO_TEST_CASE(clientSetArchiveTest){
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1, testClientType1);
        client.setArchive(true);
        BOOST_TEST(client.isArchive() == true);
    }

BOOST_AUTO_TEST_SUITE_END()