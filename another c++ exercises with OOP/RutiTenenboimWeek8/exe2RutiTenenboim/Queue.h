//Ruti Tenenboim 214360778
//sadna in c++
//week 8 exe 2
//����� ��� �"� ������ ������� ���
#pragma once
class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual bool isEmpty() const = 0;

};

