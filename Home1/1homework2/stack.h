#pragma once

class Stack
{
    public:
        virtual ~Stack(){}
        virtual int size() = 0;
        virtual void push(int val) = 0;
        virtual void pop() = 0;
        virtual bool findInStack(int val) = 0;
        virtual void deleteStack() = 0;
        virtual void printStack() = 0;
};
