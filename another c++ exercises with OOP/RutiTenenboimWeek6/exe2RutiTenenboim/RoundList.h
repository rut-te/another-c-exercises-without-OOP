//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//������� ������ ����� �� ����� ������, ������ ����� ������� ����� 
#pragma once
#include "List.h"

class RoundList: public List
{

public:
	RoundList();//constructor
	RoundList(const RoundList&);//copy constructor
	~RoundList();//destuctor
	friend ostream& operator<<(ostream& os, const RoundList& rl);//������� �����
	void addToEnd(int val);//����� ����
	int search(int n);//����� ����� ����� ����� ������
	void add(int val);//����� ������
	int firstElement() const;//����� ���� ����� ������
	bool search(const int& value) const;//����� �� ��� ���� ������
	void removeFirst();//����� ����� ������
	void clear();//����� ������
	RoundList& operator=(const RoundList& l);//������� ����
	
};

