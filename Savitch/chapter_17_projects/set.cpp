#ifndef SET_CPP
#define SET_CPP
#include <set.h>
#include <cstdint>
using namespace std;

namespace set_eric
{
	template<class T>
	Set<T>::Set()
	{
		//empty
	}
	
	template<class T>
	Set<T>::~Set()
	{
		items.clear();
	}
	
	template<class T>
	void Set<T>::add(T new_item)
	{
		if (!has_item(new_item))
		{
			items.push_back(new_item);
		}
	}
	
	template<class T>
	T Set<T>::get_item(int index)
	{
		return items[index];
	}
	
	template<class T>
	void Set<T>::remove(T remove_this)
	{
		for (uint32_t i=0;i<items.size();i++)
		{
			if (items[i] == remove_this)
			{
				items.erase(items.begin() + i);
			}
		}
	}
	
	template<class T>
	bool Set<T>::has_item(T the_item)
	{
		for (uint32_t i=0; i<items.size(); i++)
		{
			if (items[i] == the_item)
			{
				return true;
			}
		}
		return false;
	}
	
	template<class T>
	int Set<T>::num_items()
	{
		return items.size();
	}
	
	template<class T>	
	T* Set<T>::get_array()
	{
		T* result = new T[items.size()];
		for (uint32_t i=0;i<items.size();i++)
		{
			result[i] = items[i];
		}
		return result;
	}
}

#endif //SET_CPP
