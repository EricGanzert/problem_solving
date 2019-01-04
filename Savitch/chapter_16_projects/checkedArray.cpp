#include <checkedArray.hpp>
#include <iomanip>
using namespace std;

namespace
{
	using namespace checked_array_eric;
	
	void swap_2d_array(int* a, int* b)
	{
		int* temp = b;
		b = a;
		a = temp;
	}
}

namespace checked_array_eric
{
	CheckedArray::CheckedArray() : size(100)
	{
		array = new int[size];
	}
	
	CheckedArray::CheckedArray(int the_size) : size(the_size)
	{
		array = new int[size];
	}
	
	CheckedArray::CheckedArray(const CheckedArray& copy) : size(copy.size)
	{
		array = new int[size];
		
		for (int i=0; i<size; i++)
		{
			array[i] = copy.array[i];
		}
	}
	
	CheckedArray::~CheckedArray()
	{
		delete[] array;
	}
		
	CheckedArray& CheckedArray::operator =(const CheckedArray& right)
	{
		if (size != right.size)
		{
			delete[] array;
			array = new int[right.size];
		}
		size = right.size;
		
		for (int i=0; i<size; i++)
		{
			array[i] = right.array[i];
		}
		return *this;
	}
	
	int CheckedArray::get_size() const
	{
		return size;
	}
	
	void CheckedArray::set_size(int new_size)
	{
		if (size == new_size)
		{
			return;
		}
		
		int old_size = size;
		int* temp = array;
		
		size = new_size;
		array = new int[size];
		
		for (int i=0; i<old_size; i++)
		{
			array[i] = temp[i];
		}
		delete[] temp;
	}
		
	int& CheckedArray::operator [](int the_index) throw(ArrayOutOfRangeError)
	{
		if (the_index < 0 || the_index >= size)
		{
			throw(ArrayOutOfRangeError());
		}
		return array[the_index];
	}

	CheckedArray2D::CheckedArray2D() : size_x(100), size_y(100)
	{
		array = new int[size_x*size_y];
	}
	
	CheckedArray2D::CheckedArray2D(int x, int y) : size_x(x), size_y(y)
	{
		array = new int[size_x*size_y];		
	}
		
	CheckedArray2D::CheckedArray2D(const CheckedArray2D& copy) : size_x(copy.size_x), size_y(copy.size_y) 
	{
		array = new int[size_x*size_y];
		for (int i=0; i<size_x*size_y; i++)
		{
			array[i] = copy.array[i];
		}
	}
	
	CheckedArray2D::~CheckedArray2D()
	{
		delete[] array;
	}
		
	CheckedArray2D& CheckedArray2D::operator =(const CheckedArray2D& right)
	{
		size_x = right.size_x;
		size_y = right.size_y;
		CheckedArray2D temp(right);
		
		swap_2d_array(array, temp.array);
		
		delete &temp;
		return *this;
	}
	
	ostream& operator <<(ostream& outs, const CheckedArray2D& right)
	{
		int size_x = right.size_x;
		int size_y = right.size_y;
		
		for (int y = size_y-1; y>=0; y--)
		{
			for (int x=0; x<size_x; x++)
			{
				cout << right.get_element(x,y) << " ";
			}
			cout << "\n";
		}
		return outs;
	}
		
	int CheckedArray2D::get_element(int x, int y) const
	{
		if (x < 0 || x >= size_x || y < 0 || y >= size_y)
		{
			throw ArrayOutOfRangeError();
		}
		return array[y*size_y + x];
	}
	
	void CheckedArray2D::set_element(int x, int y, int new_element)
	{
		if (x < 0 || x >= size_x || y < 0 || y >= size_y)
		{
			throw ArrayOutOfRangeError();
		}
		array[y*size_y + x] = new_element;
	}
		
	int CheckedArray2D::get_size_x() const
	{
		return size_x;
	}
	
	int CheckedArray2D::get_size_y() const
	{
		return size_y;
	}
}
