#include <projectFunctions.hpp>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

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

void jump_it(int board_size)
{
	//make the game board: 0 then random numbers
	int* game_board = new int[board_size];
	game_board[0] = 0;
	srand (time(NULL));
	
	for (int i=1; i<board_size; i++)
	{
		game_board[i] = rand() % 100;
	}
	int index = 0;
	int total_score = 0;
	
	total_score = choose_jump(game_board, index, board_size);
	
	std::cout << "Here is the game board: \n";
	for (int i=0; i<board_size; i++)
	{
		std::cout << "|" << game_board[i] << "|" << " ";
	}
	std::cout << "\nThe lowest possible score is " << total_score << "\n";
	
	delete [] game_board; 
}

int choose_jump(int* game_board, int index, int board_size)
{
	if (index == board_size-1)
	{
		return game_board[index];
	}
	else if (index == board_size-2)
	{
		return game_board[index] + choose_jump(game_board, index+1, board_size);
	}
	else
	{
		if (game_board[index+1] < game_board[index+2])
		{
			return game_board[index] + choose_jump(game_board, index+1, board_size);
		}
		else
		{
			return game_board[index] + choose_jump(game_board, index+2, board_size);
		}
	}
}

int chocolate_bars(int dollars)
{
	int bars = dollars;
	int coupons = bars;
	
	return bars + redeem(coupons);
}

int redeem(int coupons)
{
	if (coupons < 7)
	{
		return 0;
	}
	else
	{
		return (coupons / 7) + redeem(coupons / 7 + coupons % 7);
	}
}

int handshake(int n)
{
	return combinations(n, 2);
}

bool palindrome(std::string str)
{
	return str_index_match(str, 0, str.length()-1);
}

bool str_index_match(std::string str, int index1, int index2)
{
	if (index1 == index2 || index1 > index2)
	{
		return true;
	}
	else
	{
		if (str[index1] == str[index2])
		{
			return str_index_match(str, index1+1, index2-1);
		}
		else
		{
			return false;
		}
	}
}
