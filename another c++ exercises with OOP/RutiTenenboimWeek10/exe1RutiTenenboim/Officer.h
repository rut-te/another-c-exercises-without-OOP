#pragma once
#include "Soldier.h"
class Officer:public Soldier
{
protected:
	int sociometricScore;
public:
	int getSociometricScore();
	Officer();
	Officer(int myId, string myFirstName, string myLastName, int myNumOfOperations, int mySociometricScore);
	virtual bool medal();
	virtual void print();
	virtual string soldierType();
};

