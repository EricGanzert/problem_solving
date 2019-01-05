#include <projectTests.h>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void array_find_test()
{
	srand(time(NULL));
	using namespace arr_alg_eric;
	int size = 100;
	int a[size];
	
	for (int i=0; i<size; i++)
	{
		a[i] = rand()%50;
		cout << a[i] << " ";
	}
	cout << "\n";
	
	for (int test = 20; test<50; test = test+2)
	{
		cout << "finding " << test << "\n";
		int index = find(test, a, size);
		if (index >= 0)
		{
			cout << "found it at index " << index << "\n";
		}
		else
		{
			cout << "its not in the array\n";
		}
	}
}

void generic_list_test()
{
	using namespace list_eric;
	string test = "this is a test string";
	
	GenericList<char> l(100);
	
	for (uint32_t i=0; i<test.length(); i++)
	{
		l.add(test[i]);
	}
	cout << l;
	for (uint32_t i=0; i<test.length(); i++)
	{
		cout << l.get_current_item() << "\n";
		l.increment_current();
	}
	
	srand(time(NULL));
	int size = 80;
	GenericList<int> a(size);
	
	for (int i=0; i<size; i++)
	{
		a.add(rand()%70);
		cout << a.get_nth(i) << " ";
	}
	cout << "\n";
	
	for (int test = 20; test<50; test = test+2)
	{
		cout << "finding " << test << "\n";
		int index = find(test, a);
		if (index >= 0)
		{
			cout << "found it at index " << index << "\n";
		}
		else
		{
			cout << "its not in the array\n";
		}
	}	
}

void delete_repeats_test()
{
	using namespace arr_alg_eric;
	
	char a[10] = {'a', 'b', 'a', 'f', 'u', 'c', 'b', 'a'};
	int num_used = 8;
	for (int i=0; i<num_used; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
	
	delete_repeats(a, num_used);
	for (int i=0; i<num_used; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";	
}

void selection_sort_test()
{
	srand(time(NULL));
	using namespace arr_alg_eric;
	int size = 10;
	int a[size];
	
	for (int i=0; i<size; i++)
	{
		a[i] = rand()%10;
		cout << a[i] << " ";
	}
	cout << "\n";
	
	insertion_sort(a, size);
	for (int i=0; i<size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

void binary_search_test()
{
	using namespace arr_alg_eric;
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

void binary_search_recursive_test()
{
	using namespace arr_alg_eric;
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
}
