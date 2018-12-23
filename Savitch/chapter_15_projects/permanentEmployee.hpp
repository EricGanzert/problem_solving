#ifndef PERMANENT_EMPLOYEE_H
#define PERMANENT_EMPLOYEE_H
#include <string>
#include <employee.hpp>

namespace employee_eric
{
	class PermanentEmployee : public Employee
	{
	public:
		PermanentEmployee();
		PermanentEmployee(std::string the_name, std::string the_ssn);
		PermanentEmployee(std::string the_name, std::string the_ssn, std::string the_benefits, int the_severance);
		PermanentEmployee(const PermanentEmployee& copy);
		virtual ~PermanentEmployee();
		
		void set_health_benefits(std::string new_benefits);
		std::string get_health_benefits() const;
		
		void input_permanent_employee_info();
		
		void set_severance(int new_severance);
		int get_severance() const;
		
		virtual void print_check() const;
		
	protected:
		std::string health_benefits_id;
		int severance;
	};
}

#endif //PERMANENT_EMPLOYEE_H
