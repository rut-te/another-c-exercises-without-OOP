//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//������� ����� ������ �� ���� �����, ����� ����� �����
#pragma once
#include "Shape.h"
class Triangle: public Shape
{
public:
	Triangle();//constructor
	virtual bool isSpecial() const override;//������� ��������� ������ ������� �����
	virtual float area() const override;//������� ��������� ������ ��� �����
	virtual void printSpecial() const override;//������� ��������� ������ ������� �����
};

