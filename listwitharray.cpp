#include "listwitharray.h"
#include <iostream>

ListWithArray::~ListWithArray()
{
    deleteList();
}

int ListWithArray::length()
{
    return currentLength;
}

void ListWithArray::insert(int pos, int val)
{
    if (currentLength == maxN)
    {
        std::cerr << "Error. The maximum size is " << maxN;
        deleteList();
        exit(0);
    }
    int * temp = new int[maxN];

    for (int i = 0; i < pos; ++i)
        temp[i] = mainArray[i];

    temp[pos] = val;

    for (int i = pos; i < currentLength; ++i)
        temp[i + 1] = mainArray[i];

    currentLength++;

    for (int i = 0; i < currentLength; ++i)
        mainArray[i] = temp[i];

    delete[] temp;
}

void ListWithArray::deleteElement(int pos)
{
    if (currentLength <= pos)
    {
        std::cerr << "Error!!!";
        deleteList();
        exit(0);
    }
    int * temp = new int[maxN];

    for (int i = 0; i < pos; ++i)
        temp[i] = mainArray[i];
    for (int i = pos + 1; i < currentLength; ++i)
        temp[i - 1] = mainArray[i];

    currentLength--;

    for (int i = 0; i < currentLength; ++i)
        mainArray[i] = temp[i];
    delete[] temp;
}

void ListWithArray::deleteList()
{
    delete[] mainArray;
    currentLength = 0;
}

void ListWithArray::printList()
{
    for (int i = 0; i < currentLength; ++i)
    {
        std::cout << mainArray[i] << " ";
    }
}
