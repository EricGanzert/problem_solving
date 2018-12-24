#ifndef SPORTS_CAR_H
#define SPORTS_CAR_H
#include <string>
#include <car.hpp>

namespace vehicle_eric
{
	class SportsCar : public Car
	{
	public:
		SportsCar();
		SportsCar(std::string the_manufacturer, int the_cylinders, Person the_owner,
			double the_kilos_per_liter, int the_safety_rating, double the_top_speed, bool supercharged);
		SportsCar(const SportsCar& copy);
		SportsCar& operator =(const SportsCar& object);
		
		void set_top_speed(double new_top_speed);
		double get_top_speed();
		
		void set_supercharged(bool new_supercharged);
		bool get_supercharged();
	private:
		double top_speed;
		bool supercharged;
	};
}

#endif //SPORTS_CAR_H
