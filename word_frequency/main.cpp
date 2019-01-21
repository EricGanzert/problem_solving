#include <wordFrequency.h>
#include <projectTests.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{	
	if (argc > 1)
	{
		wcount_eric::WordReader reader(argv[1]);
		try
		{
			reader.load_file();
		}
		catch (wcount_eric::FileError e)
		{
			cout << e.get_message() << "\n";
			return 0;
		}
		reader.display_most_common();
	}
	else
	{
		cout << "Usage is ./wcount path_to_file\n";
	}
	return 0;
}
