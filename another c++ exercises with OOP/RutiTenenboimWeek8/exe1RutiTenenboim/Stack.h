#pragma once
//-------------------------------------------------------
//  class stack
//  abstract class - simply defines protocol for
//  stack operations	
//-------------------------------------------------------
template <class T>
class Stack
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T pop() = 0;
    virtual void push(T value) = 0;
    virtual T top() const = 0;
};
