#include <projectTests.hpp>
#include <iostream>
using namespace std;

void time_convert_test()
{
	using namespace time_convert_eric;
	
	convert();
}

void date_convert_test()
{
	using namespace date_convert_eric;
	
	convert();
}

void numeric_hist_test()
{
	using namespace numeric_value_eric;
	
	NumericValues v;
	v.input();
	v.output_hist();
}
