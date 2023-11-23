#include <iostream>
using namespace std;
#include "Book.h"

int main()
{
	char tav;
	//Tree<Book> t;
	cout << "enter a-e: " << endl;
	cin >> tav;
	while (tav != 'e')
	{
		switch (tav)
		{
		case 'a':
			break;
		case 'b':
			break;
		case 'c':
			break;
		case 'd':
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