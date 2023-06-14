#include <boost/test/unit_test.hpp>
#include "typedefs.h"
#include "model/rooms/SingleRoom.h"
#include "exceptions/RoomException.h"
#include "model/rooms/DoubleRoom.h"
#include "model/rooms/Apartment.h"

struct TestSuiteRoomFixture {
    const std::string testNumber1 = "203B";
    const int testPrice1=120;
    const int testRoomCapacity1=1;
    const std::string testNumber2 = "304C";
    const int testPrice2=220;
    const int testRoomCapacity2=2;
    const BedType testBedType1=QueenSize;
    const BedType testBedType2=KingSize;
    const int testNumberOfAmenities1=5;
    const int testNumberOfAmenities2=4;
    RoomPtr testRoom1;
    RoomPtr testRoom2;
    RoomPtr testRoom3;

    TestSuiteRoomFixture() {
        testRoom1 = std::make_shared<SingleRoom>(testNumber1, testPrice1, testRoomCapacity1);
        testRoom2 = std::make_shared<DoubleRoom>(testNumber1, testPrice1, testRoomCapacity1,testBedType1);
        testRoom3 = std::make_shared<Apartment>(testNumber1, testPrice1, testRoomCapacity1,testNumberOfAmenities1);
    }

    ~TestSuiteRoomFixture() = default;

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoom, TestSuiteRoomFixture)

    BOOST_AUTO_TEST_CASE(RoomConstructorTest_Positive) {
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        BOOST_TEST(r.getNumber() == testNumber1);
        BOOST_TEST(r.getPrice() == testPrice1);
        BOOST_TEST(r.getRoomCapacity() == testRoomCapacity1);
        BOOST_TEST(r.isArchived() == false);
    }

    BOOST_AUTO_TEST_CASE(RoomConstructorTest_Negative) {
        BOOST_CHECK_THROW(SingleRoom r("", testPrice1, testRoomCapacity1), RoomException);
    }

    BOOST_AUTO_TEST_CASE(RoomSetNumberTest_PosSingleRoomitive) {
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        r.setNumber(testNumber2);
        BOOST_TEST(r.getNumber() == testNumber2);
    }

    BOOST_AUTO_TEST_CASE(RoomSetNumberTest_Negative) {
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        BOOST_CHECK_THROW(r.setNumber(""), RoomException);
    }

    BOOST_AUTO_TEST_CASE(RoomSetPriceTest_Positive) {
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        r.setPrice(testPrice2);
        BOOST_TEST(r.getPrice() == testPrice2);
    }

    BOOST_AUTO_TEST_CASE(RoomSetPriceTest_Negative) {
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        BOOST_CHECK_THROW(r.setPrice(0), RoomException);
    }

    BOOST_AUTO_TEST_CASE(RoomSetRoomCapacityTest_Positive) {
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        r.setRoomCapacity(testRoomCapacity2);
        BOOST_TEST(r.getRoomCapacity() == testRoomCapacity2);
    }

    BOOST_AUTO_TEST_CASE(RoomSetRoomCapacityTest_Negative) {
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        BOOST_CHECK_THROW(r.setRoomCapacity(0), RoomException);
    }

    BOOST_AUTO_TEST_CASE(RoomSetArchiveTest){
        SingleRoom r(testNumber1, testPrice1, testRoomCapacity1);
        r.setArchived(true);
        BOOST_TEST(r.isArchived() == true);
    }

    BOOST_AUTO_TEST_CASE(DoubleRoomConstructorTest_Positive) {
        DoubleRoom r(testNumber1, testPrice1, testRoomCapacity1,testBedType1);
        BOOST_TEST(r.getNumber() == testNumber1);
        BOOST_TEST(r.getPrice() == testPrice1);
        BOOST_TEST(r.getRoomCapacity() == testRoomCapacity1);
        BOOST_TEST(r.getBedType() == testBedType1);
        BOOST_TEST(r.isArchived() == false);
    }

    BOOST_AUTO_TEST_CASE(DoubleRoomConstructorTest_Negative) {
        BOOST_CHECK_THROW(DoubleRoom r("", testPrice1, testRoomCapacity1, testBedType1), RoomException);
    }

    BOOST_AUTO_TEST_CASE(DoubleRoomSetBedTypeTest_Positive) {
        DoubleRoom r(testNumber1, testPrice1, testRoomCapacity1, testBedType1);
        r.setBedType(testBedType2);
        BOOST_TEST(r.getBedType() == testBedType2);
    }

    BOOST_AUTO_TEST_CASE(DoubleRoomSetBedTypeTest_Negative) {
        DoubleRoom r(testNumber1, testPrice1, testRoomCapacity1, testBedType1);
        BOOST_CHECK_THROW(r.setBedType(static_cast<BedType>(-1)), RoomException);
    }

    BOOST_AUTO_TEST_CASE(DoubleRoomSetArchiveTest){
        DoubleRoom r(testNumber1, testPrice1, testRoomCapacity1, testBedType1);
        r.setArchived(true);
        BOOST_TEST(r.isArchived() == true);
    }

    BOOST_AUTO_TEST_CASE(ApartmentSetBedTypeTest_Positive) {
        Apartment r(testNumber1, testPrice1, testRoomCapacity1, testNumberOfAmenities1);
        r.setNumberOfAmenities(testNumberOfAmenities2);
        BOOST_TEST(r.getNumberOfAmenities() == testNumberOfAmenities2);
    }

    BOOST_AUTO_TEST_CASE(ApartmentSetBedTypeTest_Negative) {
        Apartment r(testNumber1, testPrice1, testRoomCapacity1, testNumberOfAmenities1);
        BOOST_CHECK_THROW(r.setNumberOfAmenities(10), RoomException);
    }

BOOST_AUTO_TEST_SUITE_END()