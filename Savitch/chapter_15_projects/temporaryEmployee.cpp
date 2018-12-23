#include <temporaryEmployee.hpp>
#include <iostream>
using namespace std;

namespace employee_eric
{
	TemporaryEmployee::TemporaryEmployee()
		: Employee(), contract_expiry_date("no expiry date yet")
	{
		//empty
	}

	TemporaryEmployee::TemporaryEmployee(string the_name, string the_ssn)
		: Employee(the_name, the_ssn), contract_expiry_date("no expiry date yet")
	{
		//empty
	}
	
	TemporaryEmployee::TemporaryEmployee(string the_name, string the_ssn, string the_expiry_date)
		: Employee(the_name, the_ssn), contract_expiry_date(the_expiry_date)
	{
		//empty
	}
	
	TemporaryEmployee::TemporaryEmployee(const TemporaryEmployee& copy)
		: Employee(copy.name, copy.ssn), contract_expiry_date(copy.contract_expiry_date)
	{
		//empty
	}
	
	TemporaryEmployee::~TemporaryEmployee()
	{
		//empty
	}
	
	void TemporaryEmployee::set_expiry_date(string new_expiry_date)
	{
		contract_expiry_date = new_expiry_date;
	}
	
	string TemporaryEmployee::get_expiry_date() const
	{
		return contract_expiry_date;
	}
	
	void TemporaryEmployee::input_temporary_employee_info()
	{
		cout << "Enter contract expiry date: ";
		cin >> contract_expiry_date;
	}
	
	void TemporaryEmployee::print_check() const
	{
		std::cout << "Error: undifferentiated temporary employee print_check()\n";
		exit(1); 
	}
}
