#include "model/Address.h"
#include <boost/test/unit_test.hpp>
//
// Created by student on 11.05.23.
//
struct TestSuiteAddressFixture {
    const std::string testCity1 = "Lodz";
    const std::string testStreet1 = "Ulica Piotrkowska";
    const std::string testNumber1 = "153";

    const std::string testCity2 = "London";
    const std::string testStreet2 = "Baker Street";
    const std::string testNumber2 = "221b";


};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, TestSuiteAddressFixture)

BOOST_AUTO_TEST_CASE(addressConstructorTest_Positive){
        Address address(testCity1, testStreet1, testNumber1);
        BOOST_TEST(address.getCity() == testCity1);
        BOOST_TEST(address.getStreet() == testStreet1);
        BOOST_TEST(address.getNumber() == testNumber1);
}

BOOST_AUTO_TEST_SUITE_END()