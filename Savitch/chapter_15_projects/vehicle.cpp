#include <vehicle.hpp>
using namespace std;

namespace vehicle_eric
{
	Vehicle::Vehicle() : manufacturer("no manufacturer yet"), cylinders(0)
	{
		//empty
	}

	Vehicle::Vehicle(std::string the_manufacturer, int num_cylinders, Person the_owner)
		: manufacturer(the_manufacturer), cylinders(num_cylinders), owner(the_owner)
	{
		//empty
	}

	Vehicle::Vehicle(const Vehicle& copy) : manufacturer(copy.manufacturer),
		cylinders(copy.cylinders), owner(copy.owner)
	{
		//empty
	}

	Vehicle& Vehicle::operator =(const Vehicle& object)
	{
		manufacturer = object.manufacturer;
		cylinders = object.cylinders;
		owner = object.owner;
		return *this;
	}
	
	string Vehicle::get_manufacturer() const
	{
		return manufacturer;
	}
	
	void Vehicle::set_manufacturer(string new_manufacturer)
	{
		manufacturer = new_manufacturer;
	}
	
	int Vehicle::get_cylinders() const
	{
		return cylinders;
	}
	
	void Vehicle::set_cylinders(int new_cylinders)
	{
		cylinders = new_cylinders;
	}
	
	Person Vehicle::get_owner() const
	{
		return owner;
	}
	
	void Vehicle::set_owner(Person new_owner)
	{
		owner = new_owner;
	}
} 
