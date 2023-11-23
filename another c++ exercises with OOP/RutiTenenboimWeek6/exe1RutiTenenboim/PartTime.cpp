//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//������� ������ ����� �� ������ ����� ��� ������ 2 ������ �� ��� ���� ������ ������� ������� ��
//������� ������. ������� ����� �������� ����� ���� ������ ����� �� ��� ����� �����
#include "PartTime.h"

PartTime::PartTime()//constructor
{
	Employee();//����� ����
	hoursOfWork = 0;
	payPerHour = 0;
}

PartTime::PartTime(string myName, int myId, int mySeniority, int myHoursOfWork, float myPayPerHour)//parametrize constructor
{
	Employee(myName, myId, mySeniority);//����� ����
	if (hoursOfWork > 0)
		hoursOfWork = myHoursOfWork;
	else
	{
		throw "ERROR hoursOfWork";
		hoursOfWork = 0;
	}
	if (payPerHour > 0)
		payPerHour = myPayPerHour;
	else
	{
		throw "ERROR payPerHour";
		payPerHour = 0;
	}
	setPay(salary());
}

PartTime::PartTime(PartTime& pemp)//copy constructor
{
	Employee& newPemp = pemp;//����� ������ ���� ����
	Employee::Employee(newPemp);//����� ����� �� ����
	hoursOfWork = pemp.hoursOfWork;//����� ��� ������
	payPerHour = pemp.payPerHour;
}

void PartTime::setHoursOfWork(int myHoursOfWork)//������� ����� ���� ���� �����
{
	if (myHoursOfWork > 0)
		hoursOfWork = myHoursOfWork;
	else
	{
		throw "ERROR hoursOfWork";
		hoursOfWork = 0;
	}
}

int PartTime::getHoursOfWork()//������� ����� ���� ���� �����
{
	return hoursOfWork;
}

void PartTime::setPayPerHour(float myPayPerHour)//������� ����� ��� ����
{
	if (myPayPerHour > 0)
		payPerHour = myPayPerHour;
	else
	{
		throw "ERROR payPerHour";
		payPerHour = 0;
	}
}

float PartTime::getPayPerHour()//������� ����� ��� ����
{
	return payPerHour;
}

float PartTime::salary()//������� ������ ������
{
	float salaryPerMonth = hoursOfWork * payPerHour;
	return salaryPerMonth;
}

ostream& operator<<(ostream& os,  PartTime& pemp)//������� �����
{
	os << "Employee: " << pemp.getName() << endl;
	os << "Employee ID: " << pemp.getId() << endl;
	os << "Years Seniority: " << pemp.getSeniority() << endl;
	os << "Hours: " << pemp.hoursOfWork << endl;
	os << "Salary per Month: " << pemp.salary() << endl;
	return os;
}

istream& operator>>(istream& is, PartTime& pemp)//������� �����
{
	string myName;
	int myId, mySeniority, myHoursOfWork;
	float myPayPerHour;
	cout << "Enter employee details :" << endl;
	is >> myName;
	pemp.setName(myName);
	is >> myId;
	pemp.setId(myId);
	is >> mySeniority;
	pemp.setSeniority(mySeniority);
	is >> myHoursOfWork;
	pemp.setHoursOfWork(myHoursOfWork);
	is >> myPayPerHour;
	pemp.setPayPerHour(myPayPerHour);
	pemp.setPay(pemp.salary());
	return is;
}
