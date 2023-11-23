#include "Commander.h"

Commander::Commander():PrivateSoldier()
{
	combat = false;
}

Commander::Commander(int myId, string myFirstName, string myLastName, int myNumOfOperations, int* myGrades, bool myCombat)
	:PrivateSoldier( myId,  myFirstName,  myLastName,  myNumOfOperations,  myGrades)
{
	combat = myCombat;
}

Commander::Commander(Commander& cs):PrivateSoldier(cs)
{
	combat = cs.combat;
}

Commander::Commander(Commander&& cs):PrivateSoldier(cs)
{
	combat = cs.combat;
}

bool Commander::getCombat()
{
	return combat;
}

void Commander::print()
{
	cout << "Commander" << endl;
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
	cout << "combat: ";
	if (combat == true)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

string Commander::soldierType()
{
	return "Commander";
}

bool Commander::medal()
{
	if (numOfOperations >= 7 && average > 90)
		if(combat)
			return true;
	return false;
}
