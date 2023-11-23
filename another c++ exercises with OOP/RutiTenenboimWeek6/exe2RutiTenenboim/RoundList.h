//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//התוכנית מגדירה מחלקה של רשימה מעגלית, המחלקה יורשת מהמחלקה רשימה 
#pragma once
#include "List.h"

class RoundList: public List
{

public:
	RoundList();//constructor
	RoundList(const RoundList&);//copy constructor
	~RoundList();//destuctor
	friend ostream& operator<<(ostream& os, const RoundList& rl);//אופרטור הדפסה
	void addToEnd(int val);//הוספה לסוף
	int search(int n);//החזרת האיבר במקום שנשלח כפרמטר
	void add(int val);//הוספה להתחלה
	int firstElement() const;//בדיקה מיהו האיבר הראשון
	bool search(const int& value) const;//בדיקה אם ערך קיים ברשימה
	void removeFirst();//מחיקת האיבר הראשון
	void clear();//ניקוי הרשימה
	RoundList& operator=(const RoundList& l);//אופרטור השמה
	
};

