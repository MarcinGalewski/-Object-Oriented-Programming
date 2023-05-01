//
// Created by student on 01.05.23.
//
#include <boost/test/unit_test.hpp>
#include "managers/LogicContainer.h"
#include "model/Client.h"
#include "model/Default.h"
#include "model/Moped.h"
#include "model/Bicycle.h"

namespace gr = boost::gregorian;

struct TestSuiteRentManagerFixture {
    LogicContainerPtr logicContainer;
    RentManagerPtr rentManager;
    ClientPtr testClient;
    VehiclePtr testVehicle;

    TestSuiteRentManagerFixture(){
        logicContainer = std::make_shared<LogicContainer>();
        rentManager = logicContainer->getRentManager();
        testClient = std::make_shared<Client>("Antonina", "Kozlowska", "111111",
                                         std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                         std::make_shared<Default>());
        testVehicle = std::make_shared<Moped>("EL 1111", 150, 1500);
    }

    ~TestSuiteRentManagerFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentManager, TestSuiteRentManagerFixture)

    BOOST_AUTO_TEST_CASE(RentManagerGetALlClientRentsTest) {
        ClientPtr client = std::make_shared<Client>("Leon", "Zakrzewski", "010101",
                                                    std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                                    std::make_shared<Default>());
        BOOST_TEST(rentManager->getAllClientRents(client).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentManagerGetVehicleRentTest_Positive) {
        VehiclePtr vehicle = std::make_shared<Bicycle>("EL 0101", 20);
        BOOST_TEST(rentManager->getVehicleRent(vehicle) != nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentManagerGetVehicleRentTest_Negative) {
        BOOST_TEST(rentManager->getVehicleRent(testVehicle) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentManagerFindRent) {
        BOOST_TEST(rentManager->findRent([](RentPtr r){return r->getClient()->getFirstName() == "Judyta";}).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentManagerFindAllRents) {
        BOOST_TEST(rentManager->findAllRents().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentManagerCheckClientRentBalance) {
        ClientPtr client = std::make_shared<Client>("Leon", "Zakrzewski", "010101",
                                                    std::make_shared<Address>("London", "Accacia Avenue", "22"),
                                                    std::make_shared<Default>());
        VehiclePtr vehicle = std::make_shared<Bicycle>("EL 0101", 20);

        BOOST_TEST(rentManager->checkClientRentBalance(client) == 0);

        rentManager->returnVehicle(vehicle);

        BOOST_TEST(rentManager->checkClientRentBalance(client) != 0);
    }

    BOOST_AUTO_TEST_CASE(RentManagerRentVehicle_Positive) {
        BOOST_TEST(rentManager->rentVehicle(testClient, testVehicle, pt::not_a_date_time) != nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentManagerRentVehicle_Negative) {
        VehiclePtr vehicle = std::make_shared<Bicycle>("EL 0101", 20);
        BOOST_TEST(rentManager->rentVehicle(testClient, vehicle, pt::not_a_date_time) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentManagerReturnVehicle) {
        VehiclePtr vehicle = std::make_shared<Moped>("EL 1010", 100, 1000);
        rentManager->returnVehicle(vehicle);
        BOOST_TEST(rentManager->getVehicleRent(vehicle) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentManagerChangeClientType) {
        rentManager->rentVehicle(testClient, testVehicle, pt::ptime(gr::date(2023, 1, 1), pt::hours(12) + pt::minutes(30)));
        rentManager->returnVehicle(testVehicle);
        BOOST_TEST(testClient->getMaxVehicles() == 10);
    }


BOOST_AUTO_TEST_SUITE_END()