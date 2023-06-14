cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/typedefs.h
        src/model/Client.cpp
        include/model/Client.h
        src/model/Address.cpp
        include/model/Address.h
        src/model/clientTypes/ClientType.cpp
        include/model/clientTypes/ClientType.h
        src/model/clientTypes/DefaultClient.cpp
        include/model/clientTypes/DefaultClient.h
        src/model/clientTypes/RegularClient.cpp
        include/model/clientTypes/RegularClient.h
        src/exceptions/ClientException.cpp
        include/exceptions/ClientException.h
        include/repositories/Repository.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/managers/ClientManager.cpp
        include/managers/ClientManager.h
        src/managers/LogicContainer.cpp
        include/managers/LogicContainer.h
        src/repositories/StorageContainer.cpp
        include/repositories/StorageContainer.h
        include/Functors.h
        src/model/Rent.cpp
        include/model/Rent.h
        src/exceptions/RentException.cpp
        include/exceptions/RentException.h
        src/repositories/RentRepository.cpp
        include/repositories/RentRepository.h
        src/managers/RentManager.cpp
        include/managers/RentManager.h
        src/model/rooms/Room.cpp
        include/model/rooms/Room.h
        src/model/rooms/SingleRoom.cpp
        include/model/rooms/SingleRoom.h
        src/model/rooms/DoubleRoom.cpp
        include/model/rooms/DoubleRoom.h
        src/model/rooms/Apartment.cpp
        include/model/rooms/Apartment.h
        include/managers/RoomManager.h
        src/managers/RoomManager.cpp
        include/managers/RoomManager.h
        src/repositories/RoomRepository.cpp
        include/repositories/RoomRepository.h
        src/exceptions/RoomException.cpp
        include/exceptions/RoomException.h)

#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp
        test/AddressTest.cpp
        test/repositories/ClientRepositoryTest.cpp
        test/managers/ClientManagerTest.cpp
        test/RentTest.cpp
        test/repositories/RentRepositoryTest.cpp
        test/managers/RentManagerTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})