#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <salariedEmployee.hpp>

namespace employee_eric
{
	class Administrator : public SalariedEmployee
	{
	public:
		Administrator();
		Administrator(std::string the_name, std::string the_ssn, double the_weekly_salary,
			std::string the_title, std::string the_area, std::string the_supervisor);
		Administrator(const Administrator& copy);
		~Administrator();
		
		void operator =(const Administrator& right);
		void set_supervisor(std::string new_supervisor);
		std::string get_supervisor() const;
		void input_info();
		void print();
		virtual void print_check();
	private:
		std::string title;
		std::string area_of_responsibility;
		std::string supervisor;
	};
}
#endif //ADMIN_H
