#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H

#include <iostream>
#include <fstream>
#include <math.h>

class Complex {
public:
	Complex();
	Complex(double real_part, double imaginary_part);
	Complex(double real_part);
	
	 friend bool operator ==(const Complex& first, const Complex& second);
	
	friend Complex operator +(const Complex& first, const Complex& second);
	friend Complex operator -(const Complex& first, const Complex& second);
	friend Complex operator *(const Complex& first, const Complex& second);
	
	friend std::ostream& operator <<(std::ostream& outs, const Complex& second);
	friend std::istream& operator >>(std::istream& ins, Complex& second);
	
private:
	double real;
	double imaginary;
};

#endif //COMPLEX_NUMBERS_H
