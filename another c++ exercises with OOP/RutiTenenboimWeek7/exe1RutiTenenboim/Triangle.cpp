//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//������� ����� ������ �� ���� �����, ����� ����� �����
#include "Triangle.h"

Triangle::Triangle():Shape(3){}//constructor

bool Triangle::isSpecial() const//������� ��������� ������ ������� �����
{
	float side1 = p[0].distance(p[1]);
	float side2 = p[0].distance(p[2]);
	float side3 = p[1].distance(p[2]);
	if (side1 == side2 == side3)//�� ����� ������ ������ ����, ����� ��� ����� ���� �����
		return true;
	return false;
}

float Triangle::area() const//������� ��������� ������ ��� �����
{

	float c = (p[0].distance(p[1]) + p[0].distance(p[2]) + p[1].distance(p[2])) / 2;
	float area = sqrt(c * (c - p[0].distance(p[1])) * (c - p[0].distance(p[2])) * (c - p[1].distance(p[2])));
	return area;
}

void Triangle::printSpecial() const//������� ��������� ������ ������� �����
{
	if (isSpecial())
	{
		float dis=p[0].distance(p[1]);
		cout << "An equilateral triangle with a side length "<<dis << endl;
	}
}

