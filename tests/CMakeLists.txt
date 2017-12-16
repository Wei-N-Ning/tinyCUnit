
add_executable(test_addCases
    test_addCases.c)
target_link_libraries(test_addCases tinyCUnit)
add_test(NAME tinyCUnit::addCases COMMAND test_addCases)


add_executable(test_mainFunc
    test_A.c)
target_link_libraries(test_mainFunc tinyCUnit)
add_test(NAME tinyCUnit::mainFunc COMMAND test_mainFunc)

