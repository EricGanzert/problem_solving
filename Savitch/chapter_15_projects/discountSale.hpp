#ifndef DISCOUNT_SALE_H
#define DISCOUNT_SALE_H

#include <sale.hpp>

namespace sale_eric
{
	class DiscountSale : public Sale
	{
	public:
		DiscountSale();
		DiscountSale(double the_price, double the_discount);
		//Discount is expressed as a percent of the price
		virtual double bill() const;
	protected:
		double discount;
	};
} //sale_eric

#endif //DISCOUNT_SALE_H
