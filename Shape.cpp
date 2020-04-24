#include<iostream>
#include"Shape.h"

Shape::Shape():area_(0){}


void Shape::set_area(int a)//�������
{
	area_ = a;
}


int Shape::get_area()		//��ȡ���
{
	return area_;
}


Circle::Circle():r(0)		//����
{
	set_area(3.14 * r * r);
}

Circle::Circle(int radius) : r(radius)//����
{
	set_area(3.14 * r * r);
}

int Circle::GetArea()//��ȡ���
{
	return get_area();
}


Rectangle::Rectangle():len(0),wid(0)//����
{
	set_area(len * wid);
}


Rectangle::Rectangle(int x, int y) :len(x), wid(y)//����
{
	set_area(len * wid);
}


int Rectangle::GetArea()//��ȡ���
{
	return get_area();
}


Square::Square() :len(0)//����
{
	set_area(len * len);
}


Square::Square(int l) : len(l)//����
{
	set_area(len * len);
}


int Square::GetArea()//��ȡ���
{
	return get_area();
}