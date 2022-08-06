cmake_minimum_required(VERSION 3.16)

# set the project name
project(unittest)

enable_testing()
find_package(GTest REQUIRED)

# add the executable
add_executable(unittest 
               main.cpp
               tests/simpleTest.cpp)

target_include_directories(unittest
  PUBLIC .
  PRIVATE include
)

set_target_properties(unittest
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/unittest"
)

target_link_libraries(unittest GTest::GTest GTest::Main)

add_test(NAME unittest
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
         COMMAND unittest "--gtest_output=xml:${CMAKE_BINARY_DIR}/unittest/test-report.xml")

add_custom_command(
     TARGET unittest
     COMMENT "Run tests"
     POST_BUILD 
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
     COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
)