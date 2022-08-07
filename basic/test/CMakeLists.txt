cmake_minimum_required(VERSION 3.16)

# set the project name
project(unittest)

set (TEST_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(test-output-directory AKK
                  COMMAND ${CMAKE_COMMAND} - E make_directory ${TEST_OUTPUT_DIRECTORY})

enable_testing()
find_package(GTest REQUIRED)

# add the executable
add_executable(unittest 
               main.cpp
               tests/evenOddTransformTests.cpp
               tests/simpleTest.cpp)

target_include_directories(unittest
  PUBLIC .
  PRIVATE include
)

add_custom_target(rununittest unittest COMMAND $<TARGET_FILE:unittest> DEPENDS unittest)

set_target_properties(unittest
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/unittest"
)

target_link_libraries(unittest GTest::GTest GTest::Main)

add_test(NAME unittest
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
         COMMAND unittest "--gtest_output=xml:${CMAKE_BINARY_DIR}/unittest/test-report.xml")

add_custom_command(
     TARGET rununittest
     COMMENT "Run tests"
     POST_BUILD 
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
     # COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failures
     COMMAND ctest -C $<CONFIGURATION> --output-on-failures
)
