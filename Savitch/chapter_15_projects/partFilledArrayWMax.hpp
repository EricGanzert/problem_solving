#ifndef PART_FILLED_ARRAY_WMAX_H
#define PART_FILLED_ARRAY_WMAX_H

#include <partFilledArray.hpp>
#include <cstdlib>

class PartFilledArrayWMax : public PartFilledArray
{
public:
	PartFilledArrayWMax(int array_size);
	PartFilledArrayWMax(const PartFilledArrayWMax& copy);
	~PartFilledArrayWMax();
	void operator =(const PartFilledArrayWMax& right_side);
	double get_max();
	void add_value(double new_entry);
	//friend void swap(PartFilledArrayWMax& first, PartFilledArrayWMax& second);
	//There would probably be more member functions
protected:
	double max_value;
};

#endif //PART_FILLED_ARRAY_WMAX_H
