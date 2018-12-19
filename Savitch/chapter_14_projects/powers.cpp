#include <powers.hpp>
#include <iostream>
#include <cstdlib>
using namespace std;

double power(int x, int n)
{
	if (n < 0)
	{
		return 1/power(x,abs(n));
	}
	if (n > 0)
	{
		return (x * power(x, n-1));
	}
	else
	{
		return 1;
	}
}
