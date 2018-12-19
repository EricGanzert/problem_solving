#ifndef BINARY_SEARCH
#define BINARY_SEARCH

namespace recursive_binary_search
{
	void search(const int a[], int first, int last,
		int key, bool& found, int& location);
		
	void search_iter(const int a[], int low_end, int high_end,
		int key, bool& found, int& location);
}

#endif //BINARY_SEARCH
