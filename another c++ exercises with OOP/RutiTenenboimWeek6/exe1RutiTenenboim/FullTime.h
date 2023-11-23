//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//התוכנית מגדירה מחלקה של עובדים ולאחר מכן מגדירה 2 מחלקות של שתי סוגי עובדים שיורשות מהמחלקה של
//העובדים הראשית. התוכנית מבצעת פונקציות שונות חלקם בירושה וחלקם לא לפי הנדרש בשאלה
#pragma once
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;
class FullTime:public Employee
{
private:
	float salaryPerYear;//שכר לשנה
public:
	FullTime();//constructor
	FullTime(string myName, int myId, int mySeniority,float mySalaryPerYear);//parametrize constructor
	FullTime(FullTime& femp);//copy constructor
	void setSalaryPerYear(float mySalaryPerYear);//פונקציה להשמה שכר לשנה
	float getSalaryPerYear();//פונקציה לקבלת שכר לשנה
	float salary();//פונקציה לחישוב משכורת
	friend ostream& operator<<(ostream& os, FullTime& femp);//אופרטור הדפסה
	friend istream& operator>>(istream& is, FullTime& femp);//אופרטור קריאה
};

