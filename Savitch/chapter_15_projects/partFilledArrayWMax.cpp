#include <partFilledArrayWMax.hpp>

PartFilledArrayWMax::PartFilledArrayWMax(int array_size) : PartFilledArray(array_size), max_value(0)
{
	//empty
}

PartFilledArrayWMax::PartFilledArrayWMax(const PartFilledArrayWMax& copy)
	: PartFilledArray(copy), max_value(copy.max_value)
{
	//empty
}

PartFilledArrayWMax::~PartFilledArrayWMax()
{
	//empty
}

void PartFilledArrayWMax::operator =(const PartFilledArrayWMax& right_side)
{
	PartFilledArrayWMax temp(right_side);
	swap(*this, temp);
}

double PartFilledArrayWMax::get_max()
{
	return max_value;
}

void PartFilledArrayWMax::add_value(double new_entry)
{
	PartFilledArray::add_value(new_entry);
	if (new_entry > max_value)
	{
		max_value = new_entry;
	}
}
