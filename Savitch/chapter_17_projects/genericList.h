#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H
#include <iostream>

namespace list_eric
{
	class IndexOutOfRangeError {};
	class ArrayFullError {};
	
	template<class T>
	class GenericList
	{
	public:
		GenericList(int max);
		
		~GenericList();
		
		int length() const;
		
		void add(T new_item) throw(ArrayFullError);
		
		bool full() const;
		
		void erase();
		
		template<class U>
		friend std::ostream& operator <<(std::ostream& outs, const GenericList<U>& right);
		
		T get_current_item();
		T increment_current();
		T decrement_current();
		
		T reset_current();
		T get_nth(int n) const throw(IndexOutOfRangeError);
		
	private:
		int max_length;
		int used_length;
		int current_index;
		T* item;
	};
}

#endif //GENERIC_LIST_H
