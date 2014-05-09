#include "arraystack.h"
#include "iostream"

ArrayStack::~ArrayStack()
{
    deleteStack();
}

int ArrayStack::size()
{
    return currentLength;
}

int ArrayStack::top()
{
    if (currentLength == 0)
        return -1;
    return mainArray[currentLength - 1];
}

void ArrayStack::push(int val)
{
    mainArray[currentLength] = val;
    currentLength++;
}

void ArrayStack::pop()
{
    currentLength--;
}

void ArrayStack::deleteStack()
{
    delete[] mainArray;
    currentLength = 0;
}

void ArrayStack::printStack()
{
    for(int i = 0; i < currentLength; i++)
    {
        std::cout << mainArray[i] << " ";
    }
    printf("\n");
}

bool ArrayStack::findInStack(int val)
{
    for(int i = 0; i < currentLength; i++)
    {
        if(val == mainArray[i])
               return true;
    }
    return false;
}
