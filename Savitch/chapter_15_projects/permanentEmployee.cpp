#include <permanentEmployee.hpp>
#include <iostream>
using namespace std;

namespace employee_eric
{
	PermanentEmployee::PermanentEmployee()
		: Employee(), health_benefits_id("no health benefits yet"), severance(0)
	{
		//empty
	}
		
	PermanentEmployee::PermanentEmployee(std::string the_name, std::string the_ssn)
		: Employee(the_name, the_ssn), health_benefits_id("no health benefits yet"), severance(0)
	{
		//empty
	}
	
	PermanentEmployee::PermanentEmployee(std::string the_name, std::string the_ssn, std::string the_benefits, int the_severance)
		: Employee(the_name, the_ssn), health_benefits_id(the_benefits), severance(the_severance)
	{
		//empty
	}
	
	PermanentEmployee::PermanentEmployee(const PermanentEmployee& copy)
		: Employee(copy), health_benefits_id(copy.health_benefits_id), severance(copy.severance)
	{
		
	}
	
	PermanentEmployee::~PermanentEmployee()
	{
		//empty
	}
	
	void PermanentEmployee::set_health_benefits(std::string new_benefits)
	{
		health_benefits_id = new_benefits;
	}
	
	string PermanentEmployee::get_health_benefits() const
	{
		return health_benefits_id;
	}
	
	void PermanentEmployee::input_permanent_employee_info()
	{
		cout << "Enter health benefits: ";
		cin >> health_benefits_id;
		cout << "Enter severance amount: ";
		cin >> severance; 
	}
	
	void PermanentEmployee::set_severance(int new_severance)
	{
		severance = new_severance;
	}
	
	int PermanentEmployee::get_severance() const
	{
		return severance;
	}
	
	void PermanentEmployee::print_check() const
	{
		std::cout << "Error: undifferentiated permanent employee print_check()\n";
		exit(1); 		
	}
}
