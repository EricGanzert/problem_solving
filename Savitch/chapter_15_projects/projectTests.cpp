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
	
	Employee* hourly;
	Employee* salaried;
	Employee* admin;
	
	hourly = new HourlyEmployee("hourly drone", "457322", "Jan 31, 2019", 15.00, 40);
	salaried = new SalariedEmployee("middle manager", "673346", "full benefits", 2000, 1500);
	admin = new Administrator("admin", "874344", 2000, "director", "nothing important", "the other boss");
	
	hourly->print_check();
	salaried->print_check();
	admin->print_check();
	
	Employee* another_hourly = new HourlyEmployee(*dynamic_cast<HourlyEmployee*>(hourly));
	Employee* another_salaried = new SalariedEmployee(*dynamic_cast<SalariedEmployee*>(salaried));
	Employee* another_admin = new Administrator(*dynamic_cast<Administrator*>(admin)); 

	another_hourly->print_check();
	another_salaried->print_check();
	another_admin->print_check();
}


void vehicle_test()
{
	using namespace vehicle_eric;
	
	Truck truck;
	Person owner("Eric");
	
	truck.set_manufacturer("Ford");
	truck.set_cylinders(8);
	truck.set_owner(owner);
	truck.set_load_capacity(5000);
	truck.set_towing_capacity(10000);
	cout << truck.get_manufacturer() << endl;
	cout << truck.get_cylinders() << endl;
	cout << truck.get_owner() << endl;
	cout << truck.get_load_capacity() << endl;
	cout << truck.get_towing_capacity() << endl << endl;
		
	Truck another_truck(truck);
	cout << another_truck.get_manufacturer() << endl;
	cout << another_truck.get_cylinders() << endl;
	cout << another_truck.get_owner() << endl;
	cout << another_truck.get_load_capacity() << endl;
	cout << another_truck.get_towing_capacity() << endl << endl;
	
	Truck a_third_truck = another_truck;
	cout << a_third_truck.get_manufacturer() << endl;
	cout << a_third_truck.get_cylinders() << endl;
	cout << a_third_truck.get_owner() << endl;
	cout << a_third_truck.get_load_capacity() << endl;
	cout << a_third_truck.get_towing_capacity() << endl << endl;
}

namespace
{
	using namespace vehicle_eric;
	
	void output_car(Car the_car)
	{
		cout << "owner: " << the_car.get_owner() << "\n";
		cout << "manufacturer: " << the_car.get_manufacturer() << "\n";
		cout << "cylinders: " << the_car.get_cylinders() << "\n";
		cout << "kilos per liter: " << the_car.get_kilos_per_liter() << "\n\n";
	}
	
	void output_car(SportsCar the_car)
	{
		cout << "owner: " << the_car.get_owner() << "\n";
		cout << "manufacturer: " << the_car.get_manufacturer() << "\n";
		cout << "cylinders: " << the_car.get_cylinders() << "\n";
		cout << "kilos per liter: " << the_car.get_kilos_per_liter() << "\n";
		cout << "top speed: " << the_car.get_top_speed() << "\n";
		cout << "supercharged: " << the_car.get_supercharged() << "\n\n";
	}
}

void car_test()
{
	using namespace vehicle_eric;
	Person eric("Eric");
	Person jesus("Jesus");
	Person dad("Dad");
	Person batman("Batman");
	
	Car erics_car("Honda", 4, eric, 5, 9);
	Car jesus_jeep("Jeep", 6, jesus, 2.5, 8);
	
	Car eric_copy(erics_car);
	Car jesus_copy = jesus_jeep;
	
	SportsCar fast_car("BMW", 6, dad, 3, 7, 200, false);
	SportsCar fast_car_copy(fast_car);
	
	SportsCar faster_car("Lamborghini", 8, batman, 2, 6, 270, true);
	SportsCar faster_car_copy = faster_car;
	
	output_car(erics_car);
	output_car(jesus_jeep);
	output_car(eric_copy);
	output_car(jesus_copy);
	output_car(fast_car);
	output_car(faster_car);
	output_car(fast_car_copy);
	output_car(faster_car_copy);
}

void patient_billing_test()
{
	using namespace employee_eric;
	
	Doctor regular("Regular", "023402", "all benefits", 3000, 2000, "general", 300);
	Patient patient("sick guy", regular);
	Doctor other("new doc", "953873", "all benefits", 2900, 1900, "surgery", 310);
	Patient hurt_guy("hurt guy", other);
	
	Billing a(patient, regular);
	Billing b(patient, other);
	Billing c(hurt_guy, regular);
	Billing d(hurt_guy, other);
	
	Billing a_copy(a);
	Billing c_copy = c;
	
	a.print_bill(cout);
	b.print_bill(cout);
	c.print_bill(cout);
	d.print_bill(cout);
	a_copy.print_bill(cout);
	c_copy.print_bill(cout);
	
	
	
	
}

