//
// Created by wein on 12/15/17.
//


#include <tinyCUnit.h>


int main(int argc, char** argv) {
    AddTinyTest(OnePlusOne_ExpectTwo);
    return RUN_ALL_TESTS();
}