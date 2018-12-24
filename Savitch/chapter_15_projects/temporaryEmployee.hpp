#ifndef TEMPORARY_EMPLOYEE_H
#define TEMPORARY_EMPLOYEE_H
#include <string>
#include <employee.hpp>

namespace employee_eric
{
	class TemporaryEmployee : public Employee
	{
	public:
		TemporaryEmployee();
		TemporaryEmployee(std::string the_name, std::string the_ssn);
		TemporaryEmployee(std::string the_name, std::string the_ssn, std::string the_expiry_date);
		TemporaryEmployee(const TemporaryEmployee& copy);
		virtual ~TemporaryEmployee();
		
		TemporaryEmployee& operator =(const TemporaryEmployee& right);
		
		void set_expiry_date(std::string new_expiry_date);
		std::string get_expiry_date() const;
		void input_temporary_employee_info();
		
		virtual void print_check();
		
	protected:
		std::string contract_expiry_date;
	};
}

#endif //TEMPORARY_EMPLOYEE_H
