#ifndef LISTWITHARRAY_H
#define LISTWITHARRAY_H

#pragma once
#include "list.h"

class ListWithArray : public List
{
public:
    ~ListWithArray();
    int length();
    void insert(int pos, int val);
    void deleteElement(int pos);
    void deleteList();
    void printList();

private:
    const int maxN = 1000;
    int * mainArray = new int[maxN];
    int currentLength = 0;
};

#endif // LISTWITHARRAY_H
