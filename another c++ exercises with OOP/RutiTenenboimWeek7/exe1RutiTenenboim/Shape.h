//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//������� ����� ������ �� ���� �����, ����� ����� �����
#pragma once
#include "Point.h";
class Shape
{
protected:
	int numOfPoints;//���� ������� �����
	Point* p;//����� ����� �������
public:
	Shape();//constructor
	Shape(int num);//parametrize constructor
	Shape(const Shape& sh);//copy constructor
	Shape(Shape&& sh);//move constructor
	virtual ~Shape();//virtual distructor
	friend ostream& operator<<(ostream& os, const Shape& sh);//������� �����
	virtual float area() const = 0;//������� ��������� ����� ������ ��� ����
	virtual bool isSpecial() const = 0;//������� ��������� ����� ������ ������� ����
	virtual void printSpecial() const = 0;//������� ��������� ����� ������ ������� ����
};

