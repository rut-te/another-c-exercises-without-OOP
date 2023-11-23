//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//������� ����� ������ �� ���� �����, ����� ����� �����
#include "Rectangle.h"

Rectangle::Rectangle() :Shape(4) {}//constructor

bool Rectangle::isSpecial() const//������� ��������� ������ ������� ����
{
	float side1 = p[0].distance(p[1]);
	float side2 = p[1].distance(p[2]);
	if (side1 == side2)//�� ��� ����� ������ ���� ����� ����� ��� �����
		return true;
	return false;
}

float Rectangle::area() const//������� ��������� ������ ��� ����
{
	float area = p[0].distance(p[1]) * p[1].distance(p[2]);
	return area;
}

void Rectangle::printSpecial() const//������� ��������� ������ ����� �� ������� ����
{
	if (isSpecial())
	{
		float side = p[0].distance(p[1]);
		cout << "Square with side length " << side << endl;
	}
}

