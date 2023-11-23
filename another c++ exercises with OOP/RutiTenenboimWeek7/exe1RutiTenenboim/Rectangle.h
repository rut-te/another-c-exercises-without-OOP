//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#pragma once
#include "Shape.h"
class Rectangle:public Shape
{
public:
	Rectangle();//constructor
	virtual bool isSpecial() const override;//פונקציה וירטואלית לבדיקת מיוחדות מלבן
	virtual float area() const override;//פונקציה וירטואלית לבדיקת שטח מלבן
	virtual void printSpecial() const override;//פונקציה וירטואלית להדפסה במקרה של מיוחדות מלבן

};

