#include <stringVar.hpp>
#include <cstdlib>
#include <cstddef>
#include <cstring>
using namespace std;

StringVar::StringVar(int size) : max_length(size)
{
	value = new char[max_length+1]; //+1 for \0
	value[0] = '\0';
}

StringVar::StringVar() : max_length(100)
{
	value = new char[max_length+1]; //+1 for \0
	value[0] = '\0';
}

StringVar::StringVar(const char a[]) : max_length(strlen(a))
{
	value = new char[max_length+1];
	value[max_length+1] = '\0';
	strcpy(value, a);
}

StringVar::~StringVar()
{
	delete[] value;
}

StringVar::StringVar(const StringVar& copy)
                     : max_length(copy.length())
{
	value = new char[max_length + 1]; //+1 for '\0'
	strcpy(value, copy.value);
}

void StringVar::input_line(istream& ins)
{
	ins.getline(value, max_length+1);
}

int StringVar::length() const
{
	return strlen(value);
}

ostream& operator <<(ostream& outs, const StringVar& the_string)
{
	outs << the_string.value;
	return outs;
}
	
StringVar StringVar::copy_piece(int index1, int index2)
{
	if (index1 < 0 ||
		index2 < 0 ||
		index1 > max_length || 
		index2 > max_length || 
		index1 >= index2)
	{
		return StringVar();
	}
	
	int copy_length = index2-index1;
	StringVar ret(copy_length);
	
	for (int i=0; i<copy_length; i++)
	{
		ret.set_char(i, one_char(index1 + i));
	}
	
	return ret;
}

char StringVar::one_char(int index) const
{
	return value[index];
}

void StringVar::set_char(int index, char new_char)
{
	value[index] = new_char;
}

bool operator ==(const StringVar& left, const StringVar& right)
{
	int i=0;
	while (i <= left.length() && i <= right.length())
	{
		if (left.value[i] != right.value[i])
		{
			return false;
		}
		i++;
	}
	return true;
}

StringVar operator +(const StringVar& left, const StringVar& right)
{	
	StringVar ret(left.length() + right.length());
	int index = 0;
	for (int i=0; i<left.length(); i++)
	{
		ret.set_char(index, left.one_char(i));
		index++;
	}
	for (int i=0; i<right.length(); i++)
	{
		ret.set_char(index, right.one_char(i));
		index++;
	}
	return ret;
}

istream& operator >>(istream& ins, StringVar& right)
{
	delete[] right.value;
	string temp;
	ins >> temp;
	right.max_length = temp.length();
	right.value = new char[temp.length()];
	
	for (int i=0;i<temp.length();i++)
	{
		right.value[i] = temp[i];
	}
	right.value[temp.length()] = '\0';
	return ins;
}

StringVar& StringVar::operator =(const StringVar& second)
{
	delete[] value;
	max_length = second.max_length;
	value = new char[max_length];
	
	for (int i=0;i<second.length();i++)
	{
		value[i] = second.one_char(i);
	}
	value[second.length()] = '\0';
	return *this;
}


