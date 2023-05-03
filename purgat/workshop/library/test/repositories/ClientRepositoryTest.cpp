//
// Created by student on 15.04.23.
//
#include <boost/test/unit_test.hpp>
#include "repositories/StorageContainer.h"
#include "model/Bronze.h"
#include "Functors.h"

struct TestSuiteClientRepositoryFixture {
    StorageContainerPtr storageContainer;
    ClientRepositoryPtr clientRepository;
    AddressPtr  testAddress;
    ClientTypePtr testClientType;
    ClientPtr testClient;

    TestSuiteClientRepositoryFixture(){
        storageContainer = std::make_shared<StorageContainer>();
        clientRepository = storageContainer->getClientRepository();
        testAddress = std::make_shared<Address>("London", "Accacia Avenue", "22");
        testClientType = std::make_shared<Bronze>();
        testClient = std::make_shared<Client>("Antonina", "Kozlowska", "111111", testAddress, testClientType);
    }

    ~TestSuiteClientRepositoryFixture(){}
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientRepository, TestSuiteClientRepositoryFixture)

    BOOST_AUTO_TEST_CASE(ClientRepositorySizeTest) {
        BOOST_TEST(clientRepository->size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryGetTest_Positive) {
        BOOST_TEST(clientRepository->get(0) != nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryGetTest_Negative) {
        BOOST_TEST(clientRepository->get(clientRepository->size()) == nullptr);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddTest_Positive) {
        unsigned int startingSize = clientRepository->size();
        clientRepository->add(testClient);
        BOOST_TEST(clientRepository->size() == startingSize + 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddTest_Negative) {
        unsigned int startingSize = clientRepository->size();
        clientRepository->add(nullptr);
        BOOST_TEST(clientRepository->size() == startingSize);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveTest_Positive) {
        clientRepository->add(testClient);
        unsigned int startingSize = clientRepository->size();
        clientRepository->remove(testClient);
        BOOST_TEST(clientRepository->size() == startingSize - 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveTest_Negative) {
        unsigned int startingSize = clientRepository->size();
        clientRepository->remove(nullptr);
        BOOST_TEST(clientRepository->size() == startingSize);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindByTest_OneItem) {
        FirstNamePredicate predicate("Leon");
        BOOST_TEST(clientRepository->findBy(predicate).size() == 1);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindByTest_ZeroItems) {
        LastNamePredicate predicate("");
        BOOST_TEST(clientRepository->findBy(predicate).size() == 0);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindAllTest) {
        BOOST_TEST(clientRepository->findAll().size() == 2);
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindByPersonalIdTest_Positive) {
        clientRepository->add(testClient);
        BOOST_TEST(clientRepository->findByPersonalId(testClient->getPersonalId())->getLastName() == testClient->getLastName());
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryFindByPersonalIdTest_Negative) {
        BOOST_TEST( clientRepository->findByPersonalId("000000") == nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()