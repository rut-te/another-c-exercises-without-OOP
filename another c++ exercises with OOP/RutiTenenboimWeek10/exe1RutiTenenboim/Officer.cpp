#include "Officer.h"

int Officer::getSociometricScore()
{
    return sociometricScore;
}

Officer::Officer():Soldier()
{
	sociometricScore = 0;
}

Officer::Officer(int myId, string myFirstName, string myLastName, int myNumOfOperations, int mySociometricScore)
	:Soldier(myId,  myFirstName,  myLastName,  myNumOfOperations)
{
	sociometricScore = mySociometricScore;
}

bool Officer::medal()
{
	if (numOfOperations >= 2 && sociometricScore > 92)
		return true;
	return false;
}

void Officer::print()
{
	cout << "Officer" << endl;
	Soldier::print();
	cout << "sociometric score: " << sociometricScore << endl;
}

string Officer::soldierType()
{
	return "Officer";
}
