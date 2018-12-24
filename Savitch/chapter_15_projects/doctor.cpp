#include <doctor.hpp>

namespace employee_eric
{
	Doctor::Doctor() : SalariedEmployee(), specialty("no specialty yet"), office_visit_fee(0)
	{
		//empty
	}
	
	Doctor::Doctor(std::string the_name, std::string the_ssn, std::string benefits,
		int severance, double the_weekly_salary, std::string the_specialty, double the_visit_fee)
		: SalariedEmployee(the_name, the_ssn, benefits, severance, the_weekly_salary),
		specialty(the_specialty), office_visit_fee(the_visit_fee)
	{
		//empty
	}
	
	Doctor::Doctor(const Doctor& copy)
		: SalariedEmployee(copy), specialty(copy.specialty), office_visit_fee(copy.office_visit_fee)
	{
		//empty
	}
	
	Doctor& Doctor::operator =(const Doctor& right)
	{
		SalariedEmployee::operator =(right);
		specialty = right.specialty;
		office_visit_fee = right.office_visit_fee;
		return *this;
	}
	
	void Doctor::print_check()
	{
		SalariedEmployee::print_check();
	}
	
	Doctor::~Doctor()
	{
		//empty
	}
	
	void Doctor::set_specialty(std::string new_specialty)
	{
		specialty = new_specialty;
	}
	
	void Doctor::set_visit_fee(double new_visit_fee)
	{
		office_visit_fee = new_visit_fee;
	}
	
	std::string Doctor::get_specialty()
	{
		return specialty;
	}
	
	double Doctor::get_visit_fee()
	{
		return office_visit_fee;
	}
}
 
