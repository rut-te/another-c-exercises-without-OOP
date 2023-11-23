//Ruti Tenenboim 214360778
//sadna in c++
//week 8 exe 2
//����� ��� �"� ������ ������� ���
#pragma once
#include "Queue.h"
#include "StackList.h"
class QueueStack:public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;

};

