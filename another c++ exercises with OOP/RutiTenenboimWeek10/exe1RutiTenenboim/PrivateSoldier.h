#pragma once
#include "Soldier.h"
class PrivateSoldier: public Soldier
{
protected:
	int* grades;
	float average;
public:
	PrivateSoldier(PrivateSoldier& ps);
	PrivateSoldier(PrivateSoldier&& ps);
	PrivateSoldier();
	PrivateSoldier(int myId, string myFirstName, string myLastName, int myNumOfOperations,int myGrades[]);
	~PrivateSoldier();
	virtual bool medal();
	virtual void print();
	virtual string soldierType();
	void culAverage();
};

