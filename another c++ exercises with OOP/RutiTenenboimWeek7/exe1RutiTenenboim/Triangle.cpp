//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#include "Triangle.h"

Triangle::Triangle():Shape(3){}//constructor

bool Triangle::isSpecial() const//פונקציה וירטואלית לבדיקת מיוחדות עיגול
{
	float side1 = p[0].distance(p[1]);
	float side2 = p[0].distance(p[2]);
	float side3 = p[1].distance(p[2]);
	if (side1 == side2 == side3)//אם שלושת הצלעות במשולש שוות, כלומר הוא משולש שווה צלעות
		return true;
	return false;
}

float Triangle::area() const//פונקציה וירטואלית לחישוב שטח עיגול
{

	float c = (p[0].distance(p[1]) + p[0].distance(p[2]) + p[1].distance(p[2])) / 2;
	float area = sqrt(c * (c - p[0].distance(p[1])) * (c - p[0].distance(p[2])) * (c - p[1].distance(p[2])));
	return area;
}

void Triangle::printSpecial() const//פונקציה וירטואלית להדפסת מיוחדות עיגול
{
	if (isSpecial())
	{
		float dis=p[0].distance(p[1]);
		cout << "An equilateral triangle with a side length "<<dis << endl;
	}
}

