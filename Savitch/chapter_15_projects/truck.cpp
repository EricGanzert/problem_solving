#include <truck.hpp>

namespace vehicle_eric
{
	Truck::Truck() : Vehicle(), load_capacity(0), towing_capacity(0)
	{
		//empty
	}
	
	Truck::Truck(std::string the_manufacturer, int num_cylinders, Person the_owner,
		double the_capacity, int the_towing_capacity)
		: Vehicle(the_manufacturer, num_cylinders, the_owner), load_capacity(the_capacity),
		towing_capacity(the_towing_capacity)
	{
		//empty
	} 
	
	Truck::Truck(const Truck& copy)
		: Vehicle(copy), load_capacity(copy.load_capacity), towing_capacity(copy.towing_capacity)
	{
		//empty
	}
	
	Truck& Truck::operator =(const Truck& right)
	{
		Vehicle::operator =(right);
		load_capacity = right.load_capacity;
		towing_capacity = right.towing_capacity;
		return *this;
	}
		
	double Truck::get_load_capacity()
	{
		return load_capacity;
	}
	
	void Truck::set_load_capacity(double new_capacity)
	{
		load_capacity = new_capacity;
	}
		
	int Truck::get_towing_capacity()
	{
		return towing_capacity;
	}
	
	void Truck::set_towing_capacity(int new_capacity)
	{
		towing_capacity = new_capacity;
	}
}
