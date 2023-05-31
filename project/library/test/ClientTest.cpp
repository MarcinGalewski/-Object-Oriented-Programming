//
// Created by student on 31.05.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"

struct TestSuiteClientFixture {

    TestSuiteClientFixture() {
    }

    ~TestSuiteClientFixture() {}

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(clientConstructorTest_Positive) {
        BOOST_TEST(true);
    }
BOOST_AUTO_TEST_SUITE_END()