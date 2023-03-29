//
// Created by student on 23.03.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(clientConstructorTest_Positive) {
        Client client("Leon", "Zakrzewski", "010101");
        BOOST_TEST(client.getFirstName() == "Leon");
        BOOST_TEST(client.getLastName() == "Zakrzewski");
        BOOST_TEST(client.getPersonalId() == "010101");
    }

    BOOST_AUTO_TEST_CASE(clientSetFirstNameTest_Positive) {
        Client client("Leon", "Zakrzewski", "010101");
        client.setFirstName("Judyta");
        BOOST_TEST(client.getFirstName() == "Judyta");
    }

    BOOST_AUTO_TEST_CASE(clientSetFirstNameTest_Negative) {
        Client client("Leon", "Zakrzewski", "010101");
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == "Leon");
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Positive) {
        Client client("Leon", "Zakrzewski", "010101");
        client.setLastName("Kozlowska");
        BOOST_TEST(client.getLastName() == "Kozlowska");
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Negative) {
        Client client("Leon", "Zakrzewski", "010101");
        client.setLastName("");
        BOOST_TEST(client.getLastName() == "Zakrzewski");
    }

BOOST_AUTO_TEST_SUITE_END()