#ifndef PART_FILLED_ARRAY_H
#define PART_FILLED_ARRAY_H

#include <cstdlib>

class PartFilledArray
{
public:
	PartFilledArray(int array_size);
	PartFilledArray(const PartFilledArray& copy);
	~PartFilledArray();
	void operator =(const PartFilledArray& right_side);
	void add_value(double new_entry);
	
	friend void swap(PartFilledArray& first, PartFilledArray& second);
	//There would probably be more member functions
protected:
	double *a;
	int max_number;
	int number_used;
};

#endif //PART_FILLED_ARRAY_H
