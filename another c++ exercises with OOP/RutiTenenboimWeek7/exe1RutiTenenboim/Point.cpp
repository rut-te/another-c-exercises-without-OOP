//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#include "Point.h"
#include <cmath>

Point::Point(int myX, int myY)//constructor
{
	x = myX;
	y = myY;
}

Point::Point(const Point& temp)//copy constructor
{
	x = temp.x;
	y = temp.y;
}

int Point::getX()//A method to return the X value
{
	return x;
}

void Point::setX(int myX)//Method for placement in X
{
	x = myX;
}

int Point::getY()//A method to return the Y value
{
	return y;
}

void Point::setY(int myY)//Method for placement in Y
{
	y = myY;
}

float Point::distance(Point p1)//A method for calculating the distance between 2 points
{
	float d = sqrt(pow((x - p1.getX()), 2) + pow((y - p1.getY()), 2));
	return d;
}

istream& operator>>(istream& is,  Point& p)
{
	int myX, myY;
	char tav;
	is >> tav >> myX >> tav >> myY >> tav;
	p.setX(myX);
	p.setY(myY);
	return is;

}
