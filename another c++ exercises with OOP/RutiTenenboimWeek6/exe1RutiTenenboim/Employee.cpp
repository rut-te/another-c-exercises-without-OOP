//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//התוכנית מגדירה מחלקה של עובדים ולאחר מכן מגדירה 2 מחלקות של שתי סוגי עובדים שיורשות מהמחלקה של
//העובדים הראשית. התוכנית מבצעת פונקציות שונות חלקם בירושה וחלקם לא לפי הנדרש בשאלה
#include "Employee.h"
#include <string>
#include <iostream> 
using namespace std;

Employee::Employee()//constructor
{
	name = "";
	id = 0;
	seniority = 0;
	pay = 0;
}

Employee::Employee(string myName, int myId, int mySeniority)//parametrize constructor
{
	name = myName;
	if(myId>10000000&&myId<999999999)
		id = myId;
	else 
	{
		throw "ERROR id";
		id = 0;
	}
	if(mySeniority>0)
		seniority = mySeniority;
	else
	{
		throw "ERROR seniority";
		seniority = 0;
	}
	pay = 0;
}

Employee::Employee(Employee& emp)//copy constructor
{
	name = emp.name;
	id = emp.id;
	seniority = emp.seniority;
	pay = emp.pay;
}

void Employee::setName(string myName)//פונקציה להכנסת שם העובד
{
	name = myName;
}

void Employee::setId(int myId)//פונקציה להכנסת תעודת זהות
{
	if (myId > 10000000 && myId < 999999999)
		id = myId;
	else
	{
		throw "ERROR id";
		id = 0;
	}
}

void Employee::setSeniority(int mySeniority)//פונקציה להכנסת וותק
{
	if (mySeniority > 0)
		seniority = mySeniority;
	else
	{
		throw "ERROR seniority";
		seniority = 0;
	}
}

string Employee::getName()//פונקציה לקבלת שם העובד
{
	return name;
}

int Employee::getId()//פונקציה לקבלת תעודת זהות
{
	return id;
}

int Employee::getSeniority()//פונקציה לקבלת וותק
{
	return seniority;
}

float Employee::getPay()//פונקציה לקבלת שכר 
{
	return pay;
}

float Employee::salaryAfterBonus()//פונקציה לחיושב שכר לאחר הבונוס
{
	float salaryAfterBonus;
	if (seniority > 0 && seniority <= 5)
	{
		salaryAfterBonus = pay + 500;
	}
	if (seniority > 5)
	{
		float bonus = pay * 0.25;
		salaryAfterBonus = pay + bonus;
	}
	return salaryAfterBonus;
}

void Employee::setPay(float myPay)//פונקציה להשמה שכר לחודש
{
	pay = myPay;
}

ostream& operator<<(ostream& os, const Employee& emp)//אופרטור הדפסה
{
	os << "Employee: " << emp.name << endl;
	os << "Employee ID: " << emp.id << endl;
	os << "Years Seniority: " << emp.seniority << endl;
	return os;
}

istream& operator>>(istream& is, Employee& emp)//אופרטור קריאה
{
	int myId, mySeniority;
	cout << "Enter employee details :" << endl;
	is >> emp.name;
	is >> myId;
	emp.setId(myId);
	is>> mySeniority;
	emp.setSeniority(mySeniority);
	return is;
}
