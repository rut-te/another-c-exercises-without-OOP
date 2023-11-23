//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//������� ����� ������ �� ���� �����, ����� ����� �����
#pragma once
#include "Shape.h"
class Circle: public Shape
{
protected:
	float radius;//����� �����
public:
	Circle(float radius);//constuctor
	Circle(const Circle& c);//copy constructor
	virtual bool isSpecial() const override;//������� ��������� ������ ������� ���� �����
	virtual float area() const override;//������� ��������� ������ ��� �����
	virtual void printSpecial() const override;//������� ��������� ������ ����� �� ������� �����
};

