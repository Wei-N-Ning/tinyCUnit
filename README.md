A Tiny C Unit Test Helper
-------------------------

To bring xUnit in C with minimal set up overhead.

Tested on Ubuntu 16.

### Usage

Copy [tinyCUnit.h](tinyCUnit.h) to somewhere your tests can #include from.

In your test:

```C
#include "tinyCUnit.h"

// ... include your SUTs; Define other test helper functions

int main() {
    
    InitializeTinyTests();
    
    // give each test a good, descriptive name - see cleancode 
    NewTinyTest("Something") ((void) {
        
        // test body goes here - follow the AAA idiom in cleancode
        
        // Tiny C Unit provides two assertion functions (macros):
        // AssertEqual(a, b)
        // AssertTrue(a)
        // feel free to use the standard C library assert() function
        
        AssertEqual(0, 0);
        
        // test function does not return;
    });
    
    NewTinyTest("Otherthing") ((void) {
        AssertEqual(0, 0);
    });
    
    // ... other tests...
    
    RunTinyTests();
    return 0;
}

```

See [test_tinyCUnit.c](test_tinyCUnit.c) for a complete example.

Once built and executed, the test runner prints a summary in the shell:

```
TinyTest: ExpectValueIs10......PASSED
TinyTest: GivenSizeExpectProduct......PASSED

Summary: 2 tests, 0.000115s (115.000000ms)
```

It is highly recommended to take a look at Clean Code: A Handbook of Agile Software Craftsmanship, 
 written by Uncle Bob to get a good understanding of TDD methodology.

### How does it work

Tiny C Unit uses the "anonymous function" (lambda) technique.

It creates a function pointer array (and a c-string array to hold the function names) in order to 
keep track of all the test functions (anonymous functions). 

The size of both arrays determines the total number of tests you can create per test executable.

The default value is 1024. You may override this value via a compiler flag:

```
-DMAXNUMTESTFUNCS=2048
```

This means you can create up to 2048 tests in one executable...... something I would not recommend :)

RunTinyTests(), the test runner, will iterate over these function pointers and call them one by one. 

For convenience the test runner also measures the execution time (although the result is not 
 perfectly accurate). I'm hoping to improve that in the future.

SetUp() and TearDown() are not supported at the moment, but it is possible to implement them using 
the same function pointer technique.
