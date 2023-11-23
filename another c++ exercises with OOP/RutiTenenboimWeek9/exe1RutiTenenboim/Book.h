#pragma once
#include <iostream>
using namespace std;
class Book
{
private:
	int code;
	string bookName;
	string authorName;
public:
	Book(int myCode = 0, string myBookName = "", string myAuthorName = "");
	bool operator==(Book b);
	bool operator!=(Book b);
	bool operator>(Book b);
	bool operator<(Book b);
	bool operator>=(Book b);
	bool operator<=(Book b);
	friend ostream& operator<<(ostream& os, const Book& b);
	friend istream& operator>>(istream& is, Book& b);
};

