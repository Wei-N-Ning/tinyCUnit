A Tiny C Unit Test Helper
-------------------------

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

Once built and executed, the test runner prints a summary in the shell:

```
TinyTest: ExpectValueIs10......PASSED
TinyTest: GivenSizeExpectProduct......PASSED

Summary: 2 tests, 0.000115s (115.000000ms)
```

It is highly recommended to take a look at Clean Code: A Handbook of Agile Software Craftsmanship, 
by Uncle Bob.

### How does it work

Tiny C Unit uses the "anonymous function" (lambda) technique.

It creates a function pointer array (and a c-string array to hold the function names) in order to 
keep track of all the test functions. 

RunTinyTests(), the test runner will iterate over these function pointers and call them one by one.

