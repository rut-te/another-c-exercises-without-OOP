//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 1
//התוכנית מגדירה מחלקה של עובדים ולאחר מכן מגדירה 2 מחלקות של שתי סוגי עובדים שיורשות מהמחלקה של
//העובדים הראשית. התוכנית מבצעת פונקציות שונות חלקם בירושה וחלקם לא לפי הנדרש בשאלה

#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;
int main()
{
	//השתמשתי בתוכנית הראשית הנתונה בדפי התרגיל
	FullTime arrF[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}
	PartTime arrP[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl;
	}
	return 0;
}

//
//exemple(for 2 FullTime and 1 PartTime):
/*
Enter employee details :
ruti 123456789 3 36000
Enter employee details :
tamar 123456788 8 48000
Enter employee details :
shevi 112345678 4 160 35
Employee : ruti
Employee ID : 123456789
Years Seniority : 3
Salary per Month:: 3000
After Bonus : 3500
Employee : tamar
Employee ID : 123456788
Years Seniority : 8
Salary per Month:: 4000
After Bonus : 5000
Employee : shevi
Employee ID : 112345678
Years Seniority : 4
Hours : 160
Salary per Month : 5600
After Bonus : 6100
*/