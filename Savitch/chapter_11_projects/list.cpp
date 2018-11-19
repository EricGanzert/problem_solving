#include <list.hpp>
using namespace std;

List::List() : size(0)
{
	//empty
}

void List::add_item(double new_item)
{
	if (full())
	{
		cout << "Error: adding to a full list\n";
		exit(1);
	}
	else
	{
		list[size] = new_item;
		size += 1;
	}
}

bool List::full() const
{
	return (size == MAX_LIST_SIZE);
}

int List::get_size() const
{
	return size;
}

double List::get_item(int index)
{
	if (index < 0 || index > size-1)
	{
		cout << "Error: index out of range\n";
		exit(1);
	}
	else
	{
		return list[index];
	}
}

double List::get_last() const
{
	if (size == 0)
	{
		cout << "Error: list is empty\n";
	}
	else
	{
		return list[size];
	}
}

void List::delete_last()
{
	if (size != 0)
	{
		size--;
	}
}

ostream& operator <<(ostream& outs, const List& the_object)
{
	for (int i=0; i < the_object.size; i++)
	{
		outs << the_object.list[i] << "\n";
	}
	return outs;
}
