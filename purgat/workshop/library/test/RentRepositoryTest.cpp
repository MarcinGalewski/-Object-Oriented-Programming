//
// Created by student on 16.04.23.
//
#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"

struct TestSuiteRentRepositoryFixture {
    StorageContainerPtr storageContainer;
    RentRepositoryPtr rentRepository;
    AddressPtr  testAddress;
    ClientPtr testClient;
    VehiclePtr testVehicle;
    RentPtr testRent;

    TestSuiteRentRepositoryFixture(){
        storageContainer = new StorageContainer();
        rentRepository = storageContainer->getRentRepository();
        testAddress = new Address("London", "Accacia Avenue", "22");
        testClient = new Client("Antonina", "Kozlowska", "111111", testAddress);
        testVehicle = new Vehicle("EL 0000", 100);
        testRent = new Rent(1, testClient, testVehicle, pt::not_a_date_time);
    }

    ~TestSuiteRentRepositoryFixture(){
        delete storageContainer;
        delete testAddress;
        delete testClient;
        delete testVehicle;
        delete testRent;
    }
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
        rentRepository->add(new Rent(1, new Client("Antonina", "Kozlowska", "111111", new Address("London", "Accacia Avenue", "22")),
                            new Vehicle("EL 1001", 100), pt::not_a_date_time));
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