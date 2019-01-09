#ifndef SET_H
#define SET_H
#include <vector>

namespace set_eric
{
	template<class T>
	class Set
	{
	public:
		Set();
		~Set();
		void add(T new_item);
		void remove(T remove_this);
		bool has_item(T the_item);
		T get_item(int index);
		int num_items();
		
		T* get_array();
	private:
		std::vector<T> items;
	};
}

#endif //SET_H
