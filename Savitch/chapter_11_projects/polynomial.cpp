#include <polynomial.hpp>
#include <math.h>
using namespace std;

Polynomial::Polynomial() : max_exp(0)
{
	value = new double[1];
	value[0] = 0;
}

Polynomial::Polynomial(const Polynomial& copy) : max_exp(copy.max_exp)
{
	value = new double[max_exp+1];
	
	for (int i=0; i <= max_exp; i++)
	{
		value[i] = copy.value[i];
	}
}

Polynomial::Polynomial(int max_exp_arg) : max_exp(max_exp_arg)
{
	value = new double[max_exp+1];
	
	for (int i=0; i <= max_exp; i++)
	{
		value[i] = 0;
	}
}

Polynomial::Polynomial(vector<double> coefs) : max_exp(coefs.size()-1)
{
	value = new double[max_exp+1];
	
	for (int i=0; i <= max_exp; i++)
	{
		value[i] = coefs[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] value;
}

double Polynomial::evaluate(double input_value)
{
	double result=0;
	for (int i=0; i<max_exp; i++)
	{
		result += value[i]*pow(input_value, i);
	}
	return result;
}

double Polynomial::get_coefficient(int index) const
{
	return value[index];
}

void Polynomial::set_coefficient(int index, double new_coef)
{
	value[index] = new_coef;
}

Polynomial& Polynomial::operator =(const Polynomial& right)
{
	delete[] value;
	max_exp = right.max_exp;
	value = new double[max_exp+1];
	
	for (int i=0; i<=max_exp; i++)
	{
		value[i] = right.value[i];
	}
	return *this;
}

Polynomial operator +(const Polynomial& left, const Polynomial& right)
{
	//initialize the return as the higher-degree polynomial
	Polynomial result;
	int min_deg;
	
	if (left.max_exp > right.max_exp)
	{
		result = left;
		min_deg = right.max_exp;
	}
	else
	{
		result = right;
		min_deg = left.max_exp;
	}
	
	for (int i=0; i<=min_deg; i++)
	{
		result.value[i] = left.value[i] + right.value[i];
	}
	
	return result;
}

Polynomial operator +(const Polynomial& left, double constant)
{
	Polynomial result(left);
	result.value[0] += constant;
	return result;
}

Polynomial operator +(double constant, const Polynomial& right)
{
	Polynomial result(right);
	result.value[0] += constant;
	return result;
}

Polynomial operator -(const Polynomial& left, const Polynomial& right)
{
	//initialize the return as the higher-degree polynomial
	Polynomial result;
	int min_deg;
	
	if (right.max_exp > left.max_exp)
	{
		result = right;
		min_deg = right.max_exp;
		//init the highest exp coefficients to negative in this case
		for (int i=min_deg+1; i<right.max_exp; i++)
		{
			result.value[i] = -result.value[i];
		}
	}
	else
	{
		result = left;
		min_deg = right.max_exp;
	}
	
	for (int i=0; i<=min_deg; i++)
	{
		result.value[i] = left.value[i] - right.value[i];
	}
	
	return result;
}

Polynomial operator -(const Polynomial& left, double constant)
{
	Polynomial result(left);
	result.value[0] -= constant;
	return result;
}

Polynomial operator -(double constant, const Polynomial& right)
{
	Polynomial result(right);
	result.value[0] = constant - right.value[0];
	if (right.max_exp > 0)
	{
		for (int i=1; i<=right.max_exp; i++)
		{
			result.value[i] = -result.value[i]; 
		}
	}
	
	result.max_exp;
	return result;
}

Polynomial operator *(const Polynomial& left, const Polynomial& right)
{
	int res_max_exp = left.max_exp + right.max_exp;
	Polynomial result(res_max_exp);
	//cout << "result max exp is " << res_max_exp << "\n";
	
	int current_exp = 0;
	for (int i=0; i<=left.max_exp; i++)
	{
		for (int j=0; j<=right.max_exp; j++)
		{
			current_exp = i+j;
			//cout << "(i,j) = (" << i << "," << j << "), current_exp: " << current_exp << "\n";
			result.value[current_exp] += left.value[i]*right.value[j];
			//cout << ".\n";
		}
	}
	return result;
}

Polynomial operator *(const Polynomial& left, double constant)
{
	Polynomial result(left);
	for (int i=0;i<=left.max_exp;i++)
	{
		result.value[i] *= constant; 
	}
	return result;
}

Polynomial operator *(double constant, const Polynomial& right)
{
	Polynomial result(right);
	for (int i=0;i<=right.max_exp;i++)
	{
		result.value[i] *= constant; 
	}
	return result;
}

ostream& operator <<(ostream& out_stream, const Polynomial& right)
{
	for (int i=0; i<=right.max_exp; i++)
	{
		out_stream << right.value[i] << "*x^" << i;
		if (i<right.max_exp)
		{
			out_stream << " + ";
		}
	}
	return out_stream;
}






