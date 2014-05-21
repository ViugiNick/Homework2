#pragma once
#include "stack.h"

class PointerStack : public Stack
{
public:
    PointerStack();
    ~PointerStack();
    void push(int value);
    int pop();
    bool isEmpty();
    void print();
    void deleteTop();
    int takeTop();

private:
    struct StackElement
    {
        int value;
        StackElement *next;
    };

    StackElement *top;
};