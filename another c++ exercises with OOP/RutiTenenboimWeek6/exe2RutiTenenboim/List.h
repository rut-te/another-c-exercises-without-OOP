//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//התוכנית מגדירה מחלקה של רשימה מעגלית, המחלקה יורשת מהמחלקה רשימה 
#pragma once
#include<iostream>
using namespace std;
//השתמשתי במחלקה של רשימה שהגדרתי בתרגיל בית 5
class List
{
protected:
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);//הוספה להתחלה
	int firstElement() const;//בדיקה מיהו האיבר הראשון
	bool search(const int& value) const;//בדיקה אם ערך קיים ברשימה
	bool isEmpty() const;//בדיקה אם הרשימה ריקה
	void removeFirst();//מחיקת האיבר הראשון
	void clear();//ניקוי הרשימה
	List& operator=(const List& l);//אופרטור השמה
	void insert(int key);//הוספת איבר
	void remove(int key);//מחיקת איבר
	friend ostream& operator<<(ostream& os, const List& l);//אופרטור הדפסה
	friend istream& operator>>(istream& is, List& l);//אופרטור הכנסה

protected:
	// data field
	Link* head;
};





