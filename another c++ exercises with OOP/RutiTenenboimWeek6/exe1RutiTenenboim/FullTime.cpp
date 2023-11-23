//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//התוכנית מגדירה מחלקה של עובדים ולאחר מכן מגדירה 2 מחלקות של שתי סוגי עובדים שיורשות מהמחלקה של
//העובדים הראשית. התוכנית מבצעת פונקציות שונות חלקם בירושה וחלקם לא לפי הנדרש בשאלה
#include "FullTime.h"

FullTime::FullTime()//constructor
{
	Employee();//שליחה לאבא
	salaryPerYear = 0;
}

FullTime::FullTime(string myName, int myId, int mySeniority, float mySalaryPerYear)//parametrize constructor
{
	Employee(myName, myId, mySeniority);//שליחה לאבא
	if(mySalaryPerYear>0)
		salaryPerYear = mySalaryPerYear;
	else
	{
		throw "ERROR salaryPerYear";
		salaryPerYear = 0;
	}
	setPay(salary());//קריאה לפונקציה שמעדכנת את המשכורת
}

FullTime::FullTime(FullTime& femp)//copy constructor
{
	Employee &newFemp = femp;//שמירה במשתנה מטיפוס האבא
	Employee::Employee(newFemp);//שליחה לקופי של האבא
	salaryPerYear = femp.salaryPerYear;//עדכון הפריט שנוסף
}

void FullTime::setSalaryPerYear(float mySalaryPerYear)//פונקציה להשמה שכר לשנה
{
	if (mySalaryPerYear > 0)
		salaryPerYear = mySalaryPerYear;
	else
	{
		throw "ERROR salaryPerYear";
		salaryPerYear = 0;
	}
}

float FullTime::getSalaryPerYear()//פונקציה לקבלת שכר לשנה
{
	return salaryPerYear;
}

float FullTime::salary()//פונקציה לחישוב משכורת
{
	float salaryPerMonth = salaryPerYear / 12;
	return salaryPerMonth;
}

ostream& operator<<(ostream& os, FullTime& femp)//אופרטור הדפסה
{
	os << "Employee: " << femp.getName() << endl;
	os << "Employee ID: " << femp.getId() << endl;
	os << "Years Seniority: " << femp.getSeniority() << endl;
	os << "Salary per Month:: " << femp.salary() << endl;
	return os;
}

istream& operator>>(istream& is, FullTime& femp)//אופרטור קריאה
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
