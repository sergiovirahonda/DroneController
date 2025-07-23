cmake_minimum_required(VERSION 3.16)
project(DroneControllerTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add source files for domain layer
set(DOMAIN_SOURCES
    ${CMAKE_SOURCE_DIR}/../internal/domain/attitude.cpp
    ${CMAKE_SOURCE_DIR}/../internal/domain/motor_output.cpp
    ${CMAKE_SOURCE_DIR}/../internal/domain/drone_command.cpp
)

# Add test files
set(TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/domain/attitude_test.cpp
    ${CMAKE_SOURCE_DIR}/domain/motor_output_test.cpp
    ${CMAKE_SOURCE_DIR}/domain/drone_command_test.cpp
)

add_executable(drone_controller_tests ${DOMAIN_SOURCES} ${TEST_SOURCES})
target_include_directories(drone_controller_tests PRIVATE ${CMAKE_SOURCE_DIR}/../internal/domain)
target_link_libraries(drone_controller_tests GTest::GTest GTest::Main pthread) 