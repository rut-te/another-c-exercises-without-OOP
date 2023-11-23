//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//������� ����� ������ �� ���� �����, ����� ����� �����
#include "Circle.h"

const float P = 3.14;
Circle::Circle(float myRadius):Shape(1)//constuctor
{
	if (myRadius >= 0)
		radius = myRadius;
	else
		radius = 0;
}

Circle::Circle(const Circle& c):Shape(c)//copy constructor
{
	radius = c.radius;
}

bool Circle::isSpecial() const//������� ��������� ������ ������� ���� �����
{
	if (p[0].getX() == 0 && p[0].getY() == 0)//�� ���� ����� ��� 0,0
		return true;
	return false;
}

float Circle::area() const//������� ��������� ������ ��� �����
{
	float area = radius * radius * P;
	return area;
}

void Circle::printSpecial() const//������� ��������� ������ ����� �� ������� �����
{
	if (isSpecial())
		cout << "A canonical circle with a radius " << radius << endl;
}
