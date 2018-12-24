#ifndef DOCTOR_H
#define DOCTOR_H
#include <salariedEmployee.hpp>
#include <string>

namespace employee_eric
{
	class Doctor : public SalariedEmployee
	{
	public:
		Doctor();
		Doctor(std::string the_name, std::string the_ssn, std::string benefits,
			int severance, double the_weekly_salary, std::string the_specialty, double the_visit_fee);
		virtual ~Doctor();
		Doctor(const Doctor& copy);
		Doctor& operator =(const Doctor& right);
		
		virtual void print_check();
		void set_specialty(std::string new_specialty);
		void set_visit_fee(double new_visit_fee);
		std::string get_specialty();
		double get_visit_fee();
	
	protected:
		std::string specialty;
		double office_visit_fee;
	};
}

#endif //DOCTOR_H
