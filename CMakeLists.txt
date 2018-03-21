cmake_minimum_required(VERSION 3.0)
project(tinyCUnit)

enable_testing()

add_executable(testTinyCUnit test_tinyCUnit.c)
set_target_properties(testTinyCUnit
    PROPERTIES
    C_STANDARD 99)

include(tinyCUnit.cmake)

add_tinytest_executable(test_nomain
    test_nomain.c)
add_tinytest_executable(test_nomain_abs
    ${CMAKE_SOURCE_DIR}/test_nomain.c)
add_tinytest_executable(test_nomain_cxx
    test_nomaincxx.cpp)

add_test(NAME TinyTest::UseHeader COMMAND testTinyCUnit)
add_test(NAME TinyTest::UseGeneratorRelPath COMMAND test_nomain)
add_test(NAME TinyTest::UseGeneratorAbsPath COMMAND test_nomain_abs)