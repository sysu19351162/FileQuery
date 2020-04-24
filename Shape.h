#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
	Shape();

	void set_area(int a);

	int get_area();

private:
	int area_;

};

class Circle :public Shape
{
public:
	Circle();

	Circle(int radius);

	int GetArea();
private:
	int r;								//record the radius of the circle
};

class Rectangle:public Shape
{
public:
	Rectangle();

	Rectangle(int x, int y);

	int GetArea();

private:
	int len;								//record the length of the Rectangle

	int wid;								//record the width of the Rectangle

};

class Square :public Rectangle
{
public:
	Square();

	Square(int l);

	int GetArea();

private:
	int len;							//record the length of the square
};
#endif