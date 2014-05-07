#include "stack.h"
#include "stackelement.h"
#pragma once

class arrayStack : public Stack
{
    public:
        ~arrayStack();
        int size();
        int top();
        void push(int val);
        void pop();
        void deleteStack();
        void printStack();
        bool findInStack(int val);

    private:
        const int maxN = 1000;
        int * mainArray = new int[maxN];
        int currentLength = 0;
};
