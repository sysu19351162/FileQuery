#include<iostream>
#include"Shape.h"

Shape::Shape():area_(0){}


void Shape::set_area(int a)//设置面积
{
	area_ = a;
}


int Shape::get_area()		//读取面积
{
	return area_;
}


Circle::Circle():r(0)		//构造
{
	set_area(3.14 * r * r);
}

Circle::Circle(int radius) : r(radius)//构造
{
	set_area(3.14 * r * r);
}

int Circle::GetArea()//读取面积
{
	return get_area();
}


Rectangle::Rectangle():len(0),wid(0)//构造
{
	set_area(len * wid);
}


Rectangle::Rectangle(int x, int y) :len(x), wid(y)//构造
{
	set_area(len * wid);
}


int Rectangle::GetArea()//读取面积
{
	return get_area();
}


Square::Square() :len(0)//构造
{
	set_area(len * len);
}


Square::Square(int l) : len(l)//构造
{
	set_area(len * len);
}


int Square::GetArea()//读取面积
{
	return get_area();
}