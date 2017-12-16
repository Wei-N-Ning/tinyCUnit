//
// Created by wein on 12/15/17.
//


#include <tinyCUnit.h>


TINYTEST OnePlusOne_ExpectTwo() {
    ASSERT_EQ(2, 1 + 1);
};


#include "test_A_main.c"
