#ifndef TRUCK_H
#define TRUCK_H
#include <vehicle.hpp>

namespace vehicle_eric
{
	class Truck : public Vehicle
	{
	public:
		Truck();
		Truck(std::string the_manufacturer, int num_cylinders, Person the_owner,
			double the_capacity, int the_towing_capacity);
		Truck(const Truck& copy);
		Truck& operator =(const Truck& right);
		
		double get_load_capacity();
		void set_load_capacity(double new_capacity);
		
		int get_towing_capacity();
		void set_towing_capacity(int new_capacity);
		
	private:
		double load_capacity;
		int towing_capacity;
	};
}

#endif //TRUCK_H
