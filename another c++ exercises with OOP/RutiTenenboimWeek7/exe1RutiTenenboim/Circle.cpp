//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#include "Circle.h"

const float P = 3.14;
Circle::Circle(float myRadius):Shape(1)//constuctor
{
	if (myRadius >= 0)
		radius = myRadius;
	else
		radius = 0;
}

Circle::Circle(const Circle& c):Shape(c)//copy constructor
{
	radius = c.radius;
}

bool Circle::isSpecial() const//פונקציה וירטואלית לבדיקת מיוחדות צורת עיגול
{
	if (p[0].getX() == 0 && p[0].getY() == 0)//אם מרכז המעגל הוא 0,0
		return true;
	return false;
}

float Circle::area() const//פונקציה וירטואלית לחישוב שטח עיגול
{
	float area = radius * radius * P;
	return area;
}

void Circle::printSpecial() const//פונקציה וירטואלית להדפסה במקרה של מיוחדות עיגול
{
	if (isSpecial())
		cout << "A canonical circle with a radius " << radius << endl;
}
