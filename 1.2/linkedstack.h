#include "stack.h"
#include "stackelement.h"
#pragma once

class linkedStack : public Stack
{
    public:
        ~linkedStack();
        int size();
        int top();
        void push(int val);
        void pop();
        void deleteStack();
        void printStack();
        bool findInStack(int val);

    private:
        StackElement * head = new StackElement(-1);
};
