#include <verticalNumbers.hpp>
#include <iostream>

void write_vertical(int n)
{
	if (n < 10)
	{
		std::cout << n << "\n";
	}
	else
	{
		write_vertical(n / 10);
		std::cout << n % 10 << "\n";
	}
}

void write_vertical_iterative(int n)
{
	int tens_in_n = 1;
	int left_end_piece = n;
	while (left_end_piece > 9)
	{
		left_end_piece = left_end_piece/10;
		tens_in_n = tens_in_n * 10;
	}
	
	for (int power_of_10 = tens_in_n; power_of_10 > 0; power_of_10 = power_of_10/10)
	{
		std::cout << (n/power_of_10) << "\n";
		n = n % power_of_10;
	}
}
