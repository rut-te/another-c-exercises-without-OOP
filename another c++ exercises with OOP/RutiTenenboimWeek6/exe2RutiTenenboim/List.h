//Ruti Tenenboim 214360778
//sadna in c++
//week 6 exe 2
//������� ������ ����� �� ����� ������, ������ ����� ������� ����� 
#pragma once
#include<iostream>
using namespace std;
//������� ������ �� ����� ������� ������ ��� 5
class List
{
protected:
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);//����� ������
	int firstElement() const;//����� ���� ����� ������
	bool search(const int& value) const;//����� �� ��� ���� ������
	bool isEmpty() const;//����� �� ������ ����
	void removeFirst();//����� ����� ������
	void clear();//����� ������
	List& operator=(const List& l);//������� ����
	void insert(int key);//����� ����
	void remove(int key);//����� ����
	friend ostream& operator<<(ostream& os, const List& l);//������� �����
	friend istream& operator>>(istream& is, List& l);//������� �����

protected:
	// data field
	Link* head;
};





