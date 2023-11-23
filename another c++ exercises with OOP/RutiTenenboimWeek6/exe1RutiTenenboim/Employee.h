//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//������� ������ ����� �� ������ ����� ��� ������ 2 ������ �� ��� ���� ������ ������� ������� ��
//������� ������. ������� ����� �������� ����� ���� ������ ����� �� ��� ����� �����
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Employee
{
private:
	string name;//�� �����
	int id;//����� ����
	int seniority;//���� ����
	float pay;//��� �����
public:
	Employee();//constructor
	Employee(string myName, int myId, int mySeniority);//parametrize constructor
	Employee(Employee& emp);//copy constructor
	void setName(string myName);//������� ������ �� �����
	void setId(int myId);//������� ������ ����� ����
	void setSeniority(int mySeniority);//������� ������ ����
	string getName();//������� ����� �� �����
	int getId();//������� ����� ����� ����
	int getSeniority();//������� ����� ����
	float getPay();//������� ����� ��� 
	float salaryAfterBonus();//������� ������ ��� ���� ������
	friend ostream& operator<<(ostream& os, const Employee& emp);//������� �����
	friend istream& operator>>(istream& is, Employee& emp);//������� �����
protected:
	void setPay(float myPay);//������� ����� ��� �����
};

