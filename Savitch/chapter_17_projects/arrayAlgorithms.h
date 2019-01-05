#ifndef ARRAY_ALGORITHMS_H
#define ARRAY_ALGORITHMS_H
#include <iostream>

namespace arr_alg_eric
{
	template<class T>
	int find(T target, T array[], int num_used)
	{
		int result = -1;
		
		for (int index=0; index<num_used; index++)
		{
			if (target == array[index])
			{
				result = array[index];
				break;
			}
		}
		return result;
	}
	
	template<class T>
	void delete_repeats(T array[], int& num_used)
	{
		for (int i=0; i<num_used; i++)
		{
			for (int j=0; j<num_used; j++)
			{
				if (i!=j && array[i] == array[j])
				{
					//shift all entries back one, overwriting the duplicate
					for(int k=j; k<num_used-1; k++)
					{
						array[k] = array[k+1];
					}
					num_used--;
				}
			}			
		}
	}
	
	//type used must support < and =
	template<class T>
	void insertion_sort(T array[], int num_used)
	{
		for (int i=0; i<num_used; i++)
		{
			int place_index = 0;
			while (place_index < i)
			{
				if (array[i] < array[place_index])
				{
					//push them all forward by 1
					T temp = array[i];
					int k=i;
					while (k>place_index)
					{
						array[k] = array[k-1];
						k--;
					}
					//std::cout << "(k, place_index)" << "(" << k << ", " << place_index << ")\n";
					array[place_index] = temp;
					break;
				}
				place_index++;
			}
		}
	}
	
	//type used must support <, =, ==
	template<class T>
	void search_iter(const T a[], int low_end, int high_end,
		T key, bool& found, int& location)
	{
		int first = low_end;
		int last = high_end;
		int mid;
		
		found = false;
		while (first <= last && !found)
		{
			mid = (first + last) / 2;
			if (key == a[mid])
			{
				found = true;
				location = mid;
			}
			else if (key < a[mid])
			{
				last = mid-1;
			}
			else if (key > a[mid])
			{
				first = mid+1;
			}
		}
	}
	
	//type used must support <, =, ==
	template<class T>
	void search(const T a[], int first, int last,
		T key, bool& found, int& location)
	{
		found = false;
		int mid;
		if (first > last)
		{
			return;
		}
		else
		{
			mid = (first + last) / 2;
			
			if (key == a[mid])
			{
				found = true;
				location = mid;
				return;
			}
			else
			{
				if (key < a[mid])
				{
					search(a, first, mid-1, key, found, location);
				}
				else if (key > a[mid])
				{
					search(a, mid+1, last, key, found, location);
				}
			}
		}
	}
}
#endif //ARRAY_ALGORITHMS_H
