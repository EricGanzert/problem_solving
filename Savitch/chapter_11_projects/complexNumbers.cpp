#include <complexNumbers.hpp>

const Complex i(0,1);

Complex::Complex(double real_part, double imaginary_part) : real(real_part), imaginary(imaginary_part)
{
}

Complex::Complex() : real(0), imaginary(0)
{
}

Complex::Complex(double real_part) : real(real_part), imaginary(0)
{
}

static int digit_to_int(char c)
{
	return ( static_cast<int>(c) - static_cast<int>('0') );
}

bool operator ==(const Complex& first, const Complex& second)
{
	if (first.real == second.real && first.imaginary == second.imaginary)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Complex operator +(const Complex& first, const Complex& second)
{
	Complex ret;
	ret.real = first.real + second.real;
	ret.imaginary = first.imaginary + second.imaginary;
	return ret;
}

Complex operator -(const Complex& first, const Complex& second)
{
	Complex ret;
	ret.real = first.real - second.real;
	ret.imaginary = first.imaginary - second.imaginary;
	return ret;
}

Complex operator *(const Complex& first, const Complex& second)
{
	Complex ret;
	ret.real = first.real*second.real - first.imaginary*second.imaginary;
	ret.imaginary = first.real*second.imaginary + first.imaginary*second.real;
	return ret;
}

std::ostream& operator <<(std::ostream& outs, const Complex& second)
{
	outs << second.real;
	if (second.imaginary < 0)
	{
		outs << " - ";
	}
	else
	{
		outs << " + ";
	}
	outs << fabs(second.imaginary) << "*i";
	return outs;
}

std::istream& operator >>(std::istream& ins, Complex& second)
{                                                                                            
	bool negative;
	
	ins >> second.real;
	//std::cout << "real: " << second.real << "\n";
	char sign;
	ins >> sign;
	if (sign == '+')
	{
		negative = false;
	}
	else if (sign == '-')
	{
		negative = true;
	}
	else
	{
		std::cout << "error 1 inputting type money\n";
		exit(1);
	}
	
	ins >> second.imaginary;
	//std::cout << "imaginary: " << second.imaginary << "\n";
	if (negative)
	{
		second.imaginary *= -1;
	}
	//std::cout << "imaginary: " << second.imaginary << "\n";
	
	char mult, imag_symbol;
	ins >> mult >> imag_symbol;
	if (mult != '*' || imag_symbol != 'i')
	{
		std::cout << "error 1 inputting type money\n";
		exit(1);
	}
	return ins;
}

