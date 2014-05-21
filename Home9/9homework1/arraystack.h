#pragma once
#include "stack.h"

class ArrayStack : public Stack
{
public:
    ArrayStack();
    void push(int value);
    int pop();
    bool isEmpty();
    void print();
    void deleteTop();
    int takeTop();

private:
    int stackElements[100];
    int top;
};