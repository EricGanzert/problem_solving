#ifndef SALE_H
#define SALE_H

#include <iostream>
using namespace std;

namespace sale_eric
{
	class Sale
	{
	public:
		Sale();
		Sale(double the_price);
		virtual double bill() const;
		double savings(const Sale& other) const;
		//returns the savings if you buy the other instead of the calling object
	protected:
		double price;
	};
	
	bool operator <(const Sale& first, const Sale& second);
	//Compares two sales to see which is larger
} //sale_eric

#endif //SALE_H
