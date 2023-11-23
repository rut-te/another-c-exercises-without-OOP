#pragma once
#include<iostream>
using namespace std;
#include "PrivateSoldier.h"
class Commander:public PrivateSoldier
{
protected:
	bool combat;
public:
	Commander();
	Commander(int myId, string myFirstName, string myLastName, int myNumOfOperations, int* myGrades,bool myCombat);
	Commander(Commander&cs);
	Commander(Commander&& cs);
	bool getCombat();
	virtual void print();
	virtual string soldierType();
	virtual bool medal();
};

