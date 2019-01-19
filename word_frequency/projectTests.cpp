#include <projectTests.h>
using namespace std;

void all_tests(int argc, char** argv)
{
	if (!test_make_instance())
	{
		cout << "Could not make class instance\n";
	}
	
	cout << "Tests finished\n";
}

bool test_make_instance()
{
	using namespace wcount_eric;
	
	WordReader reader1;
	
	//with a dummy filename
	WordReader reader2("../test.txt");
	
	cout << "Make instance success\n";
	return true;
}
