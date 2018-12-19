#include <selfTestExercises.hpp>
#include <iostream>
using namespace std;

void cheers(int n)
{
	if (n <= 1)
	{
		cout << "Hooray!\n";
	}
	else
	{
		cout << "Hip ";
		cheers(n-1);
	}
}

void asterisks(int n)
{
	if (n <= 0)
	{
		cout << "\n";
		return;
	}
	else
	{
		cout << "*";
		asterisks(n-1);
	}
}

void write_num_backwards(int n)
{
	if (n < 10)
	{
		cout << n << "\n";
		return;
	}
	else
	{
		cout << n % 10;
		write_num_backwards(n / 10);
	}
}

void list_ascending(int n)
{
	if (n >= 1)
	{
		list_ascending(n-1);
		cout << n << " ";
	}
}

void list_descending(int n)
{
	if (n >= 1)
	{
		cout << n << " ";
		list_descending(n-1);
	}
}

void write_num_backwards_iterative(int n)
{
	if (n < 0)
		cout << "-";
	n = abs(n);
	while (n > 0)
	{
		cout << n % 10;
		n = n / 10; 
	}
	cout << "\n";
}
