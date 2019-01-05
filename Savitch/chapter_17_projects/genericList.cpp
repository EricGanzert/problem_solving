#ifndef GENERIC_LIST_CPP
#define GENERIC_LIST_CPP

#include <iostream>
#include <cstdlib>
#include <genericList.h>
using namespace std;

namespace list_eric
{
	template<class T>
	GenericList<T>::GenericList(int max): max_length(max), used_length(0), current_index(0)
	{
		item = new T[max_length];
	}
	
	template<class T>
	GenericList<T>::~GenericList()
	{
		delete [] item;
	}

	template<class T>
	int GenericList<T>::length() const
	{
		return used_length;
	}
	
	template<class T>
	void GenericList<T>::add(T new_item) throw(ArrayFullError)
	{
		if (full())
		{
			throw(ArrayFullError());
		}
		else
		{
			item[used_length] = new_item;
			used_length = used_length + 1;
		}
	}
	
	template<class T>
	bool GenericList<T>::full() const
	{
		return used_length == max_length;
	}
	
	template<class T>
	void GenericList<T>::erase()
	{
		used_length = 0;
		current_index = 0;
	}
	
	template<class T>
	ostream& operator <<(ostream& outs, const GenericList<T>& right)
	{
		for (int i=0; i<right.used_length; i++)
		{
			outs << right.item[i] << "\n";
		}
		return outs;
	}
	
	template<class T>
	T GenericList<T>::get_current_item()
	{
		return item[current_index];
	}
	
	template<class T>
	T GenericList<T>::increment_current()
	{
		if (!(current_index == max_length))
		{
			current_index++;
		}
		return item[current_index];
	}
	
	template<class T>
	T GenericList<T>::decrement_current()
	{
		if (!(current_index == 0))
		{
			current_index--;
		}
		return item[current_index];
	}
	
	template<class T>
	T GenericList<T>::reset_current()
	{
		current_index = 0;
		return item[current_index];
	}
	
	template<class T>
	T GenericList<T>::get_nth(int n) const throw(IndexOutOfRangeError)
	{
		if (n < 0 || n >= max_length)
		{
			throw (IndexOutOfRangeError());
		}
		else
		{
			return item[n];
		}
	}

	template<class T>
	int find(T target, const GenericList<T>& list)
	{
		int result = -1;
		
		for (int index=0; index<list.length(); index++)
		{
			if (target == list.get_nth(index))
			{
				result = index;
				break;
			}
		}
		return result;
	}
}

#endif //GENERIC_LIST_H
