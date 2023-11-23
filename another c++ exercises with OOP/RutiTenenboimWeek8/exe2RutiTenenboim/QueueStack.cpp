//Ruti Tenenboim 214360778
//sadna in c++
//week 8 exe 2
//מימוש תור ע"י מחסנית ומחסנית עזר
#include "QueueStack.h"
#include "StackList.h"

QueueStack::QueueStack()
{
	data = new StackList();
}

void QueueStack::clear()
{
	while (!data->isEmpty())
		data->pop();
}

int QueueStack::dequeue()
{
	StackList data2;
	int temp;
	while (!data->isEmpty())
	{
		temp = data->pop();
		data2.push(temp);
	}
	int toDeq = data2.pop();
	while (!data2.isEmpty())
	{
		temp = data2.pop();
		data->push(temp);
	}
	return toDeq;
}

void QueueStack::enqueue(int value)
{

	data->push(value);
}

int QueueStack::front()
{
	StackList data2;
	int temp;
	while (!data->isEmpty())
	{
		temp = data->pop();
		data2.push(temp);
	}
	int front = data2.pop();
	data->push(front);
	while (!data2.isEmpty())
	{
		temp = data2.pop();
		data->push(temp);
	}
	return front;
}

bool QueueStack::isEmpty() const
{
	return data->isEmpty();
}
