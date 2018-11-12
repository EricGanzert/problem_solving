#ifndef MONEY_H
#define MONEY_H 

#include <iostream>
#include <fstream>
#include <cctype>

typedef enum {
	ERROR_MONEY_INPUT
}money_error_t; 

//Class for amounts of money in U.S. currency
class Money
{
public:
	friend Money operator +(const Money& amount1, const Money& amount2);
	
	friend Money operator -(const Money& amount1, const Money& amount2);
	
	friend Money operator -(const Money& amount);
	
	friend bool operator ==(const Money& amount1, const Money& amount2);
	
	friend bool operator <(const Money& amount1, const Money& amount2);
	
	friend bool operator <=(const Money& amount1, const Money& amount2);
	
	friend bool operator >(const Money& amount1, const Money& amount2);
	
	friend bool operator >=(const Money& amount1, const Money& amount2);
	
	Money(long dollars, int cents);
	
	Money(long dollars);
	
	Money();
	
	double get_value() const;
	
	Money percent(int percent_figure);
	
	friend std::istream& operator >>(std::istream& ins, Money& amount);
	//overloads the >> operator so it can be used to input values of type Money.
	//Notation for inputting negative amounts is as in -$100.00
	//Precondition: If ins is a file input stream, then ins has already been connected to a file
	
	friend std::ostream& operator <<(std::ostream& outs, const Money& amount);
	//Overloads the << operator so it can be used to output values of type Money
	//Precedes each output value with a dollar sign
	//Precondition: If outs is a file output stream, then outs is already connected to a file
	
private:
	long all_cents;
};

//~ int digit_to_int(char c);

#endif //MONEY_H

