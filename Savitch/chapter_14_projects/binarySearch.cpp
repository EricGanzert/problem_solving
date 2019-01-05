#include <binarySearch.hpp>

namespace recursive_binary_search
{
	void search(const int a[], int first, int last,
		int key, bool& found, int& location)
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
	
	void search_iter(const int a[], int low_end, int high_end,
		int key, bool& found, int& location)
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
}
