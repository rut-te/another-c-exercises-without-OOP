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
class PartTime :public Employee
{
private:
	int hoursOfWork;//מספר שעות העבודה
	float payPerHour;//שכר לשעה
public:
	PartTime();//costructor
	PartTime(string myName, int myId, int mySeniority, int myHoursOfWork, float myPayPerHour);//parametrize constructor
	PartTime(PartTime& femp);//copy constructor
	void setHoursOfWork(int myHoursOfWork);//פונקציה להשמה מספר שעות עבודה
	int getHoursOfWork();//פונקציה לקבלת מספר שעות עבודה
	void setPayPerHour(float myPayPerHour);//פונקציה להשמת שכר לשעה
	float getPayPerHour();//פונקציה לקבלת שכר לשעה
	float salary();//פונקציה לחישוב משכורת
	friend ostream& operator<<(ostream& os,  PartTime& pemp);//אופרטור הדפסה
	friend istream& operator>>(istream& is, PartTime& femp);//אופרטור קריאה
};

