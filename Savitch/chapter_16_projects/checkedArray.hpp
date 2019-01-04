#ifndef CHECKED_ARRAY_H
#define CHECKED_ARRAY_H
#include <iostream>

namespace checked_array_eric
{
	class ArrayOutOfRangeError {};
	
	class CheckedArray
	{
	public:
		CheckedArray();
		CheckedArray(int the_size);
		CheckedArray(const CheckedArray& copy);
		~CheckedArray();
		
		CheckedArray& operator =(const CheckedArray& right);
		
		int& operator [](int the_index) throw(ArrayOutOfRangeError);
		
		int get_size() const;
		void set_size(int new_size);
		
	private:
		int size;
		int* array;
	};
	
	class CheckedArray2D
	{
	public:
		CheckedArray2D();
		CheckedArray2D(int x, int y);
		CheckedArray2D(const CheckedArray2D& copy);
		~CheckedArray2D();
		
		CheckedArray2D& operator =(const CheckedArray2D& right);
		
		friend std::ostream& operator <<(std::ostream& outs, const CheckedArray2D& right);
		
		int get_element(int x, int y) const;
		void set_element(int x, int y, int new_element);
		
		int get_size_x() const;
		int get_size_y() const;
		
	private:
		int size_x;
		int size_y;
		int* array;
	};
}

#endif //CHECKED_ARRAY_H
