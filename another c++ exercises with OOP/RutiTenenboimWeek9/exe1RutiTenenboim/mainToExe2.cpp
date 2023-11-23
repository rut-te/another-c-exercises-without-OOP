#include <iostream>
using namespace std;
#include "Book.h"
#include "SearchTree.h"

int main()
{
	char tav;
	SearchTree<Book> books;
	Book b;
	cout << "enter a-e: " << endl;
	cin >> tav;
	while (tav != 'e')
	{
		switch (tav)
		{
		case 'a':
			cout << "enter a book" << endl;
			cin >> b;
			books.add(b);
			break;
			
		case 'b':
			cout << "enter a book" << endl;
			cin >> b;
			if (books.search(b))
				books.remove(b);
			else
				cout << "not exist" << endl;
			break;
		case 'c':
			cout << "enter a book" << endl;
			cin >> b;
			if (books.search(b))
				cout << "exist" << endl;
			else
				cout << "not exist" << endl;
			break;
		case 'd':
			books.inOrder();
			break;
		default:
			cout << "error" << endl;
			break;
		}
		cout << "enter a-e: " << endl;
		cin >> tav;
	}
	return 0;
}