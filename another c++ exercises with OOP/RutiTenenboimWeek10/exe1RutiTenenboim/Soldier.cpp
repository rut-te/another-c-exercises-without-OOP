#include "Soldier.h"

Soldier::Soldier(int myId, string myFirstName, string myLastName, int myNumOfOperations)
{
	id = myId;
	firstName = myFirstName;
	lastName = myLastName;
	numOfOperations = myNumOfOperations;
}

int Soldier::getId()
{
	return id;
}

string Soldier::getFirstName()
{
	return firstName;
}

string Soldier::getLastName()
{
	return lastName;
}

int Soldier::getnumOfOperations()
{
	return numOfOperations;
}

void Soldier::print()
{
	cout << "ID " << id<<endl;
	cout << "first name: " << firstName << endl;
	cout << "last name: " << lastName << endl;
	cout << "num operations: " << numOfOperations << endl;
}
