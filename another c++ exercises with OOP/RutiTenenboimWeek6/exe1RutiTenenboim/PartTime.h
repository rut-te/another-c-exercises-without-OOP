//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//������� ������ ����� �� ������ ����� ��� ������ 2 ������ �� ��� ���� ������ ������� ������� ��
//������� ������. ������� ����� �������� ����� ���� ������ ����� �� ��� ����� �����
#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;
class PartTime :public Employee
{
private:
	int hoursOfWork;//���� ���� ������
	float payPerHour;//��� ����
public:
	PartTime();//costructor
	PartTime(string myName, int myId, int mySeniority, int myHoursOfWork, float myPayPerHour);//parametrize constructor
	PartTime(PartTime& femp);//copy constructor
	void setHoursOfWork(int myHoursOfWork);//������� ����� ���� ���� �����
	int getHoursOfWork();//������� ����� ���� ���� �����
	void setPayPerHour(float myPayPerHour);//������� ����� ��� ����
	float getPayPerHour();//������� ����� ��� ����
	float salary();//������� ������ ������
	friend ostream& operator<<(ostream& os,  PartTime& pemp);//������� �����
	friend istream& operator>>(istream& is, PartTime& femp);//������� �����
};

