#include <wordFrequency.h>
using namespace std;

namespace wcount_eric
{
	WordReader::WordReader()
		: filepath("no filepath yet")
	{
		//empty
	}
	
	WordReader::WordReader(const char* the_filepath)
		: filepath(the_filepath)
	{
		//empty
	}
}
