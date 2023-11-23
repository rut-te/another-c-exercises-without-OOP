//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#pragma once
#include "Shape.h"
class Triangle: public Shape
{
public:
	Triangle();//constructor
	virtual bool isSpecial() const override;//פונקציה וירטואלית לבדיקת מיוחדות עיגול
	virtual float area() const override;//פונקציה וירטואלית לחישוב שטח עיגול
	virtual void printSpecial() const override;//פונקציה וירטואלית להדפסת מיוחדות עיגול
};

