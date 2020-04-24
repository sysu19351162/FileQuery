#include<iterator>
#include<string>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include "FileQuery.h"
#include "Shape.h"

using namespace std;

class FileQuery;
class Shape;

int main()
{
	void TestTextQuery();
	void TestShape();


	TestTextQuery();
	TestShape();

	return 0;
}


void TestTextQuery()
{
	FileQuery a("TwoCities.txt");

	a.PrintWordCount();

	a.PrintSentencesOrdered();

	a.PrintSentencesFiltered("the");

	a.ReplaceWord("was", "WAS");

}


void TestShape()
{
	Shape Base1;
	Rectangle rec(3,4);
	Square sq(3);
	Circle c(3);

	Base1.set_area(3);
	cout<<"Base:"<<Base1.get_area()<<endl;

	cout<<"Rectangle:"<<rec.GetArea()<<endl;

	cout<<"Square:"<<sq.GetArea()<<endl;

	cout<<"Circle"<<c.GetArea()<<endl;
}