//
// Created by student on 16.04.23.
//
#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include "model/Bronze.h"

struct TestSuiteRentRepositoryFixture {
    StorageContainerPtr storageContainer;
    RentRepositoryPtr rentRepository;
    AddressPtr  testAddress;
    ClientTypePtr testClientType;
    ClientPtr testClient;
    VehiclePtr testVehicle;
    RentPtr testRent;

    TestSuiteRentRepositoryFixture(){
        storageContainer = std::make_shared<StorageContainer>();
        rentRepository = storageContainer->getRentRepository();
        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClientType = std::make_shared<Bronze>();
        testClient = std::make_shared<Client>("Antonina", "Kozlowska", "111111", testAddress, testClientType);
        testVehicle = std::make_shared<Vehicle>("EL 0000", 100);
        testRent = std::make_shared<Rent>(1, testClient, testVehicle, pt::not_a_date_time);
    }

    ~TestSuiteRentRepositoryFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepository, TestSuiteRentRepositoryFixture)

    BOOST_AUTO_TEST_CASE(RentRepositorySizeTest) {
        BOOST_TEST(rentRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryGetTest_Positive) {
        BOOST_TEST(rentRepository->get(0) != nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryGetTest_Negative) {
        BOOST_TEST(rentRepository->get(rentRepository->size()) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddTest_Positive) {
        unsigned int startingSize = rentRepository->size();
        rentRepository->add(testRent);
        BOOST_TEST(rentRepository->size() == startingSize + 1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryAddTest_Negative) {
        unsigned int startingSize = rentRepository->size();
        rentRepository->add(nullptr);
        BOOST_TEST(rentRepository->size() == startingSize);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveTest_Positive) {
        rentRepository->add(testRent);
        unsigned int startingSize = rentRepository->size();
        rentRepository->remove(testRent);
        BOOST_TEST(rentRepository->size() == startingSize - 1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryRemoveTest_Negative) {
        unsigned int startingSize = rentRepository->size();
        rentRepository->remove(nullptr);
        BOOST_TEST(rentRepository->size() == startingSize);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindByTest_OneItem) {
        BOOST_TEST(rentRepository->findBy([](RentPtr rent){
            return rent->getId() == 1;
        }).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindByTest_ZeroItems) {
        BOOST_TEST(rentRepository->findBy([](RentPtr rent){
            return rent->getId() == 3;
        }).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindAllTest) {
        BOOST_TEST(rentRepository->findAll().size() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()