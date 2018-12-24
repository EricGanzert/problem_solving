#include <administrator.hpp>
#include <iostream>
using namespace std;

namespace employee_eric
{
	Administrator::Administrator()
		: SalariedEmployee(), title("no title yet"),
		area_of_responsibility("no area yet"), supervisor("no supervisor yet")
	{
		//empty
	}
	
	Administrator::Administrator(string the_name, string the_ssn, double the_weekly_salary,
		string the_title, string the_area, string the_supervisor)
		: SalariedEmployee(the_name, the_ssn, the_weekly_salary), title(the_title), area_of_responsibility(the_area), supervisor(the_supervisor)
	{
		//empty
	}
	
	Administrator::Administrator(const Administrator& copy)
		: SalariedEmployee(copy), title(copy.title), area_of_responsibility(copy.area_of_responsibility), supervisor(copy.supervisor)
	{
		//empty
	}
	
	Administrator::~Administrator()
	{
		//empty
	}
	
	Administrator& Administrator::operator =(const Administrator& right)
	{
		SalariedEmployee::operator =(right);
		title = right.title;
		area_of_responsibility = right.area_of_responsibility;
		supervisor = right.supervisor;
		return *this;
	}
	
	void Administrator::set_supervisor(string new_supervisor)
	{
		supervisor = new_supervisor;
	}
	
	string Administrator::get_supervisor() const
	{
		return supervisor;
	}
	
	void Administrator::input_info()
	{
		cout << "Enter title: ";
		cin >> title;
		cout << "Enter area of responsibility: ";
		cin >> area_of_responsibility;
		cout << "Enter supervisor: ";
		cin >> supervisor;
	}
	
	void Administrator::print_check()
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
		cout << "Title: " << title << "\nArea of responsibility: " << area_of_responsibility
			<< "\nSupervisor: " << supervisor << "\n";
		cout << "----------------------------------------------------\n";
	}
	
	void Administrator::print()
	{
		cout << "Title: " << title << "\nArea of responsibility: " << area_of_responsibility
			<< "\nSupervisor: " << supervisor << "\n";
	}
}
