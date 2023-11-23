//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#include "Rectangle.h"

Rectangle::Rectangle() :Shape(4) {}//constructor

bool Rectangle::isSpecial() const//פונקציה וירטואלית לבדיקת מיוחדות מלבן
{
	float side1 = p[0].distance(p[1]);
	float side2 = p[1].distance(p[2]);
	if (side1 == side2)//אם שתי צלעות סמוכות שוות כלומר המלבן בוא ריבוע
		return true;
	return false;
}

float Rectangle::area() const//פונקציה וירטואלית לבדיקת שטח מלבן
{
	float area = p[0].distance(p[1]) * p[1].distance(p[2]);
	return area;
}

void Rectangle::printSpecial() const//פונקציה וירטואלית להדפסה במקרה של מיוחדות מלבן
{
	if (isSpecial())
	{
		float side = p[0].distance(p[1]);
		cout << "Square with side length " << side << endl;
	}
}

