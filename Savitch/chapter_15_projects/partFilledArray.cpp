#include <partFilledArray.hpp>
#include <iostream>

PartFilledArray::PartFilledArray(int array_size)
	: max_number(array_size), number_used(0)
{
	a = new double[max_number];
}

PartFilledArray::PartFilledArray(const PartFilledArray& copy)
	: max_number(copy.max_number), number_used(copy.number_used)
{
	a = new double[copy.max_number];
	for (int i=0; i<copy.number_used; i++)
	{
		a[i] = copy.a[i];
	}
}

PartFilledArray::~PartFilledArray()
{
	delete[] a;
}

void PartFilledArray::add_value(double new_entry)
{
	if (number_used == max_number)
	{
		std::cout << "Error: adding to a full array\n";
	}
	else
	{
		a[number_used] = new_entry;
		number_used++;
	}
}

void PartFilledArray::operator =(const PartFilledArray& right_side)
{
	PartFilledArray temp(right_side);
	swap(*this, temp);
}

void swap(PartFilledArray& first, PartFilledArray& second)
{
	int temp_max_num = first.max_number;
	double* temp_array = first.a;
	
	first.max_number = second.max_number;
	first.a = second.a;
	
	second.max_number = temp_max_num;
	second.a = temp_array;
}
