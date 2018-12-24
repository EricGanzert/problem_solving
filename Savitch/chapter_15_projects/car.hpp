#ifndef CAR_H
#define CAR_H
#include <vehicle.hpp>
#include <string>

namespace vehicle_eric
{
	class Car : public Vehicle
	{
	public:
		Car();
		Car(std::string the_manufacturer, int the_cylinders, Person the_owner,
			double the_kilos_per_liter, int the_safety_rating);
		Car(const Car& copy);
		Car& operator =(const Car& right);
		
		void set_kilos_per_liter(double new_kilos);
		double get_kilos_per_liter();
		
		void set_safety_rating(int new_safety_rating);
		int get_safety_rating();
		
	private:
		double kilos_per_liter;
		int safety_rating;
	};
}

#endif //CAR_H
