#include <money.hpp>
using namespace std;

static int digit_to_int(char c)
{
	return ( static_cast<int>(c) - static_cast<int>('0') );
}

istream& operator >>(istream& ins, Money& amount)
{
	char one_char, decimal_point,
		digit1, digit2; //for amount of cents
	long dollars;
	int cents;
	bool negative;
	
	ins >> one_char;
	if (one_char == '-')
	{
		negative == true;
		ins >> one_char;
	}
	else
		negative = false;
	//if input is legal, then one_char is $
	
	ins >> dollars >> decimal_point >> digit1 >> digit2;
	
	if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
	{
		cout << "Error illegal form for money input\n";
		throw ERROR_MONEY_INPUT;
	}
	
	cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
	
	amount.all_cents = 100 * dollars + cents;
	if (negative)
		amount.all_cents = -amount.all_cents;
	ins.clear();
	ins.ignore(10000,'\n');
	return ins;
}

ostream& operator <<(ostream& outs, const Money& amount)
{
	long positive_cents, dollars, cents;
	positive_cents = labs(amount.all_cents);
	dollars = positive_cents/100;
	cents = positive_cents%100;
	
	if (amount.all_cents < 0)
		outs << "- $" << dollars << '.';
	else
		outs << "$" << dollars << '.';
	
	if (cents < 10)
		outs << '0';
	outs << cents;
	
	return outs;
}

Money operator +(const Money& amount1, const Money& amount2)
{
	long total_dollars = amount1.all_cents/100 + amount2.all_cents/100;
	int total_cents	= amount1.all_cents%100 + amount2.all_cents%100;
	
	return Money(total_dollars, total_cents);
}
	
Money operator -(const Money& amount1, const Money& amount2)
{
	long total_dollars = amount1.all_cents/100 - amount2.all_cents/100;
	int total_cents	= amount1.all_cents%100 - amount2.all_cents%100;
	
	return Money(total_dollars, total_cents);	
}
	
Money operator -(const Money& amount)
{
	long dollars = -amount.all_cents/100;
	int cents	= -amount.all_cents%100;
	
	return Money(dollars, cents);		
}

bool operator ==(const Money& amount1, const Money& amount2)
{
	if (amount1.all_cents == amount2.all_cents)
		return true;
	else
		return false;
}
	
bool operator <(const Money& amount1, const Money& amount2)
{
	if (amount1.all_cents < amount2.all_cents)
		return true;
	else
		return false;
}
	
bool operator <=(const Money& amount1, const Money& amount2)
{
	if (amount1.all_cents <= amount2.all_cents)
		return true;
	else
		return false;
}
	
bool operator >(const Money& amount1, const Money& amount2)
{
	if (amount1.all_cents > amount2.all_cents)
		return true;
	else
		return false;
}
	
bool operator >=(const Money& amount1, const Money& amount2)
{
	if (amount1.all_cents >= amount2.all_cents)
		return true;
	else
		return false;
}

Money::Money(long dollars, int cents)
{
	all_cents = dollars*100 + cents;
}

Money::Money(long dollars)
{
	all_cents = dollars*100;
}

Money::Money()
{
	all_cents = 0;
}

Money Money::percent(int percent_figure)
{
	double new_all_cents = (percent_figure/100.0)*this->all_cents;
	long new_dollars = static_cast<long>(new_all_cents)/100;
	int new_cents = static_cast<int>(new_all_cents)%100;
	
	return Money(new_dollars, new_cents);
}
