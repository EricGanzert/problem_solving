#include <projectFunctions.hpp>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

int nth_fibonacci(int n)
{
	if (n < 0)
	{
		std::cout << "Error: negative arg to fibonacci\n";
		exit(1);
	}
	else if (n == 0 || n == 1)
	{
		return 1;
	}
	else //n > 0
	{
		return nth_fibonacci(n-1) + nth_fibonacci(n-2);
	}
}

int index_of_smallest(const int a[], int start_index, int number_used)
{
	if (start_index == number_used-1)
	{
		return start_index;
	}
	else
	{
		int smallest_of_the_rest = index_of_smallest(a, start_index+1, number_used);
		if (a[start_index] < a[smallest_of_the_rest])
		{
			return start_index;
		}
		else
		{
			return smallest_of_the_rest;
		}
	}
}

int search(const int a[], int low_index, int number_used, int target)
{
	if (target == a[low_index])
	{
		return low_index;
	}
	else if (low_index == number_used)
	{
		return -1;
	}
	else
	{
		return (search(a, low_index+1, number_used, target));
	}
}

int factorial(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}

int factorial_iter(int n)
{
	if (n < 0)
	{
		std::cout << "Error: negative arg to factorial\n";
	}
	
	int result = 1;
	while (n > 0)
	{
		result *= n;
		n--;
	}
	return result;
}

int combinations(int n, int r)
{
	if (r > n || n < 0 || r < 0)
	{
		std::cout << "Error: invalid args to combinations\n";
		exit(1);
	}
	return factorial(n) / (factorial(r) * factorial(n - r));
}

int combinations_iter(int n, int r)
{
	if (r > n || n < 0 || r < 0)
	{
		std::cout << "Error: invalid args to combinations\n";
		exit(1);
	}
	return factorial_iter(n) / (factorial_iter(r) * factorial_iter(n - r));
}

void swap(char a[], int index1, int index2)
{
	char temp = a[index2];
	a[index2] = a[index1];
	a[index1] = temp;
}

void swap(int a[], int index1, int index2)
{
	int temp = a[index2];
	a[index2] = a[index1];
	a[index1] = temp;
}

void reverse_array(char a[], int low_index, int high_index)
{
	if (low_index == high_index || low_index > high_index)
	{
		//done
		return;
	}
	else
	{
		swap(a, low_index, high_index);
		reverse_array(a, low_index+1, high_index-1);
	}
}

void swap_sort(int a[], int low_index, int num_elements)
{
	if (low_index == num_elements-1)
	{
		//done
		return;
	}
	else
	{
		int small_index = index_of_smallest(a, low_index, num_elements);
		swap(a, low_index, small_index);
		swap_sort(a, low_index+1, num_elements);
	}
}
