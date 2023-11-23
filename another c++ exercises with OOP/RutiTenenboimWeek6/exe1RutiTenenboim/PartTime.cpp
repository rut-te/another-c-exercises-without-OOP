//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//התוכנית מגדירה מחלקה של עובדים ולאחר מכן מגדירה 2 מחלקות של שתי סוגי עובדים שיורשות מהמחלקה של
//העובדים הראשית. התוכנית מבצעת פונקציות שונות חלקם בירושה וחלקם לא לפי הנדרש בשאלה
#include "PartTime.h"

PartTime::PartTime()//constructor
{
	Employee();//שליחה לאבא
	hoursOfWork = 0;
	payPerHour = 0;
}

PartTime::PartTime(string myName, int myId, int mySeniority, int myHoursOfWork, float myPayPerHour)//parametrize constructor
{
	Employee(myName, myId, mySeniority);//שליחה לאבא
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
	Employee& newPemp = pemp;//שמירה בטיפוס מסוג האבא
	Employee::Employee(newPemp);//שליחה לקופי של האבא
	hoursOfWork = pemp.hoursOfWork;//עדכון שאר הפרטים
	payPerHour = pemp.payPerHour;
}

void PartTime::setHoursOfWork(int myHoursOfWork)//פונקציה להשמה מספר שעות עבודה
{
	if (myHoursOfWork > 0)
		hoursOfWork = myHoursOfWork;
	else
	{
		throw "ERROR hoursOfWork";
		hoursOfWork = 0;
	}
}

int PartTime::getHoursOfWork()//פונקציה לקבלת מספר שעות עבודה
{
	return hoursOfWork;
}

void PartTime::setPayPerHour(float myPayPerHour)//פונקציה להשמת שכר לשעה
{
	if (myPayPerHour > 0)
		payPerHour = myPayPerHour;
	else
	{
		throw "ERROR payPerHour";
		payPerHour = 0;
	}
}

float PartTime::getPayPerHour()//פונקציה לקבלת שכר לשעה
{
	return payPerHour;
}

float PartTime::salary()//פונקציה לחישוב משכורת
{
	float salaryPerMonth = hoursOfWork * payPerHour;
	return salaryPerMonth;
}

ostream& operator<<(ostream& os,  PartTime& pemp)//אופרטור הדפסה
{
	os << "Employee: " << pemp.getName() << endl;
	os << "Employee ID: " << pemp.getId() << endl;
	os << "Years Seniority: " << pemp.getSeniority() << endl;
	os << "Hours: " << pemp.hoursOfWork << endl;
	os << "Salary per Month: " << pemp.salary() << endl;
	return os;
}

istream& operator>>(istream& is, PartTime& pemp)//אופרטור קריאה
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
