//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#pragma once
#include "Shape.h"
class Circle: public Shape
{
protected:
	float radius;//רדיוס המעגל
public:
	Circle(float radius);//constuctor
	Circle(const Circle& c);//copy constructor
	virtual bool isSpecial() const override;//פונקציה וירטואלית לבדיקת מיוחדות צורת עיגול
	virtual float area() const override;//פונקציה וירטואלית לחישוב שטח עיגול
	virtual void printSpecial() const override;//פונקציה וירטואלית להדפסה במקרה של מיוחדות עיגול
};

