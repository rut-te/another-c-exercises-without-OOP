#include "Book.h"

Book::Book(int myCode, string myBookName, string myAuthorName)
{
	if (myCode > 0)
		code = myCode;
	else
		throw "error";
	bookName = myBookName;
	authorName = myAuthorName;
}

bool Book::operator==(Book b)
{
	if (b.authorName == authorName)
	{
		if (b.bookName == bookName)
		{
			if (b.code == code)
				return true;
		}
	}
	return false;
}

bool Book::operator!=(Book b)
{
	return !( * this == b);
}

bool Book::operator>(Book b)
{
	if (authorName > b.authorName)
		return true;
	if (authorName == b.authorName)
	{
		if (bookName > b.bookName)
			return true;
		if (bookName == b.bookName)
		{
			if (code > b.code)
				return true;
		}
	}
	return false;
}

bool Book::operator<(Book b)
{
	return !(*this>b);
}

bool Book::operator>=(Book b)
{
	return !(*this<b);
}

bool Book::operator<=(Book b)
{
	return !(*this>b);
}

ostream& operator<<(ostream& os, const Book& b)
{
	os << b.code << " " << b.bookName << " " << b.authorName << endl;
	return os;
}

istream& operator>>(istream& is, Book& b)
{
	int myCode;
	is >> myCode;
	if (myCode > 0)
		b.code = myCode;
	else
		b.code = 0;
	is >> b.bookName;
	is >> b.authorName;
	return is;
}
