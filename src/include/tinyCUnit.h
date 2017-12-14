//
// Created by wein on 12/15/17.
//

#ifndef TINYUNIT_TINYUNIT_H
#define TINYUNIT_TINYUNIT_H

#include <assert.h>
#include <stdio.h>

#ifndef MAXCASES
#define MAXCASES 255
#endif


struct TinyCase_T {
    const char *name;
    void (*pFunc)();
};


struct TinyCase_T *INVALID = 0;


struct TinyCase_T tinyCases[MAXCASES];


struct TinyCase_T *nextTinyCase() {
    struct TinyCase_T *pTC = tinyCases;
    for (int i = 0; i < MAXCASES; ++i, ++pTC) {
        if (!pTC->pFunc) {
            return pTC;
        }
    }
    return INVALID;
}


void addTinyCase(const char *name, void (*pFunc)()) {
    struct TinyCase_T *pTC = nextTinyCase();
    if (pTC) {
        pTC->name = name;
        pTC->pFunc = pFunc;
    }
}


int RUN_ALL_TESTS() {
    struct TinyCase_T *pTC = tinyCases;
    int i = 0;
    for (; i < MAXCASES; ++i, ++pTC) {
        if (!pTC->pFunc) {
            break;
        }
        printf("---- test case: %s ----\n", pTC->name);
        pTC->pFunc();
    }
    printf("Run %d tests\n", i);
    return 0;
}


#define AddTinyCase(x) addTinyCase(#x, &x)

#define ASSERT_EQ(x, y) assert(x == y)
#define ASSERT_NE(x, y) assert(x != y)
#define ASSERT_TRUE(x) assert(x)
#define ASSERT_FALSE(x) assert(!x)


#endif //TINYUNIT_TINYUNIT_H
