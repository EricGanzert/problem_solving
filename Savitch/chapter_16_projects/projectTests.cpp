#include <projectTests.hpp>
#include <iostream>
using namespace std;

void time_convert_test()
{
	using namespace time_convert_eric;
	
	convert();
}

void date_convert_test()
{
	using namespace date_convert_eric;
	
	convert();
}

void numeric_hist_test()
{
	using namespace numeric_value_eric;
	
	NumericValues v;
	v.input();
	v.output_hist();
}

void checked_array_test()
{
	using namespace checked_array_eric;
	
	CheckedArray arr(16);
	
	for (int i=0; i<arr.get_size(); i++)
	{
		arr[i] = i*3;
	}

	for (int i=0; i<arr.get_size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	CheckedArray copy(arr);
	for (int i=0; i<arr.get_size(); i++)
	{
		cout << copy[i] << " ";
	}
	cout << "\n";	
	
	CheckedArray another = copy;
	for (int i=0; i<arr.get_size(); i++)
	{
		cout << another[i] << " ";
	}
	cout << "\n";
	
	CheckedArray again(another.get_size());
	for (int i=0; i<again.get_size(); i++)
	{
		again[i] = another[i];
	}
	for (int i=0; i<again.get_size(); i++)
	{
		cout << again[i] << " ";
	}
	cout << "\n";
	
	cout << "trying to access index 33\n";
	try
	{
		cout << arr[33] << "\n";
	}
	catch (ArrayOutOfRangeError)
	{
		cout << "Index is out of range\n";
	}
	
	cout << "goodbye\n";
}

void stack_test()
{
	using namespace eric_stack_excep;
	
	Stack s(17);
	string test = "this is a test string";
	for (uint32_t i=0; i<test.length(); i++)
	{
		char c = test[i];
		try
		{
			cout << c << "\n";
			s.push(c);
		}
		catch (StackOverflowException)
		{
			cout << "cant add to stack, it is full\n";
		}
	}
	
	cout << "removing from stack\n";
	while (!s.empty())
	{
		cout << s.pop() << "\n";
	}
	
	try
	{
		s.pop();
	}
	catch (StackEmptyException)
	{
		cout << "cant take from stack, it is empty\n";
	}
}

void calling_depth_test()
{
	using namespace calling_depth_eric;
	
	int target = 11;
	
	try
	{
		calling_depth(0, target);
	}
	catch (int e)
	{
		cout << "Caught exception thrown at level " << e << "\n";
	}
}

void checked_array_2d_test()
{
	using namespace checked_array_eric;
	
	CheckedArray2D arr(8, 8);
	
	for (int y=0; y<arr.get_size_y(); y++)
	{
		for (int x=0; x<arr.get_size_x(); x++)
		{
			arr.set_element(x, y, x+y);
		}
	}

	cout << arr;
	
	CheckedArray2D copy(arr);
	cout << copy;	
	
	CheckedArray2D another = copy;
	cout << another;
	
	cout << "trying to access index 33, 1\n";
	try
	{
		cout << arr.get_element(33, 1) << "\n";
	}
	catch (ArrayOutOfRangeError)
	{
		cout << "Index is out of range\n";
	}
	
	cout << "goodbye\n";	
}

void bank_test()
{
	using namespace bank_eric;
	
	Account account(200);
	
	cout << "balance is " << account.deposit(20) << "\n";
	cout << "balance is " << account.withdraw(50) << "\n";
	
	try
	{
		account.withdraw(300);
	}
	catch (InsufficientFunds)
	{
		cout << "can't withdraw that much\n";
	}
	
	try
	{
		account.deposit(-1);
	}
	catch (InvalidDeposit)
	{
		cout << "cant deposit negative amount\n";
	}
}
