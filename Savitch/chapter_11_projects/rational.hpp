#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <fstream>
#include <math.h>

class Rational
{
public:
	Rational(int numerator, int denominator);
	Rational(int whole_number);
	Rational();
	
	void normalize();
	
	friend std::ostream& operator <<(std::ostream& outs, const Rational& second);
	friend std::istream& operator >>(std::istream& ins, Rational& second);
	
	friend bool operator ==(const Rational& first, const Rational& second);
	friend bool operator <(const Rational& first, const Rational& second);
	friend bool operator <=(const Rational& first, const Rational& second);
	friend bool operator >(const Rational& first, const Rational& second);
	friend bool operator >=(const Rational& first, const Rational& second);
	
	friend Rational operator +(const Rational& first, const Rational& second);
	friend Rational operator -(const Rational& first, const Rational& second);
	friend Rational operator *(const Rational& first, const Rational& second);
	friend Rational operator /(const Rational& first, const Rational& second);
private:
	int num;
	int denom;
};

#endif //RATIONAL_H
