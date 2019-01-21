#ifndef PROJ_TESTS_H
#define PROJ_TESTS_H
#include <wordFrequency.h>
#include <iostream>

namespace wcount_eric
{
	// run all the tests
	void all_tests(int argc, char** argv);

	// run all the tests
	void all_tests(std::string file);

	// Requirement: we can make an instance of the class with 
	// or without a given filepath
	bool test_make_instance();

	// Requirement: we can connect a file input stream to the filepath
	// and read the contents
	bool test_load_file(std::string file);

	// Requirement: words stored contain only lower case alphabet letters
	// no punctuation, spaces or symbols
	bool test_word_formatting(std::string file);
	
	// Requirement: repeated words are counted properly
	bool test_word_count(std::string file);

	// Requirement: we can make a sorted list of the words by count.
	// A user of the class can access this sorted list
	bool test_sort_by_count(std::string file);
	
} //wcount_eric
#endif //PROJ_TESTS_H
