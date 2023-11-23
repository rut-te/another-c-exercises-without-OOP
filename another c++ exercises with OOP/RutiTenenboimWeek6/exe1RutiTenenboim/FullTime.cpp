//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//������� ������ ����� �� ������ ����� ��� ������ 2 ������ �� ��� ���� ������ ������� ������� ��
//������� ������. ������� ����� �������� ����� ���� ������ ����� �� ��� ����� �����
#include "FullTime.h"

FullTime::FullTime()//constructor
{
	Employee();//����� ����
	salaryPerYear = 0;
}

FullTime::FullTime(string myName, int myId, int mySeniority, float mySalaryPerYear)//parametrize constructor
{
	Employee(myName, myId, mySeniority);//����� ����
	if(mySalaryPerYear>0)
		salaryPerYear = mySalaryPerYear;
	else
	{
		throw "ERROR salaryPerYear";
		salaryPerYear = 0;
	}
	setPay(salary());//����� �������� ������� �� �������
}

FullTime::FullTime(FullTime& femp)//copy constructor
{
	Employee &newFemp = femp;//����� ������ ������ ����
	Employee::Employee(newFemp);//����� ����� �� ����
	salaryPerYear = femp.salaryPerYear;//����� ����� �����
}

void FullTime::setSalaryPerYear(float mySalaryPerYear)//������� ����� ��� ����
{
	if (mySalaryPerYear > 0)
		salaryPerYear = mySalaryPerYear;
	else
	{
		throw "ERROR salaryPerYear";
		salaryPerYear = 0;
	}
}

float FullTime::getSalaryPerYear()//������� ����� ��� ����
{
	return salaryPerYear;
}

float FullTime::salary()//������� ������ ������
{
	float salaryPerMonth = salaryPerYear / 12;
	return salaryPerMonth;
}

ostream& operator<<(ostream& os, FullTime& femp)//������� �����
{
	os << "Employee: " << femp.getName() << endl;
	os << "Employee ID: " << femp.getId() << endl;
	os << "Years Seniority: " << femp.getSeniority() << endl;
	os << "Salary per Month:: " << femp.salary() << endl;
	return os;
}

istream& operator>>(istream& is, FullTime& femp)//������� �����
{
	string myName;
	int myId, mySeniority;
	float mySalaryPerYear;
	cout << "Enter employee details :" << endl;
	is >> myName;
	femp.setName(myName);
	is >> myId;
	femp.setId(myId);
	is >> mySeniority;
	femp.setSeniority(mySeniority);
	is >> mySalaryPerYear;
	femp.setSalaryPerYear(mySalaryPerYear);
	femp.setPay(femp.salary());
	return is;
}
