#include <sportsCar.hpp>
using namespace std;

namespace vehicle_eric
{
	SportsCar::SportsCar() : Car(), top_speed(0), supercharged(false)
	{
		//empty
	}
	
	SportsCar::SportsCar(string the_manufacturer, int the_cylinders, Person the_owner,
		double the_kilos_per_liter, int the_safety_rating, double the_top_speed, bool is_supercharged)
		: Car(the_manufacturer, the_cylinders, the_owner, the_kilos_per_liter, the_safety_rating),
		top_speed(the_top_speed), supercharged(is_supercharged)
	{
		//empty
	}
	
	SportsCar::SportsCar(const SportsCar& copy)
		: Car(copy), top_speed(copy.top_speed), supercharged(copy.supercharged)
	{
		//empty
	}
	
	SportsCar& SportsCar::operator =(const SportsCar& object)
	{
		Car::operator =(object);
		top_speed = object.top_speed;
		supercharged = object.supercharged;
		return *this;
	}
	
	void SportsCar::set_top_speed(double new_top_speed)
	{
		top_speed = new_top_speed;
	}
	
	double SportsCar::get_top_speed()
	{
		return top_speed;
	}
	
	void SportsCar::set_supercharged(bool new_supercharged)
	{
		supercharged = new_supercharged;
	}
	
	bool SportsCar::get_supercharged()
	{
		return supercharged;
	}
}
