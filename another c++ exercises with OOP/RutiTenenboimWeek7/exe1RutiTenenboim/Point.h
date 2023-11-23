//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#pragma once
#include <iostream>
using namespace std;
class Point
{
private:
	int x;//the x value of the point
	int y;//the y value of the point
public:
	Point(int myX = 0, int myY = 0);//constructor
	Point(const Point& temp);//copy constructor
	int getX();//A method to return the X value
	void setX(int myX);//Method for placement in X
	int getY();//A method to return the Y value
	void setY(int myY);//Method for placement in Y
	float distance(Point p1);//A method for calculating the distance between 2 points
	friend istream& operator>>(istream& is, Point& p);//reading operator
};



