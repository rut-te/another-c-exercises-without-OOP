#include "Soldier.h"
#include "PrivateSoldier.h"
#include "Officer.h"
#include "Commander.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
enum option {
	EXIT,	//	סיום התוכנית
	ADD_NEW_SOLDIER,	//	הוספת חייל חדש
	DESERVES_MEDAL,	//	הדפסת פרטי כל החיילים הזכאים לצל"ש
	HIGHEST_SOCIOMETRIC,	//הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	PRIVATE_MEDAL_COUNT,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	NONCOMBAT_COMMANDER,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	SUPER_SOLDIER,   //הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	REMOVE_OFFICER,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};
void add(vector<Soldier*>& p, Soldier*& s);    //השלם\י פרמטר- ווקטור או רשימה   
Soldier* highestSociometricScore(vector<Soldier*> vec);   //השלם\י פרמטר- ווקטור או רשימה  
void printMedalList(vector<Soldier*> vec);

int main()
{
	Soldier* s;
	// הצהרה על ווקטור או רשימה של חיילים
	vector <Soldier*> vec;
	int count = 0;
	vector<Soldier*>::iterator it1 = vec.begin();
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER: 
			add(vec, s);  //הוספת חייל חדש						
			break;
		case DESERVES_MEDAL:printMedalList(vec);  //הדפסת פרטי הזכאים לצל"ש
			break;
		case HIGHEST_SOCIOMETRIC:   //הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר 
			s = highestSociometricScore(vec); // השלם\י פרמטר-וקטור או רשימה
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			break;
		case PRIVATE_MEDAL_COUNT: 
			cout << "number of privates that received medals: ";
			count = 0;
			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[i]->soldierType() == "PrivateSoldier")
				{
					if (vec[i]->medal())
						count++;
				}
			}
			cout << count << endl;
			break;
		case NONCOMBAT_COMMANDER: 
			cout << "list of noncombat commanders: ";    //הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
			for (it1 = vec.begin(); it1 != vec.end(); it1++)
			{
				if ((*it1)->soldierType() == "Commander")
				{
					if (!(((Commander*)(*it1))->getCombat()))
					{
						cout << (*it1)->getFirstName() << "" << (*it1)->getLastName() << endl;
					}
				}
			}
			cout << endl;
			break;
		case SUPER_SOLDIER:
			if (count_if(vec.begin(), vec.end(), [](Soldier* s) {return s->getnumOfOperations() > 15; })) // קיים חייל שהשתתף יובתר מ- 15 מבצעים צבאיים
			cout << "there is at least one soldier that did more than 15 operations\n";
			else
			cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER://מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
			for (it1 = vec.begin(); it1 < vec.end(); it1++)
			{
				if (!(*it1)->getnumOfOperations()&&( * it1)->soldierType()=="Officer")
				{
					vec.erase(it1, it1 + 1);
					((PrivateSoldier*)(*it1))->culAverage();
				}
			}
			
			for (it1 = vec.begin(); it1 < vec.end(); it1++)
			{
				(*it1)->print();

			}
			break;
		}
		cout << "enter 0-7\n";
		cin >> op;
		
		
	}
	return 0;
}
	
void add(vector<Soldier*> &p, Soldier*&s){

	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";
	int chooses;
	cin >> chooses;
	int id, numOfOperations;
	string lastName, firstName;
	cout << "enter id, first name, last name and number of operations\n";
	cin >> id >> firstName >> lastName >> numOfOperations;
	switch (chooses)
	{
	case 1:
	{
		cout << "enter " << numOfOperations << " grades\n";
		int* grades = new int[numOfOperations];
		for (int i = 0; i < numOfOperations; i++)
		{
			cin >> grades[i];
		}
		s = new PrivateSoldier(id, firstName, lastName, numOfOperations, grades);
		break;
	}
	case 2:
	{
		cout << "enter 1 if the soldier is combat and 0 if not\n";
		int combat;
		cin >> combat;
		cout << "enter " << numOfOperations << " grades\n";
		int* grades = new int[numOfOperations];
		for (int i = 0; i < numOfOperations; i++)
		{
			cin >> grades[i];
		}
		s = new Commander(id, firstName, lastName, numOfOperations, grades, combat);
		break;
	}
	case 3:
	{
		cout << "enter the sociometric score\n";
		int sociometricScore;
		cin >> sociometricScore;
		s = new Officer(id, firstName, lastName, numOfOperations, sociometricScore);
		break;
	}
	default:
		cout << "error" << endl;
		break;
	}
	if (s)
	{
		p.push_back(s);
	}
}

Soldier* highestSociometricScore(vector <Soldier*> vec)
{
	int max = 0;
	Soldier* temp = new Officer();
	vector<Soldier*>::iterator it = vec.begin();
	for (; it < vec.end(); it++)
	{
		if ((*it)->soldierType() == "Officer")
		{
			if (((Officer*)(*it))->getSociometricScore() > max)
			{
				max = ((Officer*)(*it))->getSociometricScore();
				temp = (*it);
			}
		}
	}
	return temp;
}

void printMedalList(vector<Soldier*> vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->medal())
		{
			vec[i]->print();
		}
	}
}










