//Ruti Tenenboim 214360778
//sadna in c++
//week 8 exe 2
//מימוש תור ע"י מחסנית ומחסנית עזר
#pragma once
class Stack
{
    public:
        virtual void clear() = 0;
        virtual bool isEmpty() const = 0;
        virtual int pop() = 0;
        virtual void push(int value) = 0;
        virtual int top() const = 0;
   
};

