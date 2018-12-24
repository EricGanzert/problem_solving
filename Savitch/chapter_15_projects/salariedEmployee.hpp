#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include <string>
#include <permanentEmployee.hpp>
namespace employee_eric
{
	class SalariedEmployee : public PermanentEmployee
	{
	public:
		SalariedEmployee();
		SalariedEmployee(std::string the_name, std::string the_ssn,
			double the_weekly_salary);
		SalariedEmployee(std::string the_name, std::string the_ssn,
			std::string benefits, int severance, double the_weekly_salary);
		SalariedEmployee(const SalariedEmployee& copy);
		virtual ~SalariedEmployee();
		
		SalariedEmployee& operator =(const SalariedEmployee& right);
		
		double get_salary() const;
		void set_salary(double new_salary);
		virtual void print_check();
		
	protected:
		double salary; //weekly
	};
} //employee_eric

#endif //SALARIED_EMPLOYEE_H
