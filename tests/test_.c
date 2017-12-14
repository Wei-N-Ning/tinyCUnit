//
// Created by wein on 12/15/17.
//

#include <tinyunit.h>


TinyCase ExpectEqual() {
    ASSERT_EQ(1, 1);
}


TinyCase ExpectNotEqual() {
    ASSERT_NE(1, 2);
}


int main(int argc, char **argv) {
    AddTinyCase(ExpectEqual);
    AddTinyCase(ExpectNotEqual);
    return RUN_ALL_TESTS();
}