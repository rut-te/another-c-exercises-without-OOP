//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//התוכנית מגדירה מחלקה של רשימה מעגלית, המחלקה יורשת מהמחלקה רשימה 
#include "RoundList.h"
#include <iostream>
using namespace std;
enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY, PRINT
};
int main() {
	//השתמשתי בתוכנית הראשית הנתונה בדפי התרגיל
	RoundList roundList;
	int choice;
	cout << "Enter your choice: \n";
	cin >> choice;
	
		while (choice != EXIT) {
			int num;
			switch (choice) {
			case ADD:
				cout << "Enter a number: \n";
				cin >> num;
				roundList.add(num);
				break;
			case ADD_TO_END:
				cout << "Enter a number: \n";
				cin >> num;
				roundList.addToEnd(num);
				break;
			case REMOVE_FIRST:
				roundList.removeFirst();
				break;
			case SEARCH:
				cout << "Enter a number: ";
				cin >> num;
				cout << roundList.search(num) << endl;
				break;
			case CLEAR:
				roundList.clear();
				break;
			case EMPTY:
				if (roundList.isEmpty())
					cout << "Empty" << endl;
				else
					cout << "Not empty" << endl;
				break;
			case PRINT:
				cout << roundList << endl;
				break;
			default: cout << "ERROR!" << endl;
			}
			cout << "Enter your choice: \n";
			cin >> choice;
		}
	
	
	return 0;
}

/*
exemlpe
Enter your choice :
1
Enter a number :
11
Enter your choice :
1
Enter a number :
10
Enter your choice :
2
Enter a number :
20
Enter your choice :
2
Enter a number :
21
Enter your choice :
7
10 11 20 21

Enter your choice :
6
Not empty
Enter your choice :
3
Enter your choice :
7
11 20 21

Enter your choice :
4
Enter a number : 1
20
Enter your choice :
5
Enter your choice :
6
Empty
Enter your choice :
0
*/