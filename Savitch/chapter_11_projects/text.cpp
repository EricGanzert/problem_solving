#include <iostream>
#include <text.hpp>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

Text::Text() : max_length(100)
{
	value = new StringVar[max_length+1];
	value[0] = StringVar(" ");
}

Text::Text(int size) : max_length(size)
{
	value = new StringVar[max_length+1];
	value[0] = StringVar(" ");
}

Text::Text(const char a[])
{
	stringstream ss(a);
	vector<string> strings_vec;
	string temp;
	while (ss >> temp)
	{
		strings_vec.push_back(temp);
	}
	max_length = strings_vec.size();
	value = new StringVar[max_length + 1]; // +1 for " "
	
	for (int i=0; i<max_length; i++)
	{
		value[i] = StringVar(strings_vec[i].c_str());
	}
	value[max_length] = StringVar(" ");
}

Text::Text(const Text& copy) : max_length(copy.max_length)
{
	value = new StringVar[max_length+1];
	for (int i=0; i<max_length; i++)
	{
		value[i] = copy.one_string(i);
	}
	value[max_length] = StringVar(" ");
}

Text::~Text()
{
	delete[] value;
}

int Text::length() const
{
	int count = 0;
	while ( !(value[count] == " ") && count < max_length )
	{
		count++;
	}
	return count;
}

void Text::input_line(istream& ins)
{
	string input_str;
	std::getline(ins, input_str);
	
	stringstream ss(input_str);
	vector<string> strings_vec;
	string temp;
	while (ss >> temp)
	{
		strings_vec.push_back(temp);
	}
	max_length = strings_vec.size();
	value = new StringVar[max_length + 1]; // +1 for " "
	
	for (int i=0; i<max_length; i++)
	{
		value[i] = StringVar(strings_vec[i].c_str());
	}
	value[max_length] = StringVar(" ");	
}

ostream& operator <<(ostream& outs, const Text& the_text)
{
	int i=0;
	while (i < the_text.length())
	{
		outs << the_text.value[i] << " ";
		i++;
	}
	return outs;
}

Text Text::copy_piece(int index1, int index2)
{
	if (index1 < 0 ||
		index2 < 0 ||
		index1 > max_length || 
		index2 > max_length || 
		index1 >= index2)
	{
		return Text();
	}
	Text ret;
	ret.max_length = index2-index1;
	ret.value = new StringVar[ret.max_length+1];
	
	int i=0;
	while (i<ret.max_length)
	{
		ret.value[i] = this->value[i+index1];
		i++;
	}
	ret.value[ret.max_length] = StringVar(" ");
	return ret;
}

StringVar Text::one_string(int index) const
{
	return value[index];
}


void Text::set_string(int index, char new_string[])
{
	value[index] = StringVar(new_string);
}

bool operator ==(const Text& left, const Text& right)
{
	int i=0;
	while (i <= left.length() && i <= right.length())
	{
		if (!(left.value[i] == right.value[i]))
		{
			return false;
		}
		i++;
	}
	return true;	
}

Text operator +(const Text& left, const Text& right)
{
	Text ret(left.length() + right.length() + 1);
	
	for (int i=0; i<left.length(); i++)
	{
		ret.value[i] = left.value[i];
	}
	
	for (int i=0; i<right.max_length; i++)
	{
		ret.value[i+left.length()] = right.value[i];
	}
	ret.value[ret.max_length] = StringVar(" ");
	
	return ret;
}

istream& operator >>(istream& ins, Text& right)
{
	delete[] right.value;
	string input_str;
	std::getline(ins, input_str);
	stringstream ss(input_str);
	
	vector<StringVar> stream_collect;
	string str_in;
	while(ss >> str_in)
	{
		stream_collect.push_back(StringVar(str_in.c_str()));
	}
	right.max_length = stream_collect.size();
	right.value = new StringVar[right.max_length+1];
	
	for (int i=0; i<right.max_length; i++)
	{
		right.value[i] = stream_collect[i];
	}
	right.value[right.max_length] = " ";
	
	return ins;
}


Text& Text::operator =(const Text& second)
{
	delete[] value;
	max_length = second.max_length;
	value = new StringVar[max_length+1];
	
	for (int i=0;i<second.length();i++)
	{
		value[i] = second.one_string(i);
	}
	value[max_length] = '\0';
	return *this;
}

