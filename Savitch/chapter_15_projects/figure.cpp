#include <figure.hpp>
#include <iostream>
using namespace std;

namespace
{
	bool find(figure_eric::Point point, vector<figure_eric::Point> vec)
	{
		for (vector<figure_eric::Point>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			if (point == *it)
			{
				return true;
			}
		}
		return false;
	}
}

namespace figure_eric
{
	
	Point::Point() : x(0), y(0)
	{
		//empty
	}
	
	Point::Point(int the_x, int the_y) : x(the_x), y(the_y)
	{
		//empty
	}
	
	Point::Point(const Point& copy)
		: x(copy.x), y(copy.y)
	{
		//empty
	}
	
	Point& Point::operator =(const Point& right)
	{
		x = right.x;
		y = right.y;
		return *this;
	}
		
	bool operator ==(const Point& left, const Point& right)
	{
		return (left.x == right.x && left.y == right.y);
	}
	
	ostream& operator <<(ostream& outs, const Point& right)
	{
		outs << "(" << right.x << ", " << right.y << ")";
		return outs;
	}
	
	void Point::set_x(int new_x)
	{
		x = new_x;
	}
	
	int Point::get_x()
	{
		return x;
	}
	
	void Point::set_y(int new_y)
	{
		y = new_y;
	}
	
	int Point::get_y()
	{
		return y;
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
	
	void Figure::display(const vector<Point>& marked)
	{
		int x=0;
		int y=25;
		while(y >= 0)
		{
			x = 0;
			while (x < 50)
			{
				Point p(x,y);
				if (find(p, marked))
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
				x++;
			}
			cout << "\n";
			y--;
		}		
	}
	
	Rectangle::Rectangle() : height(0), width(0)
	{
		//empty
	}
	
	Rectangle::Rectangle(int the_height, int the_width, Point the_center)
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
		cout << "Center in Rectangle class\n";
		erase();
		draw();
	}
	
	void Rectangle::erase()
	{
		cout << "Erase in Rectangle class\n";
		vector<Point> marked; //no points marked with *
		display(marked);
	}
	
	void Rectangle::draw()
	{
		cout << "Draw in Rectangle class\n";
		std::vector<Point> marked;
		marked.push_back(position);
		
		Point current = position;
		for (int i=0; i<height; i++)
		{
			current.set_y(current.get_y() + 1);
			marked.push_back(current);
			marked.push_back(Point(current.get_x() + width, current.get_y()));
		}
		
		for (int i=0; i<width; i++)
		{
			current.set_x(current.get_x() + 1);
			marked.push_back(current);
			marked.push_back(Point(current.get_x(), current.get_y() - height));
		}
		
		display(marked);
	}

	Triangle::Triangle() : height(0), width(0)
	{
		//empty
	}
	
	Triangle::Triangle(int the_height, int the_width, Point the_center)
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
		vector<Point> marked; //no points marked with *
		display(marked);
	}
	
	void Triangle::draw()
	{
		cout << "Draw in Triangle class\n";
		std::vector<Point> marked;
		marked.push_back(position);
		
		Point current = position;
		
		for (int i=0; i<width; i++)
		{
			current.set_x(current.get_x() + 1);
			marked.push_back(current);
		}
		current = position;
		current.set_x(position.get_x() + width/2);
		current.set_y(position.get_y() + height);
		
		marked.push_back(current);
		//get equation for diagonal line, positive slope
		Point left_corner(position);
		Point top_peak(current);
		double slope, intercept;
		slope = (top_peak.get_y() - left_corner.get_y()) / static_cast<double>(top_peak.get_x() - left_corner.get_x());
		intercept = left_corner.get_y() - slope*left_corner.get_x();
		
		while (current.get_y() > position.get_y())
		{
			current.set_y(current.get_y() - 1);
			int distance_from_center = abs(static_cast<int>(top_peak.get_x() - ((current.get_y()-intercept) / slope)));
			current.set_x( top_peak.get_x() - distance_from_center);
			//~ current.set_x((current.get_y()-intercept) / slope);
			marked.push_back(current);
			current.set_x( top_peak.get_x() + distance_from_center);
			marked.push_back(current);
		}
		display(marked);
	}	
}
