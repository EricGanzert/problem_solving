#include <projectTests.h>
using namespace std;

namespace wcount_eric
{	
	void all_tests(int argc, char** argv)
	{
		if (argc < 2)
		{
			cout << "Error: no filepath given. Usage is: ./wcount path_to_file\n";
			return;
		}
		else
		{
			string file = argv[1];
			all_tests(file);
		}		
	}
	
	void all_tests(string file)
	{
		if (!test_make_instance())
			cout << "FAILED make class instance test\n\n";
		else
			cout << "PASSED make class instance test\n\n";
		
		
		if (!test_load_file(file))
			cout << "FAILED load the file test\n\n";
		else
			cout << "PASSED load the file test\n\n";
		

		if (!test_word_formatting(file))
			cout << "FAILED word formatting test\n\n";
		else
			cout << "PASSED word formatting test\n\n";

		if (!test_word_count(file))
			cout << "FAILED word count test\n\n";
		else
			cout << "PASSED word count test\n\n";

		if (!test_sort_by_count(file))
			cout << "FAILED sorting by count test\n\n";
		else
			cout << "PASSED sorting by count test\n\n";
			
			
		cout << "Tests finished\n";
	}
	
	//this helper function allows us to avoid repeating
	//the same code in multiple tests
	bool test_load_file_helper(string file, WordReader& reader)
	{
		reader.set_filepath(file);
		
		//fail the test in case of file errors from load_file method
		try
		{
			reader.load_file();
		}
		catch (FileError e)
		{
			cout << e.get_message() << "\n";
			return false;
		}
		return true;
	}

	bool test_make_instance()
	{	
		WordReader reader1;
		
		//with a dummy filename
		WordReader reader2("dummy string");
		
		return true;
	}

	bool test_load_file(string file)
	{
		WordReader reader;
		return test_load_file_helper(file,reader);
	}

	bool test_word_formatting(string file)
	{
		WordReader reader;
		
		if (!test_load_file_helper(file,reader))
		{
			return false;
		}
		
		//check to see if we got any words
		if (reader.get_words().empty())
		{
			cout << "Did not get any words from the file\n";
			return false;
		}
		
		//if any of the words we got include punctuation
		//or upper case letters or space fail the test
		unordered_map<string, int>::const_iterator it;
		for (it=reader.get_words().begin(); it != reader.get_words().end(); ++it)
		{
			if (it->first.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != string::npos)
			{
				cout << "Illegal character found\n";
				return false;
			}
		}
		return true;
	}
	
	
	bool test_word_count(string file)
	{
		WordReader reader;
		
		if (!test_load_file_helper(file,reader))
		{
			return false;
		}
		
		uint64_t check_count = 0;
		
		unordered_map<string, int>::const_iterator it;		
		for (it=reader.get_words().begin(); it != reader.get_words().end(); ++it)
		{
			check_count += it->second;
		}
		
		return (check_count == reader.get_total_count());
	}
	
	
	bool test_sort_by_count(string file)
	{
		WordReader reader;
		
		if (!test_load_file_helper(file,reader))
		{
			return false;
		}
		
		vector<pair<string, int> > most_common = reader.get_most_common();
		
		if (most_common.size() < 10 && reader.get_words().size() > 10)
		{
			cout << "not enough common words\n";
			return false;
		}
		
		//lets see if the results are in descending order
		vector<pair<string,int> >::const_iterator it;
		it = most_common.begin();
		int current = it->second;
		
		for (it=most_common.begin(); it != most_common.end(); ++it)
		{
			if (it->second > current)
			{
				cout << "order incorrect\n";
				return false;
			}
			current = it->second;
		} 
		return true;
	}
}
