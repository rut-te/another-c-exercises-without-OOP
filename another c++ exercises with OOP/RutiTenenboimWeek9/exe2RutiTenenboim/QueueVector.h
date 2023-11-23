#pragma once
#include "Queue.h"

template <class T>
class QueueVector : public Queue<T> {
public:
	// constructor requires a starting size
	/*QueueVector() {}*/
	QueueVector(int max = 100);
	/*QueueVector(const QueueVector&);*/

	// implement Queue protocol
	void clear() override;
	T dequeue() override;
	void enqueue(T value) override;
	T front() const override;
	bool isEmpty() const override;

private:
	T* data;
	int capacity;
	int nextSlot; //current next empty place/slot
	int firstUse; //current first place in the Q
};

#include "QueueVector.h"
//== class QueueVector implementation ==

template <class T>
QueueVector<T>::QueueVector(int size)
{
	capacity = size + 1;
	data = new T[capacity];
	clear();
}

//template <class T>
//QueueVector<T>::QueueVector(const QueueVector& v)
//	: data(v.data), nextSlot(v.nextSlot), firstUse(v.firstUse)
//{    // no further initialization  }
//
//}
template<class T>
inline void QueueVector<T>::clear()
{
	nextSlot = 0;
	firstUse = 0;
}
template <class T>
T QueueVector<T>::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity;
	return data[dataloc];
}

template <class T>
void QueueVector<T>::enqueue(T val)
{
	if ((nextSlot + 1) % capacity == firstUse)
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}

template <class T>
T QueueVector<T>::front() const
{
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}

template <class T>
bool QueueVector<T>::isEmpty() const
{
	return nextSlot == firstUse;
}
