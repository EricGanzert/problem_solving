#ifndef PROJ_TESTS_H
#define PROJ_TESTS_H
#include <wordFrequency.h>
#include <iostream>

// run all the tests
void all_tests(int argc, char** argv);

// Requirement: we can make an instance of the class with 
// or without a given filepath. Doesn't care if the filepath is good or bad
// when creating the instance
bool test_make_instance();

// Note: I decided the filepath member 'get' and 'set' methods
// don't need a test. Because it's ok if the filepath doesn't exist
// at the time you use 'set'

// Requirement: we can connect a file input stream to the filepath
// and read the contents
bool test_load_file();

#endif //PROJ_TESTS_H
