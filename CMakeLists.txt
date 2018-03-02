cmake_minimum_required(VERSION 3.0)
project(tinyCUnit)

add_executable(testTinyCUnit test_tinyCUnit.c)
set_target_properties(testTinyCUnit
    PROPERTIES
    C_STANDARD 99)
