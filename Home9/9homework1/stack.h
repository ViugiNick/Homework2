#pragma once
#include "iostream"

class Stack
{
public:
    virtual ~Stack();

    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;
    virtual void deleteTop() = 0;
    virtual int takeTop() = 0;
};