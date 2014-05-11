#include "stack.h"
#include "stackelement.h"
#pragma once

///Class, to work with stack, based on array
class arrayStack : public Stack
{
    public:
        ~arrayStack();
        ///Method, to count size of stack
        int size();
        ///Method, to count size of stack
        int top();
        ///Method, to push element to stack
        void push(int val);
        ///Method, pop element from stack
        void pop();
        ///Method, delete stack
        void deleteStack();
        ///Method, to print stack
        void printStack();
        bool findInStack(int val);

    private:
        const int maxN = 1000;
        int * mainArray = new int[maxN];
        int currentLength = 0;
};
