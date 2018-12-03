#include <projectTests.hpp>
using namespace std;
//~ using d_time_eric::DigitalTime;
//~ using d_time2_eric::DigitalTime;

void digital_time_test()
{
	d_time_eric::DigitalTime current(2, 30), past(3, 35);
	int hours, minutes;
	current.interval_since(past, hours, minutes);
	cout << "the time from " << past
		<< " to " << current << "\nis " << hours << " hours and " 
		<< minutes << " minutes.\n";
}

void digital_time2_test()
{
	d_time2_eric::DigitalTime current(2, 30), past(3, 35);
	int hours, minutes;
	current.interval_since(past, hours, minutes);
	cout << "the time from " << past
		<< " to " << current << "\nis " << hours << " hours and " 
		<< minutes << " minutes.\n";
}
