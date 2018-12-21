#include <projectTests.hpp>
#include <iostream>
using namespace std;

void vert_num_test()
{
	cout << "write vertical(3):\n";
	write_vertical(3);

	cout << "write vertical(12):\n";
	write_vertical(12);

	cout << "write vertical(123):\n";
	write_vertical(123);
	
	cout << "write vertical iterative:\n";
	write_vertical_iterative(123456);
}

void self_test_test()
{
	cheers(3);
	asterisks(5);
	write_num_backwards(1234);
	list_ascending(7);
	cout << "\n";
	list_descending(7);
	cout << "\n";
	write_num_backwards_iterative(6789);
}

void power_test()
{
	cout << "10 to the power of -2 is " << power(10,-2) << "\n";
}

void search_test()
{
	using namespace recursive_binary_search;
	const int ARRAY_SIZE = 10;
	const int final_index = ARRAY_SIZE - 1;
	
	int a[ARRAY_SIZE];
	for (int i=0; i < ARRAY_SIZE; i++)
	{
		a[i] = i;
	}
	
	int key, location;
	bool found;
	cout << "enter a number to search for: ";
	cin >> key;
	search(a, 0, final_index, key, found, location);
	
	if (found)
	{
		cout << key << " is in index location " 
			<< location << "\n";
	}
	else
	{
		cout << key << " is not in the array\n";
	}
	
	search_iter(a, 0, final_index, key, found, location);
	
	if (found)
	{
		cout << key << " is in index location " 
			<< location << "\n";
	}
	else
	{
		cout << key << " is not in the array\n";
	}
}

void fibonacci_test()
{
	for (int i=0; i<10; i++)
	{
		cout << i << " fibonacci number is " << nth_fibonacci(i) << "\n";
	}
}

void find_smallest_test()
{
	int array[] = {14, 5, 98, 23, 1, 7, 9, 13};
	int num_elements = sizeof(array)/sizeof(int);
	cout << "there are " << num_elements << " items in the array\n";
	
	int low_index = index_of_smallest(array, 0, num_elements);
	cout << "the smallest element is " << array[low_index] << " at index " << low_index << "\n";
}

void search_test2()
{
	int array[] = {14, 5, 98, 23, 1, 7, 9, 13};
	int num_elements = sizeof(array)/sizeof(int);
	
	int target = 23;
	int index_of_target = search(array, 0, num_elements, target);
	if (index_of_target != 0)
	{
		cout << "the target " << target << " is found at index " << index_of_target << "\n";
	}
}

void factorial_test()
{
	for (int i=0; i<10; i++)
	{
		cout << i << "! = " << factorial(i) << "\n";
	}
}

void combinations_test()
{
	cout << "C(2, 1) is " << combinations(2, 1) << "\n";
	cout << "C(3, 2) is " << combinations(3, 2) << "\n";
	cout << "C(4, 1) is " << combinations(4, 1) << "\n";
	cout << "C(5, 3) is " << combinations(5, 3) << "\n";
}

void combinations_test_iter()
{
	cout << "C(2, 1) is " << combinations_iter(2, 1) << "\n";
	cout << "C(3, 2) is " << combinations_iter(3, 2) << "\n";
	cout << "C(4, 1) is " << combinations_iter(4, 1) << "\n";
	cout << "C(5, 3) is " << combinations_iter(5, 3) << "\n";
}

void swap_test()
{
	char array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int num_elements = sizeof(array)/sizeof(char);
	
	cout << "array";
	for (int i=0; i<num_elements; i++)
	{
		cout << " " << array[i];
	}
	cout << "\n";
	cout << "switching indices 2 and 4\n";
	swap(array, 2, 4);
	
	cout << "array";
	for (int i=0; i<num_elements; i++)
	{
		cout << " " << array[i];
	}
	cout << "\n";
}

void reverse_array_test()
{
	char array[] = "this is a test string";
	int num_elements = sizeof(array)/sizeof(char);
	
	for (int i=0; i<num_elements; i++)
	{
		cout << array[i];
	}
	cout << "\n";
	cout << "reversing\n";
	reverse_array(array, 0, num_elements-1);
	
	for (int i=0; i<num_elements; i++)
	{
		cout << array[i];
	}
	cout << "\n";		
}

void swap_sort_test()
{
	int array[] = {14, 5, 98, 23, 1, 7, 9, 13};
	int num_elements = sizeof(array)/sizeof(int);

	for (int i=0; i<num_elements; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\nsorting\n";
	swap_sort(array, 0, num_elements);
	
	for (int i=0; i<num_elements; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void hanoi_test()
{
	towers_of_hanoi(10);
}

void jump_test()
{
	jump_it(15);
}

void chocolate_bars_test()
{
	int total_money = 20;
	int bars = chocolate_bars(total_money);
	cout << "For $" << total_money << " you can get " << bars << " chocolate bars\n";
}

void permutations_test()
{
	vector<vector<int> > perms = get_permutations(0);
	display_permutations(perms);
}

void handshake_test()
{
	int number = 3;
	cout << "if there are " << number << " people in a room there are " << handshake(number) << " handshakes\n";
}

void palindrome_test()
{
	std::string test = "abecdcba";
	if (palindrome(test))
	{
		cout << test << " is a palindrome\n";
	}
	else
	{
		cout << test << " is not a palindrome\n";
	}
}
