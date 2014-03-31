#include "arraystack.h"
#include "iostream"

arrayStack::~arrayStack()
{
    deleteStack();
}

int arrayStack::size()
{
    return currentLength;
}

int arrayStack::top()
{
    if (currentLength == 0)
        return -1;
    return mainArray[currentLength - 1];
}

void arrayStack::push(int val)
{
    mainArray[currentLength] = val;
    currentLength++;
}

void arrayStack::pop()
{
    currentLength--;
}

void arrayStack::deleteStack()
{
    delete[] mainArray;
    currentLength = 0;
}

void arrayStack::printStack()
{
    for(int i = 0; i < currentLength; i++)
    {
        std::cout << mainArray[i] << " ";
    }
    printf("\n");
}

bool arrayStack::findInStack(int val)
{
    for(int i = 0; i < currentLength; i++)
    {
        if(val == mainArray[i])
               return true;
    }
    return false;
}
