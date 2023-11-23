//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//התוכנית מגדירה מחלקה של עובדים ולאחר מכן מגדירה 2 מחלקות של שתי סוגי עובדים שיורשות מהמחלקה של
//העובדים הראשית. התוכנית מבצעת פונקציות שונות חלקם בירושה וחלקם לא לפי הנדרש בשאלה
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Employee
{
private:
	string name;//שם העובד
	int id;//תעודת זהות
	int seniority;//שנות וותק
	float pay;//שכר לחודש
public:
	Employee();//constructor
	Employee(string myName, int myId, int mySeniority);//parametrize constructor
	Employee(Employee& emp);//copy constructor
	void setName(string myName);//פונקציה להכנסת שם העובד
	void setId(int myId);//פונקציה להכנסת תעודת זהות
	void setSeniority(int mySeniority);//פונקציה להכנסת וותק
	string getName();//פונקציה לקבלת שם העובד
	int getId();//פונקציה לקבלת תעודת זהות
	int getSeniority();//פונקציה לקבלת וותק
	float getPay();//פונקציה לקבלת שכר 
	float salaryAfterBonus();//פונקציה לחיושב שכר לאחר הבונוס
	friend ostream& operator<<(ostream& os, const Employee& emp);//אופרטור הדפסה
	friend istream& operator>>(istream& is, Employee& emp);//אופרטור קריאה
protected:
	void setPay(float myPay);//פונקציה להשמה שכר לחודש
};

