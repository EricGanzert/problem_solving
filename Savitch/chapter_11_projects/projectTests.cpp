#include <projectTests.hpp>

using namespace std;

void money_test()
{
	Money amount1(123,45), amount2(56,78);
	
	if (amount1 == amount2)
	cout << "they are equal\n";
	else
	{
		if (amount1 > amount2)
		{
			cout << amount1 << " > " << amount2 << "\n";
		}
		else
		{
			cout << amount1 << " < " << amount2 << "\n";
		}
	}
	
	cout << amount1 << " plus " << amount2 << " is " << amount1 + amount2 << "\n";
	cout << amount1 << " minus " << amount2 << " is " << amount1 - amount2 << "\n";
	cout << amount2 << " minus " << amount1 << " is " << amount2 - amount1 << "\n";
	
	int percent_figure = 1;
	
	cout << percent_figure << " percent of " << amount1 << " is " << amount1.percent(percent_figure) << "\n";
}

void pairs_test()
{
	ofstream out_stream;
	out_stream.open("pairs.dat");
	if (out_stream.fail())
	{
		cout << "could not open out stream\n";
		exit(1);
	}
	
	Pairs one_pair(1,2);
	Pairs another_pair(3,4);
	cout << "sending these pairs to a file " << one_pair << another_pair  << "\n";
	
	out_stream << one_pair << another_pair;
	out_stream.close();
	
	ifstream in_stream;
	in_stream.open("pairs.dat");
	if (in_stream.fail())
	{
		cout << "could not open imput stream\n";
		exit(1);
	}
	
	Pairs input_1, input_2;
	in_stream >> input_1 >> input_2;
	cout << "read these pairs from the file: " << input_1 << input_2 << "\n";
	
	Pairs mult = input_1 * input_2;
	Pairs add = input_1 + input_2;
	cout << input_1 << "* " << input_2 << " is " << mult << "\n"; 
	cout << input_1 << "+ " << input_2 << " is " << add << "\n"; 
}

void vector_double_test()
{
	VectorDouble array(10);
	
	for (int i=0; i<15; i++)
	{
		array.push_back(i + 0.01);
	}
	cout << "array size: " << array.size() << "\narray capacity: " << array.capacity() << "\nreserve: " << array.reserve() << "\ncontents:\n" << array << "\n";
	
	VectorDouble new_array(array);
	cout << "copy constructor test: \n" << new_array << "\n";
	
	if (array == new_array)
	{
		cout << "arrays are equal\n";
	}
	else
	{
		cout << "arrays not equal\n";
	}
	
	for (int i=new_array.size()-1; i>=0; i--)
	{
		new_array.change_value_at((new_array.size()-1)-i, i + 0.01);
	}
	
	cout << "reversed array:\n" << new_array << "\n";
	
	if (array == new_array)
	{
		cout << "arrays are equal\n";
	}
	else
	{
		cout << "arrays not equal\n";
	}
	
	new_array = array;
	cout << "assignment operator test:\n" << new_array << "\n";
	
	if (array == new_array)
	{
		cout << "arrays are equal\n";
	}
	else
	{
		cout << "arrays not equal\n";
	}
}

void percent_test()
{
	Percent test1, test2;
	cout << "Enter a percent: ";
	cin >> test1; 
	cin.ignore(10000, '\n');
	cout << test1 << "\n";
	cout << "Enter another percent: ";
	cin >> test2;
	cin.ignore(10000, '\n');
	cout << test2 << "\n";
	
	cout << test1 << " + " << test2 << " = " << (test1 + test2) << "\n";
	cout << test1 << " - " << test2 << " = " << (test1 - test2) << "\n";
	cout << test1 << " * " << 15 << " = " << (test1 * 15) << "\n";
}

void rational_test()
{
	//~ Rational test;
	//~ cout << "enter a rational number: ";
	//~ cin >> test;
	//~ cout << test << "\n";
	
	Rational a(3,4); Rational b(-5,2);
	
	cout << "Testing with " << a << " and " << b << "\n";
	cout << a << " + " << b << " = " << a + b << "\n";
	cout << a << " - " << b << " = " << a - b << "\n";
	cout << a << " * " << b << " = " << a * b << "\n";
	cout << a << " / " << b << " = " << a / b << "\n";
}

void complex_test()
{
	//~ Complex test;
	//~ cout << "enter an imaginary number like this: a + b*i\n";
	//~ cin >> test;
	//~ cout << "You entered: " << test << "\n";
	
	Complex a(1, 3.3);
	Complex b(-1.1, -4.1);
	
	cout << "a = " << a << "\nb = " << b << "\n";
	cout << "a+b = " << a+b << "\n";
	cout << "a-b = " << a-b << "\n";
	cout << "a*b = " << a*b << "\n";
	
}
