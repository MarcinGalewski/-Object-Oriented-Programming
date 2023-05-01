//
// Created by student on 31.03.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Address.h"

struct TestSuiteAddressFixture {
    const std::string testCity1 = "Lodz";
    const std::string testStreet1 = "Aleje Politechniki";
    const std::string testNumber1 = "9a";

    const std::string testCity2 = "London";
    const std::string testStreet2 = "Abbey Road";
    const std::string testNumber2 = "12/4";


};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

    BOOST_AUTO_TEST_CASE(addressConstructorTest){
        Address address(testCity1, testStreet1, testNumber1);
        BOOST_TEST(address.getCity() == testCity1);
        BOOST_TEST(address.getStreet() == testStreet1);
        BOOST_TEST(address.getNumber() == testNumber1);
    }

BOOST_AUTO_TEST_SUITE_END()