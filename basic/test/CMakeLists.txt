cmake_minimum_required(VERSION 3.16)

# set the project name
project(unittest)

include(CTest)
add_definitions(-DUNITTEST)
enable_testing()

set (TEST_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(test-output-directory ALL
                  COMMAND ${CMAKE_COMMAND} -E make_directory ${TEST_OUTPUT_DIRECTORY})

find_package(GTest REQUIRED)

# add the executable
add_executable(unittest 
               main.cpp
               tests/evenOddTransformTests.cpp
               tests/quadraticEquationTests.cpp
               tests/simpleTest.cpp)

target_include_directories(unittest
  PUBLIC .
  PRIVATE include
)

set_target_properties(unittest
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries(unittest GTest::GTest GTest::Main)

add_test(NAME unittest
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
         COMMAND unittest "--gtest_output=xml:${CMAKE_BINARY_DIR}/test-report.xml")

# define tests
#add_test(
#  NAME unittest
#  COMMAND $<TARGET_FILE:unittest>
#)
