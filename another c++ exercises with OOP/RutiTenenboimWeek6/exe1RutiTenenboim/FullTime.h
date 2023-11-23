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
class FullTime:public Employee
{
private:
	float salaryPerYear;//��� ����
public:
	FullTime();//constructor
	FullTime(string myName, int myId, int mySeniority,float mySalaryPerYear);//parametrize constructor
	FullTime(FullTime& femp);//copy constructor
	void setSalaryPerYear(float mySalaryPerYear);//������� ����� ��� ����
	float getSalaryPerYear();//������� ����� ��� ����
	float salary();//������� ������ ������
	friend ostream& operator<<(ostream& os, FullTime& femp);//������� �����
	friend istream& operator>>(istream& is, FullTime& femp);//������� �����
};

