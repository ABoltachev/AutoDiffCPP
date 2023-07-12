cmake_minimum_required(VERSION 3.16)

project(AutoDiff)

find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/libautodiff/*.cpp)

list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/libautodiff/*.test.cpp)

add_library(AutoDiff SHARED ${SOURCES})

target_compile_definitions(AutoDiff PUBLIC LIBAUTODIFF_EXPORTS)

include_directories(${CMAKE_SOURCE_DIR})

enable_testing()

file(GLOB_RECURSE CORE_GRAPH_UTESTS ${CMAKE_SOURCE_DIR}/libautodiff/*.test.cpp)

add_executable(CoreGraphUTests ${CORE_GRAPH_UTESTS})
target_link_libraries(CoreGraphUTests GTest::gtest_main AutoDiff)

include(GoogleTest)
gtest_discover_tests(CoreGraphUTests)
