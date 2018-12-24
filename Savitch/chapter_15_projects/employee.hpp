#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

namespace employee_eric
{
	class Employee
	{
	public:
		Employee();
		Employee(std::string the_name, std::string the_ssn);
		Employee(const Employee& copy);
		virtual ~Employee();
		
		friend bool operator ==(const Employee& left, const Employee& right);
		
		Employee& operator =(const Employee& right);
		std::string get_name() const;
		std::string get_ssn() const;
		double get_net_pay() const; 
		void set_name(std::string new_name);
		void set_ssn(std::string new_ssn);
		void set_net_pay(double new_net_pay);
		
		virtual void print_check();
	protected:
		std::string name;
		std::string ssn;
		double net_pay;
	};
} //employee_eric

#endif //EMPLOYEE_H
