//Ruti Tenenboim 214360778
//sadna in c++
//week 7 exe1
//התוכנית מממשת מטריצה של שלוש צורות, עיגול משולש ומלבן
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
enum SHAPES { CIRCLE = 1, TRIANGLE = 3, RECTANGLE };
int main() {

	//השתמשתי בתוכנית הראשית הנתונהבדפי התרגיל והוספתי את הדברים הנדרשים
	int numShapes, choice;
	cout << "How many shapes you would like to define?\n";
	cin >> numShapes;
	Shape** shapes = new Shape * [numShapes];
	for (int i = 0; i < numShapes; i++) {
		cout << "Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4\n";
		cin >> choice;
		switch (choice) {
		case CIRCLE:
			float radius;
			cout << "Enter radius :\n";
			cin >> radius;
			shapes[i] = new Circle(radius);
			break;
		case TRIANGLE:
			shapes[i] = new Triangle();
			break;
		case RECTANGLE:
			shapes[i] = new Rectangle();
			break;
		default:
			cout << "invalid input\n";
			i--;
		}

	}

	for (int i = 0; i < numShapes; i++) {
		cout << *shapes[i] << " area is: " << shapes[i]->area() << endl;
		if (shapes[i]->isSpecial())
			shapes[i]->printSpecial();
	}
	return 0;
}

/*exemple:
How many shapes you would like to define ?
3
Which shape will you choose ? Circle - 1, Triangle - 3, Rectangle - 4
3
Enter values of  3 points :
	(0, 0) (1, 0) (1, 1)
	Which shape will you choose ? Circle - 1, Triangle - 3, Rectangle - 4
	1
	Enter radius :
4
Enter values of  1 points :
	(0, 0)
	Which shape will you choose ? Circle - 1, Triangle - 3, Rectangle - 4
	2
	invalid input
	Which shape will you choose ? Circle - 1, Triangle - 3, Rectangle - 4
	4
	Enter values of  4 points :
	(0, 0) (1, 0) (1, 1) (0, 1)
	points : (0, 0) (1, 0) (1, 1)  area is : 0.5
	points : (0, 0)  area is : 50.24
	A canonical circle with a radius 4
	points : (0, 0) (1, 0) (1, 1) (0, 1)  area is : 1
	Square with side length 1
	*/

