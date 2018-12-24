#include <hourlyEmployee.hpp>
#include <iostream>
using namespace std;

namespace employee_eric
{
	HourlyEmployee::HourlyEmployee() : TemporaryEmployee(), wage_rate(0), hours(0)
	{
		//empty
	}
	
	HourlyEmployee::HourlyEmployee(string the_name, string the_number,
		double the_wage_rate, double the_hours)
		: TemporaryEmployee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
	{
		//empty
	}

	HourlyEmployee::HourlyEmployee(string the_name, string the_ssn,
		string expiry_date, double the_wage_rate, double the_hours)
		: TemporaryEmployee(the_name, the_ssn, expiry_date), wage_rate(the_wage_rate), hours(the_hours)
	{
		//empty
	}
	
	HourlyEmployee::HourlyEmployee(const HourlyEmployee& copy)
		: TemporaryEmployee(copy), wage_rate(copy.wage_rate), hours(copy.hours)
	{
		//empty
	}

	HourlyEmployee::~HourlyEmployee()
	{
		//empty
	}
	
	HourlyEmployee& HourlyEmployee::operator =(const HourlyEmployee& right)
	{
		TemporaryEmployee::operator =(right);
		wage_rate = right.wage_rate;
		hours = right.hours;
		return *this;
	}
	
	void HourlyEmployee::set_rate(double new_wage_rate)
	{
		wage_rate = new_wage_rate;
	}
	
	double HourlyEmployee::get_rate() const
	{
		return wage_rate;
	}
	
	void HourlyEmployee::set_hours(double hours_worked)
	{
		hours = hours_worked;
	}
	
	double HourlyEmployee::get_hours() const
	{
		return hours;
	}
	
	void HourlyEmployee::print_check()
	{
		set_net_pay(hours * wage_rate);
		
		cout << "\n----------------------------------------------------\n";
		cout << "Pay to the order of " << get_name() << endl;
		cout << "The sum of " << get_net_pay() << " Dollars\n";
		cout << "----------------------------------------------------\n";
		cout << "Check Stub: NOT NEGOTIABLE\n";
		cout << "Employee Number: " << get_ssn() << endl;
		cout << "Hourly Employee. \nHours worked: " << hours
			<< ", Rate: " << wage_rate << ", Pay: " << get_net_pay() << endl;			
		cout << "----------------------------------------------------\n";
	}
}
