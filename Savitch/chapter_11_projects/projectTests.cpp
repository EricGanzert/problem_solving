#include <projectTests.hpp>
#include <iostream>
#include <fstream>
#include <vector>

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

void stringvar_test()
{
	StringVar test("this is a test string");
	cout << "size of " << test << " is " << test.length() << "\n";
	
	for (int i=0; i <= test.length(); i++)
	{
		cout << test.one_char(i) << " ";
		if (test.one_char(i) == '\0')
		{
			cout << "termination character\n";
		}
	}
	cout << "\n";
	StringVar test_2 = test.copy_piece(2,11);
	cout << test_2 << "\n"
		 << "length of " << test_2 << " is " << test_2.length() << "\n";
		 
	for (int i=0; i<5; i++)
	{
		test.set_char(i,'x');
	}
	
	cout << test << "\n";
	
	StringVar a("test1");
	StringVar b("test2");
	StringVar c(a);
	
	if (!(a == b))
	{
		cout << a << " and " << b << " not equal\n"; 
	}
	if (a == c)
	{
		cout << a << " and " << c << " are equal\n"; 
	}
	
	a = b;
	
	if (a == b)
	{
		cout << a << " and " << b << " are equal\n"; 
	}
	if (!(a == c))
	{
		cout << a << " and " << c << " not equal\n"; 
	}
	
	StringVar in_test;
	cout << "enter a line of text: ";
	cin >> in_test;
	cout << "the first word is: " << in_test << "\n";
}

void text_test()
{
	Text test("this is a test string");
	cout << test << "\n";
	
	Text blank_text;
	blank_text = Text("testing assignment operator");
	cout << blank_text << "\n";
	
	for (int i=0;i<=test.length();i++)
	{
		if (test.one_string(i) == " ")
		{
			cout << "termination character\n";
		}
	}
	
	//~ Text test_input_line;
	//~ cout << "enter a line of text\n";
	//~ test_input_line.input_line(cin);
	//~ cout << test_input_line << "\n";
	
	Text subText;
	subText = test.copy_piece(1,3);
	cout << "length of copy piece is: " << subText.length() << "\n";
	cout << "copy_piece test: " << subText << "\n";
	
	test.set_string(0, (char*)"hello");
	cout << test << "\n";
	
	cout << test.one_string(0) << "\n";
	
	test = blank_text;
	cout << test << "\n";
	
	Text added;
	added = test + subText;
	cout << added << "\n";
	
	Text copy_text;
	copy_text = test + subText;
	
	if (added == copy_text)
	{
		cout << "success\n";
	}
	 
	Text in_stream_test;
	cout << "enter a line of text: ";
	cin >> in_stream_test;
	cout << in_stream_test;
}

void polynomial_test()
{
	cout << "Testing Polynomial class\n\n";
	Polynomial test(3);
	test.set_coefficient(0, 0.5);
	test.set_coefficient(1, 2);
	test.set_coefficient(2, 3);
	test.set_coefficient(3, 1);
	
	cout << test << "\n";
	
	vector<double> coefs;
	coefs.push_back(0.1);
	coefs.push_back(0.2);
	coefs.push_back(0.3);
	coefs.push_back(0.4);
	Polynomial test2(coefs);
	
	cout << test2 << "\n";
	
	Polynomial test3(test2);
	cout << test3 << "\n";
	
	Polynomial test4 = test3;
	cout << test4 << "\n"; 
	
	cout << "evaluating " << test << " at x=2.2 ..." << test.evaluate(2.2) << "\n";
	
	Polynomial add1;
	add1 = 4 - test;
	cout << 4 << " - " << test << " = " << add1 << "\n";
	
	Polynomial test5;
	test5 = test * test2;
	cout << test << " * " << test2 << " = \n";
	cout << test5 << "\n";
}


void checkbook_test()
{
	balance_checkbook();
}

void list_test()
{
	List a;
	a.add_item(4.05);
	a.add_item(0.01);
	cout << a;
	if (a.full())
	{
		cout << "list is full\n";
	}
	else
	{
		cout << "list not full\n";
	}
	a.delete_last();
	cout << a;
	a.delete_last();
	
	for (int i=0; i<50; i++)
	{
		a.add_item(i+0.1);
	}
	cout << a;
	
	if (a.full())
	{
		cout << "list is full\n";
	}
	else
	{
		cout << "list not full\n";
	}
	
	for (int i=0;i<50;i++)
	{
		cout << a.get_item(i) << "\n";
	}
}
