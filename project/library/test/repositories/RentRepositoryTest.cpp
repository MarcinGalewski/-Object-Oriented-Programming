//
// Created by student on 14.06.23.
//
#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid.hpp>
#include "repositories/StorageContainer.h"
#include "repositories/RentRepository.h"
#include "model/clientTypes/DefaultClient.h"
#include "model/Client.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "model/rooms/DoubleRoom.h"

struct TestSuiteRentRepositoryFixture {
    StorageContainerPtr storageContainer;
    RentRepositoryPtr rentRepository;
    AddressPtr  testAddress;
    ClientTypePtr testClientType;
    ClientPtr testClient;
    RoomPtr testRoom;
    RentPtr testRent;

    boost::uuids::uuid testId = boost::uuids::random_generator()();

    TestSuiteRentRepositoryFixture(){
        storageContainer = std::make_shared<StorageContainer>();
        rentRepository = storageContainer->getRentRepository();
        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClientType = std::make_shared<DefaultClient>();
        testClient = std::make_shared<Client>("May", "Jonson", "111111", testAddress, testClientType);
        testRoom = std::make_shared<DoubleRoom>("12", 200, 3, QueenSize);
        testRent = std::make_shared<Rent>(testId, testClient, testRoom, 3);
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
        rentRepository->add(testRent);
        BOOST_TEST(rentRepository->findBy([this](RentPtr rent){
            return rent->getId() == testId;
        }).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindByTest_ZeroItems) {
        BOOST_TEST(rentRepository->findBy([](RentPtr rent){
            return rent->getId() == boost::uuids::random_generator()();
        }).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(RentRepositoryFindAllTest) {
        BOOST_TEST(rentRepository->findAll().size() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()