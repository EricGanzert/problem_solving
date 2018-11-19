#ifndef LIST_H
#define LIST_H
#include <iostream>

const int MAX_LIST_SIZE = 50;

class List
{
public:
	List();
	void add_item(double new_item);
	bool full() const;
	int get_size() const;
	double get_item(int index);
	double get_last() const;
	void delete_last();
	
	friend std::ostream& operator <<(std::ostream& outs,
		const List& the_object);

private:
	double list[MAX_LIST_SIZE];
	int size;
};

#endif //LIST_H
