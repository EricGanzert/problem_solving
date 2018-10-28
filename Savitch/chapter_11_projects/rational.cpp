#include <rational.hpp>

using namespace std;

static int digit_to_int(char c)
{
	return ( static_cast<int>(c) - static_cast<int>('0') );
}

static bool is_prime(int number)
{
	if (number <= 3)
	{
		return number >= 1;
	}
	else if(number%2 == 0 || number%3 == 0)
	{
		return false;
	}
	else
	{
		for (int i=5; i*i <= number; i += 6)
		{
			if (number%i == 0)
				return false;
		}
		return true;
	}
}

static int highest_common_factor(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

Rational::Rational(int numerator, int denominator) : num(numerator), denom(denominator)
{ normalize(); }

Rational::Rational(int whole_number) : num(whole_number), denom(1)
{}

Rational::Rational() : num(0), denom(1)
{}

void Rational::normalize()
{
	bool negative = false;
	if (num < 0 || denom < 0)
	{
		if (!(num < 0 && denom < 0))
			negative = true;
	}
	int abs_num = abs(num);
	int abs_denom = abs(denom);
	while ( !is_prime(abs_num) && !is_prime(abs_denom) )
	{
		int common_factor = highest_common_factor(abs_num, abs_denom);
		if (common_factor == 1)
			return;
		abs_num = abs_num/common_factor;
		abs_denom = abs_denom/common_factor;
	}
	if (negative)
		num = -abs_num;
	else
		num = abs_num;
	denom = abs_denom;
}

ostream& operator <<(ostream& outs, const Rational& second)
{
	outs << second.num << "/" << second.denom;
	return outs;
}

istream& operator >>(istream& ins, Rational& second)
{
	char c;
	bool num_negative = false;
	bool denom_negative = false;
	ins.get(c);
	while(c == ' ') //maybe I dont need this
	{
		ins.get(c);
	}
	if (c == '-')
	{
		num_negative = true;
		ins.get(c); //should be numerator
	}

	if (!isdigit(c))
	{
		cout << "Error inputing Rational, numerator not found\n";
		exit(1);
	}
	if (num_negative)
		second.num = -digit_to_int(c);
	else
		second.num = digit_to_int(c);
	
	ins.get(c); // should be '/'
	if (c != '/')
	{
		cout << "Error inputing Rational, no '/'\n";
		exit(1);
	}
	ins.get(c);
	
	if (c == '-')
	{
		denom_negative = true;
		ins.get(c);
	}
	
	if (!isdigit(c))
	{
		cout << "Error inputing Rational, denominator not found\n";
		exit(1);
	}
	
	if (denom_negative)
		second.denom = -digit_to_int(c);
	else
		second.denom = digit_to_int(c);
		
	second.normalize();
	return ins;
}

bool operator ==(const Rational& first, const Rational& second)
{
	if ((first.denom * second.num) == (first.num * second.denom))
	{
		return true;
	}
	else
		return false;
}

bool operator <(const Rational& first, const Rational& second)
{
	double first_magnitude = static_cast<double>(first.num) / static_cast<double>(first.denom);
	double second_magnitude = static_cast<double>(second.num) / static_cast<double>(second.denom);
	
	if (first_magnitude < second_magnitude)
		return true;
	else
		return false;
}

bool operator <=(const Rational& first, const Rational& second)
{
	double first_magnitude = static_cast<double>(first.num) / static_cast<double>(first.denom);
	double second_magnitude = static_cast<double>(second.num) / static_cast<double>(second.denom);
	
	if (first_magnitude <= second_magnitude)
		return true;
	else
		return false;	
}

bool operator >(const Rational& first, const Rational& second)
{
	double first_magnitude = static_cast<double>(first.num) / static_cast<double>(first.denom);
	double second_magnitude = static_cast<double>(second.num) / static_cast<double>(second.denom);
	
	if (first_magnitude > second_magnitude)
		return true;
	else
		return false;	
}

bool operator >=(const Rational& first, const Rational& second)
{
	double first_magnitude = static_cast<double>(first.num) / static_cast<double>(first.denom);
	double second_magnitude = static_cast<double>(second.num) / static_cast<double>(second.denom);
	
	if (first_magnitude >= second_magnitude)
		return true;
	else
		return false;	
}

Rational operator +(const Rational& first, const Rational& second)
{
	Rational ret;
	int common_denom = first.denom * second.denom;
	
	ret.num = first.num*second.denom + second.num*first.denom;
	ret.denom = common_denom;
	ret.normalize();
	return ret;
}

Rational operator -(const Rational& first, const Rational& second)
{
	Rational ret;
	int common_denom = first.denom * second.denom;
	
	ret.num = first.num*second.denom - second.num*first.denom;
	ret.denom = common_denom;
	ret.normalize();
	return ret;
}

Rational operator *(const Rational& first, const Rational& second)
{
	Rational ret;
	ret.num = first.num * second.num;
	ret.denom = first.denom * second.denom;
	ret.normalize();
	return ret;
}

Rational operator /(const Rational& first, const Rational& second)
{
	Rational ret;
	ret.num = first.num * second.denom;
	ret.denom = first.denom * second.num;
	ret.normalize();
	return ret;
}
