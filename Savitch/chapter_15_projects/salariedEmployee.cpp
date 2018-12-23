#include <salariedEmployee.hpp>
#include <iostream>
using namespace std;

namespace employee_eric
{
	SalariedEmployee::SalariedEmployee() : PermanentEmployee(), salary(0)
	{
		//empty
	}
	
	SalariedEmployee::SalariedEmployee(string the_name, string the_number,
		double the_weekly_salary)
		: PermanentEmployee(the_name, the_number), salary(the_weekly_salary)
	{
		//empty
	}

	SalariedEmployee::SalariedEmployee(std::string the_name, std::string the_ssn,
		std::string benefits, int severance, double the_weekly_salary)
		: PermanentEmployee(the_name, the_ssn, benefits, severance), salary(the_weekly_salary)
	{
		//empty
	}
	
	SalariedEmployee::SalariedEmployee(const SalariedEmployee& copy)
		: PermanentEmployee(copy), salary(copy.salary)
	{
		//empty
	}
	
	SalariedEmployee::~SalariedEmployee()
	{
		//empty
	}
	
	double SalariedEmployee::get_salary() const
	{
		return salary;
	}
	
	void SalariedEmployee::set_salary(double new_salary)
	{
		salary = new_salary;
	}
	
	void SalariedEmployee::print_check()
	{
		set_net_pay(salary);
		cout << "\n----------------------------------------------------\n";
		cout << "Pay to the order of " << get_name() << endl;
		cout << "The sum of " << get_net_pay() << " Dollars\n";
		cout << "----------------------------------------------------\n";
		cout << "Check Stub NOT NEGOTIABLE\n";
		cout << "Employee number: " << get_ssn() << endl;
		cout << "Salaried Employee. Regular Pay: "
			<< salary << endl;
		cout << "----------------------------------------------------\n";
	}
} //employee_eric
