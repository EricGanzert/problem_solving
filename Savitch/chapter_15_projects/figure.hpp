#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include <iostream>

namespace figure_eric
{
	class Point
	{
	public:
		Point();
		Point(int the_x, int the_y);
		Point(const Point& copy);
		Point& operator =(const Point& copy);
		
		friend std::ostream& operator <<(std::ostream& outs, const Point& right);
		
		friend bool operator ==(const Point& left, const Point& right);
		void set_x(int new_x);
		int get_x();
		void set_y(int new_y);
		int get_y();
		
	private:
		int x;
		int y;
	};
	
	class Figure
	{
	public:
		Figure();
		virtual void center();
		virtual void erase();
		virtual void draw();
		void display(const std::vector<Point>& marked);
	};
	
	class Rectangle : public Figure
	{
	public:
		Rectangle();
		Rectangle(int the_height, int the_width, Point the_center);
		Rectangle(const Rectangle& copy);
		Rectangle& operator =(const Rectangle& right);
		
		virtual void center();
		virtual void erase();
		virtual void draw();
		
	private:
		int height;
		int width;
		Point position;
	};

	class Triangle : public Figure
	{
	public:
		Triangle();
		Triangle(int the_height, int the_width, Point the_center);
		Triangle(const Triangle& copy);
		Triangle& operator =(const Triangle& right);
		
		virtual void center();
		virtual void erase();
		virtual void draw();
		
	private:
		int height;
		int width;
		Point position;
	};
}

#endif //FIGURE_H
