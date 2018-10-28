#include <percent.hpp>
using namespace std;

static int digit_to_int(char c)
{
	return ( static_cast<int>(c) - static_cast<int>('0') );
}

bool operator ==(const Percent& first, const Percent& second)
{
	if (first.value == second.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator <(const Percent& first, const Percent& second)
{
	if (first.value < second.value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Percent::Percent() : value(0)
{
	
}

Percent::Percent(int percent_value) : value(percent_value)
{
	
}

istream& operator >>(istream& ins, Percent& second)
{
	char one_char;
	bool negative;
	
	ins >> one_char;
	if (one_char == '-')
	{
		negative = true;
		ins >> one_char;
	}
	else
	{
		negative = false;
	}
	
	if (!(isdigit(one_char)))
	{
		cout << "Error inputting Percent, no leading digit\n";
		exit(1);
	}
	
	std::vector<char> digits;
	digits.push_back(one_char);
	char c;
	ins.get(c);

	while (isdigit(c))
	{
		digits.push_back(c);
		if (digits.size() > 4)
		{
			cout << "Error inputting Percent, too many digits\n";
			exit(1);		
		}
		ins.get(c);
	}
	
	if (c != '%')
	{
		cout << "Error inputting Percent, no percent sign\n";
		exit(1);
	}

	//convert the char digits to a whole number
	int the_value = 0;
	for (int i=0; i < digits.size(); i++)
	{
		the_value += pow(10, i)*digit_to_int(digits[digits.size() -1 - i]);
	}
	
	if (negative)
	{
		second.value = -the_value;
	}
	else
	{
		second.value = the_value;
	}
}

ostream& operator <<(ostream& outs, const Percent& second)
{
	outs << second.value << "%";
	return outs;  
}

Percent operator +(const Percent& first, const Percent& second)
{
	Percent ret;
	ret.value = first.value + second.value;
	return ret;
}

Percent operator -(const Percent& first, const Percent& second)
{
	Percent ret;
	ret.value = first.value - second.value;
	return ret;
}

Percent operator *(const Percent& first, int second)
{
	Percent ret;
	ret.value = first.value * second;
	return ret;
}


