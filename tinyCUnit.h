//
// Created by wein on 3/2/18.
//

#ifndef TINYCUNIT_H
#define TINYCUNIT_H

#include <assert.h>
#include <stdio.h>

#ifndef MAXNUMTESTFUNCS
#define MAXNUMTESTFUNCS 1024
#endif

#define __TestFunc(function_body) \
({ \
    void __fn__ function_body \
      __fn__; \
})

#define NewTinyTest(function_name) __TestFuncIdx++; TestNames[__TestFuncIdx]=function_name; TestFuncs[__TestFuncIdx] = __TestFunc
#define AssertTrue(actual) (assert(actual))
#define AssertEqual(expected, actual) (assert(expected == actual))

typedef void (*__TestFunc_t)(void);
__TestFunc_t TestFuncs[MAXNUMTESTFUNCS] = {};
char **TestNames[MAXNUMTESTFUNCS] = {};
int __TestFuncIdx = -1;

#endif //TINYCUNIT_H

void InitializeTinyTests() {
    for (int i=0; i < MAXNUMTESTFUNCS; ++i) {
        TestFuncs[i] = NULL;
    }
}

void RunTinyTests() {
    for (int i=0; i <= __TestFuncIdx; ++i) {
        printf("TinyTest: %s......", TestNames[i]);
        TestFuncs[i]();
        printf("PASSED\n");
    }
}
