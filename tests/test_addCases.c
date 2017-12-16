//
// Created by wein on 12/15/17.
//

#include <tinyCUnit.h>


TINYTEST ExpectEqual() {
    ASSERT_EQ(1, 1);
}


TINYTEST ExpectNotEqual() {
    ASSERT_NE(1, 2);
}


int main(int argc, char **argv) {
    AddTinyTest(ExpectEqual);
    AddTinyTest(ExpectNotEqual);
    return RUN_ALL_TESTS();
}