#include <projectTests.hpp>
#include <iostream>
using std::cout;
using std::endl;
using namespace std;

void employee_test()
{
	using namespace employee_eric;
	
	HourlyEmployee joe;
	joe.set_name("Mighty Joe");
	joe.set_ssn("123-45-6789");
	joe.set_rate(20.50);
	joe.set_hours(40);
	
	cout << "Check for " << joe.get_name()
		<< " for " << joe.get_hours() << " hours.\n";
	joe.print_check();
	cout << endl;
	
	SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500.50);
	cout << "Check for " << boss.get_name() << endl;
	boss.print_check();
}

void sale_test()
{
	using namespace sale_eric;
	
	Sale simple(10.00);
	DiscountSale discount(11.00, 10);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	if (discount < simple)
	{
		cout << "Discounted item is cheaper.\n";
		cout << "Savings is $" << simple.savings(discount) << endl;
	}
	else
		cout << "Discounted item is not cheaper\n";
}

void admin_test()
{
	using namespace employee_eric;
	
	Administrator admin;
	admin.input_info();
	admin.print();
	admin.set_name("Eric");
	admin.set_ssn("000001");
	admin.set_salary(10000);
	admin.print_check();
}

void new_employee_types_test()
{
	using namespace employee_eric;
	
	TemporaryEmployee temp("Eric", "43524", "oct 31");
}
