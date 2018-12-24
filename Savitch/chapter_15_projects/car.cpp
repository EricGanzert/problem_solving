#include <car.hpp>
using namespace std;

namespace vehicle_eric
{
	Car::Car() : Vehicle(), kilos_per_liter(0), safety_rating(0)
	{
		//empty
	}
	
	Car::Car(string the_manufacturer, int the_cylinders, Person the_owner,
		double the_kilos_per_liter, int the_safety_rating)
		: Vehicle(the_manufacturer, the_cylinders, the_owner), kilos_per_liter(the_kilos_per_liter),
		safety_rating(the_safety_rating)
	{
		//empty
	}
	
	Car::Car(const Car& copy)
		: Vehicle(copy), kilos_per_liter(copy.kilos_per_liter), safety_rating(copy.safety_rating)
	{
		//empty
	}
	
	Car& Car::operator =(const Car& right)
	{
		Vehicle::operator =(right);
		kilos_per_liter = right.kilos_per_liter;
		safety_rating = right.safety_rating;
		
		return *this;
	}
	
	void Car::set_kilos_per_liter(double new_kilos)
	{
		kilos_per_liter = new_kilos;
	}
	
	double Car::get_kilos_per_liter()
	{
		return kilos_per_liter;
	}
	
	void Car::set_safety_rating(int new_safety_rating)
	{
		safety_rating = new_safety_rating;
	}
	
	int Car::get_safety_rating()
	{
		return safety_rating;
	}
}
