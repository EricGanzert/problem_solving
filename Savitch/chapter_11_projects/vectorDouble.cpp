#include <vectorDouble.hpp>
#include <iostream>

using namespace std;

VectorDouble& VectorDouble::operator =(const VectorDouble& second)
{
	if (this == &second)
	{
		return *this;
	}
	else
	{
		if (max_count == second.max_count)
		{
			count = second.count;
			for (int i=0; i<count; i++)
			{
				dynamic_array[i] = second.dynamic_array[i];
			}
		}
		else
		{
			delete[] dynamic_array;
			max_count = second.max_count;
			count = second.count;
			dynamic_array = new double[max_count];
		
			for (int i=0; i<count; i++)
			{
				dynamic_array[i] = second.dynamic_array[i];
			}	
		}
	}
}

bool operator ==(const VectorDouble& first, const VectorDouble& second)
{
	if (!(first.count == second.count))
	{
		return false;
	}
	else
	{
		for (int i=0; i<first.count; i++)
		{
			if (first.dynamic_array[i] != second.dynamic_array[i])
			{
				return false;
			}
		}
		return true;
	}
}

ostream& operator <<(ostream& outs, const VectorDouble& output)
{
	outs << "(";
	for (int i=0; i<output.count-1; i++)
	{
		outs << output.dynamic_array[i] << " ";
	}
	outs << output.dynamic_array[output.count-1] << ")";
	return outs;
}

VectorDouble::VectorDouble() : count(0), max_count(50)
{
	dynamic_array = new double[max_count];
}

VectorDouble::VectorDouble(int size_arg) : count(0), max_count(size_arg)
{
	dynamic_array = new double[max_count];
}

VectorDouble::VectorDouble(const VectorDouble& copy) : count(copy.count), max_count(copy.max_count)
{
	dynamic_array = new double[max_count];
	for (int i=0; i<max_count; i++)
	{
		dynamic_array[i] = copy.dynamic_array[i];
	}
}

VectorDouble::~VectorDouble()
{
	delete[] dynamic_array;
}

void VectorDouble::push_back(double new_item)
{
	if ( (count + 1) > max_count ) //we have to make a new larger array
	{
		this->resize(max_count*2);
	}
	
	dynamic_array[count] = new_item;		
	count++;
}

int VectorDouble::capacity()
{
	return max_count;
}

int VectorDouble::size()
{
	return count;
}

int VectorDouble::reserve()
{
	return (max_count - count);
}

void VectorDouble::resize(int new_size)
{
	double *temp = new double[count];
	for (int i=0; i<count; i++)
	{
		temp[i] = dynamic_array[i];
	}
		
	delete[] dynamic_array;
	max_count = new_size;
	dynamic_array = new double[max_count];
	
	if (count < max_count)
	{
		for (int i=0; i<count; i++)
		{
			dynamic_array[i] = temp[i];
		}		
	}
	else
	{
		for (int i=0; i<max_count; i++)
		{
			dynamic_array[i] = temp[i];
		}	
	}
		
	delete[] temp;	
}
	
double VectorDouble::value_at(int index)
{
	if (index < 0 || index > max_count)
	{
		cout << "invalid index";
		throw VECTOR_DOUBLE_INVALID_INDEX;
	}
	else
	{
		return dynamic_array[index];
	}
}

void VectorDouble::change_value_at(int index, double new_item)
{
	if (index < 0 || index > max_count)
	{
		cout << "invalid index";
		exit(1);
	}
	else
	{
		dynamic_array[index] = new_item;
	}
}
