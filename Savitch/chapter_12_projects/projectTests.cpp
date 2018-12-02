#include <projectTests.hpp>
using namespace std;
using d_time_eric::DigitalTime;


void digital_time_test()
{
	DigitalTime current(2, 30), past(5, 45);
	int hours, minutes;
	current.interval_since(past, hours, minutes);
	cout << "the time in between " << past
		<< " and " << current << "\nis " << hours << " hours and " 
		<< minutes << " minutes.\n";
}

