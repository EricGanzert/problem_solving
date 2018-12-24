#ifndef FIGURE_H
#define FIGURE_H

namespace figure_eric
{
	class CenterPoint
	{
	public:
		CenterPoint();
		CenterPoint(int the_x, int the_y);
		CenterPoint(const CenterPoint& copy);
		CenterPoint& operator =(const CenterPoint& copy);
		
		friend bool operator ==(const CenterPoint& left, const CenterPoint& right);
	private:
		int x;
		int y;
	};
	
	class Figure
	{
	public:
		Figure();
		void center();
		void erase();
		void draw();
	};
	
	class Rectangle : public Figure
	{
	public:
		Rectangle();
		Rectangle(int the_height, int the_width, CenterPoint the_center);
		Rectangle(const Rectangle& copy);
		Rectangle& operator =(const Rectangle& right);
		
		void center();
		void erase();
		void draw();
		
	private:
		int height;
		int width;
		CenterPoint position;
	};

	class Triangle : public Figure
	{
	public:
		Triangle();
		Triangle(int the_height, int the_width, CenterPoint the_center);
		Triangle(const Triangle& copy);
		Triangle& operator =(const Triangle& right);
		
		void center();
		void erase();
		void draw();
		
	private:
		int height;
		int width;
		CenterPoint position;
	};
}

#endif //FIGURE_H
