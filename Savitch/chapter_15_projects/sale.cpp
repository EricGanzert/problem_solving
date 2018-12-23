#include <sale.hpp>

namespace sale_eric
{
	Sale::Sale() : price(0)
	{
		//empty
	}
	
	Sale::Sale(double the_price) : price(the_price)
	{
		//empty
	}
	
	double Sale::bill() const
	{
		return price;
	}
	
	double Sale::savings(const Sale& other) const
	{
		return bill() - other.bill();
	}
	
	bool operator <(const Sale& first, const Sale& second)
	{
		return first.bill() < second.bill();
	}
} //sale_eric

