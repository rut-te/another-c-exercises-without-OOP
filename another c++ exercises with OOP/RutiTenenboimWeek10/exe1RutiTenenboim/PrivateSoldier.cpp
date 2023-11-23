#include "PrivateSoldier.h"

PrivateSoldier::PrivateSoldier(PrivateSoldier& ps)
{
	id = ps.id;
	lastName = ps.lastName;
	firstName = ps.firstName;
	numOfOperations = ps.numOfOperations;
	average = ps.average;
	grades = new int[numOfOperations];
	for (int i = 0; i < numOfOperations; i++)
	{
		grades[i] = ps.grades[i];
	}
}

PrivateSoldier::PrivateSoldier(PrivateSoldier&& ps)
{
	id = ps.id;
	lastName = ps.lastName;
	firstName = ps.firstName;
	numOfOperations = ps.numOfOperations;
	average = ps.average;
	grades = ps.grades;
	ps.grades = nullptr;
}

PrivateSoldier::PrivateSoldier():Soldier()
{
	grades = nullptr;
	average = 0;
}

PrivateSoldier::PrivateSoldier(int myId, string myFirstName, string myLastName, int myNumOfOperations, int myGrades[]) :Soldier(myId, myFirstName, myLastName, myNumOfOperations)
{
	grades = new int[numOfOperations];
	for (int i = 0; i < numOfOperations; i++)
	{
		grades[i] = myGrades[i];
	}
	culAverage();
}

PrivateSoldier::~PrivateSoldier()
{
	if (grades)
	{
		delete[]grades;
		grades = nullptr;
	}
}



bool PrivateSoldier::medal()
{
	if (numOfOperations >=10 && average > 95)
		return true;
	return false;
}

void PrivateSoldier::print()
{
	cout << "PrivateSoldier" << endl;
	Soldier::print();
	if (numOfOperations > 0)
	{
		cout << "grades: ";
		for (int i = 0; i < numOfOperations; i++)
		{
			cout << grades[i] << " ";
		}
		cout << endl;
	}
}

string PrivateSoldier::soldierType()
{
	return "PrivateSoldier";
}

void PrivateSoldier::culAverage()
{
	if (numOfOperations > 0) {
		int sum = 0;
		for (int i = 0; i < numOfOperations; i++)
		{
			sum += grades[i];
		}
		average = (float)sum / numOfOperations;
	}
}
