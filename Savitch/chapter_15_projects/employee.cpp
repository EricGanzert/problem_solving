#include <employee.hpp>
#include <iostream>
using namespace std;

namespace employee_eric
{
	Employee::Employee() : name("no name yet"), ssn("No number yet"), net_pay(0)
	{
		//empty
	}
	
	Employee::Employee(string the_name, string the_number)
		: name(the_name), ssn(the_number), net_pay(0)
	{
		//empty
	}
	
	Employee::Employee(const Employee& copy)
		: name(copy.name), ssn(copy.ssn), net_pay(copy.net_pay)
	{
		//empty
	}
	
	Employee::~Employee()
	{
		//empty
	}
	
	Employee& Employee::operator =(const Employee& right)
	{
		name = right.name;
		ssn = right.ssn;
		net_pay = right.net_pay;
		return *this;
	}
	
	bool operator ==(const Employee& left, const Employee& right)
	{
		return (left.name == right.name && left.ssn == right.ssn);
	}
	
	string Employee::get_name() const
	{
		return name;
	}
	
	string Employee::get_ssn() const
	{
		return ssn;
	}
	
	double Employee::get_net_pay() const
	{
		return net_pay;
	}
	
	void Employee::set_name(string new_name)
	{
		name = new_name;
	}
	
	void Employee::set_ssn(string new_ssn)
	{
		ssn = new_ssn;
	}
	
	void Employee::set_net_pay(double new_net_pay)
	{
		net_pay = new_net_pay;
	}
	
	void Employee::print_check()
	{
		cout << "Error: undifferentiated employee print_check()\n";
		exit(1); 
	}
}
