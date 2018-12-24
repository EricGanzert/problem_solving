#include <figure.hpp>
#include <iostream>
using namespace std;

namespace figure_eric
{
	
	CenterPoint::CenterPoint() : x(0), y(0)
	{
		//empty
	}
	
	CenterPoint::CenterPoint(int the_x, int the_y) : x(the_x), y(the_y)
	{
		//empty
	}
	
	CenterPoint::CenterPoint(const CenterPoint& copy)
		: x(copy.x), y(copy.y)
	{
		//empty
	}
	
	CenterPoint& CenterPoint::operator =(const CenterPoint& right)
	{
		x = right.x;
		y = right.y;
		return *this;
	}
		
	bool operator ==(const CenterPoint& left, const CenterPoint& right)
	{
		return (left.x == right.x && left.y == right.y);
	}
	
	Figure::Figure()
	{
		//empty
	}
	
	void Figure::center()
	{
		cout << "Center in Figure class\n";
		erase();
		draw();
	}
	
	void Figure::erase()
	{
		cout << "Erase in Figure class\n";
	}
	
	void Figure::draw()
	{
		cout << "Draw in Figure class\n";
	}
	
	Rectangle::Rectangle() : height(0), width(0)
	{
		//empty
	}
	
	Rectangle::Rectangle(int the_height, int the_width, CenterPoint the_center)
		: height(the_height), width(the_width), position(the_center)
	{
		//empty
	}
	
	Rectangle::Rectangle(const Rectangle& copy)
		: height(copy.height), width(copy.width), position(copy.position)
	{
		//empty
	}
	
	Rectangle& Rectangle::operator =(const Rectangle& right)
	{
		height = right.height;
		width = right.width;
		position = right.position;
		return *this;
	}
	
	void Rectangle::center()
	{
		cout << "Center in Figure class\n";
		erase();
		draw();
	}
	
	void Rectangle::erase()
	{
		cout << "Erase in Rectangle class\n";
	}
	
	void Rectangle::draw()
	{
		cout << "Draw in Rectangle class\n";
	}

	Triangle::Triangle() : height(0), width(0)
	{
		//empty
	}
	
	Triangle::Triangle(int the_height, int the_width, CenterPoint the_center)
		: height(the_height), width(the_width), position(the_center)
	{
		//empty
	}
	
	Triangle::Triangle(const Triangle& copy) : height(copy.height), width(copy.width), position(copy.position)
	{
		//empty
	}
	
	Triangle& Triangle::operator =(const Triangle& right)
	{
		height = right.height;
		width = right.width;
		position = right.position;
		return *this;
	}

	void Triangle::center()
	{
		cout << "Center in Triangle class\n";
		erase();
		draw();
	}
		
	void Triangle::erase()
	{
		cout << "Erase in Triangle class\n";
	}
	
	void Triangle::draw()
	{
		cout << "Draw in Triangle class\n";
	}	
}
