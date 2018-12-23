#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H

#include <string>
#include <temporaryEmployee.hpp>
namespace employee_eric
{
	class HourlyEmployee : public TemporaryEmployee
	{
	public:
		HourlyEmployee();
		HourlyEmployee(std::string the_name, std::string the_ssn,
			double the_wage_rate, double the_hours);
		HourlyEmployee(std::string the_name, std::string the_ssn,
			std::string expiry_date, double the_wage_rate, double the_hours);
		HourlyEmployee(const HourlyEmployee& copy);
		virtual ~HourlyEmployee();
		
		void set_rate(double new_wage_rate);
		double get_rate() const;
		void set_hours(double hours_worked);
		double get_hours() const;
		void print_check();
		
	private:
		double wage_rate;
		double hours;
	};
} //employee_eric

#endif //HOURLY_EMPLOYEE_H
