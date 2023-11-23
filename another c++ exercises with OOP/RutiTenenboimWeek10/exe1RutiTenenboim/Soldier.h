#pragma once
#include <iostream>
using namespace std;

class Soldier
{
protected:
	int id;
	string firstName;
	string lastName;
	int numOfOperations;
public:
	Soldier() { id = 0, firstName = "", lastName = "", numOfOperations = 0; };
	Soldier(int myId, string myFirstName, string myLastName, int myNumOfOperations);
	int getId();
	string getFirstName();
	string getLastName();
	int getnumOfOperations();
	virtual ~Soldier(){};
	virtual bool medal()=0;
	virtual void print();
	virtual string soldierType() = 0;
};

