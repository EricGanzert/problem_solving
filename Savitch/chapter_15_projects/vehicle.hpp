#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <person.hpp>

namespace vehicle_eric
{
	class Vehicle
	{
	public:
		Vehicle();
		Vehicle(std::string the_manufacturer, int num_cylinders, Person the_owner);
		Vehicle(const Vehicle& copy);
		Vehicle& operator =(const Vehicle& object);
		
		std::string get_manufacturer() const;
		void set_manufacturer(std::string new_manufacturer);
		int get_cylinders() const;
		void set_cylinders(int new_cylinders);
		Person get_owner() const;
		void set_owner(Person new_owner);
		
	private:
		std::string manufacturer;
		int cylinders;
		Person owner;
	};
}

#endif //VEHICLE_H
