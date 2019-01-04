#include <numericHist.hpp>
#include <iostream>
using namespace std;

namespace numeric_value_eric
{
	Error::Error(string the_message) : message(the_message)
	{
		//empty
	}
	
	string Error::get_message()
	{
		return message;
	}
	
	Value::Value() : key(0), count(0)
	{
		//empty
	}
	
	Value::Value(int the_key) : key(the_key), count(0)
	{
		//empty
	}
	
	Value::Value(int the_key, int the_count) : key(the_key), count(the_count)
	{
		//empty
	}
	
	Value& Value::operator =(const Value& right)
	{
		key = right.key;
		count = right.count;
		return *this;
	}
		
	int Value::get_key()
	{
		return key;
	}
	
	void Value::set_key(int new_key)
	{
		key = new_key;
	}
		
	int Value::get_count()
	{
		return count;
	}
	
	void Value::set_count(int new_count)
	{
		count = new_count;
	}
	
	void Value::increment_count()
	{
		count++;
	}
	
	NumericValues::NumericValues()
	{
		values.resize(10);
		
		for (int i=1; i<=10; i++)
		{
			values[i-1] = Value(i);
		}
	}
	
	void NumericValues::input() throw(Error)
	{
		int num_entries;
		cout << "How many numbers to enter?\n";
		cin >> num_entries;
		
		while (num_entries < 0)
		{
			cout << "How many numbers to enter?\n";
			cin >> num_entries;
		}
		cin.ignore(1000, '\n');
		
		for (int i=0; i<num_entries; i++)
		{
			try
			{
				string line;
				cout << "Enter number " << i + 1 << ":\n";
				getline(cin, line);
				
				for (uint32_t j=0; j<line.length(); j++)
				{
					if (!isdigit(line[j]) || line[j] == ' ')
					{
						throw Error("the number cant contain characters or spaces");
					}
				}
				add_value(atoi(line.c_str()));
			}
			catch (Error e)
			{
				cout << "Error: " << e.get_message() << "\n";
				i--;
			}
		}
	}
	
	void NumericValues::add_value(int new_value) throw(Error)
	{
		if (new_value < 1 || new_value > 10)
		{
			throw(Error("the digit must be 1-10"));
		}
		else
		{
			values[new_value-1].increment_count();
		}
	}
		
	void NumericValues::add_value(Value new_value) throw(Error)
	{
		for (int i=0; i<new_value.get_count(); i++)
		{
			add_value(new_value.get_key());
		}
	}
		
	void NumericValues::output_hist()
	{
		cout << "Here is the histogram of values:\n";
		for (int k = 0; k < 10; k++)
		{
			Value* current = &values[k];
			cout << current->get_key();
			if (current->get_key() < 10)
			{
				cout << " ";
			}
			cout << ": ";
			for (int c = 0; c<current->get_count(); c++)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}
}
