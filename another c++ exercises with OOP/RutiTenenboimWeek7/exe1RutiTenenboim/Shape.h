//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#pragma once
#include "Point.h";
class Shape
{
protected:
	int numOfPoints;//כמות הנקודות בצורה
	Point* p;//מצביע למערך הנקודות
public:
	Shape();//constructor
	Shape(int num);//parametrize constructor
	Shape(const Shape& sh);//copy constructor
	Shape(Shape&& sh);//move constructor
	virtual ~Shape();//virtual distructor
	friend ostream& operator<<(ostream& os, const Shape& sh);//אופרטור הדפסה
	virtual float area() const = 0;//פונקציה וירטואלית טהורה לחישוב שטח צורה
	virtual bool isSpecial() const = 0;//פונקציה וירטואלית טהורה לבדיקת מיוחדות צורה
	virtual void printSpecial() const = 0;//פונקציה וירטואלית טהורה להדפסת מיוחדות צורה
};

