//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#include "Shape.h"

Shape::Shape()//constructor
{
	numOfPoints = 0;
	p = nullptr;
}

Shape::Shape(int num)//parametrize constructor
{
	numOfPoints = num;
	p = new Point[num];
	cout << "Enter values of  " << num << " points:" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> p[i];
	}
}

Shape::Shape(const Shape& sh)//copy constructor
{
	numOfPoints = sh.numOfPoints;
	p = new Point[numOfPoints];
	for (int i = 0; i < numOfPoints; i++)
	{
		p[i] = sh.p[i];
	}
}

Shape::Shape(Shape&& sh)//move constructor
{
	numOfPoints = sh.numOfPoints;
	p = sh.p;
	sh.p = nullptr;
}

Shape::~Shape()//virtual distructor
{
	if(p)
		delete []p;
}

ostream& operator<<(ostream& os, const Shape& sh)//אופרטור הדפסה
{
	os << "points: ";
	for (int i = 0; i < sh.numOfPoints; i++)
	{
		os << "(" << sh.p[i].getX() << "," << sh.p[i].getY() << ")" << " ";
	}
	return os;
}
