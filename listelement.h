#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#pragma once
#include <iostream>
#include <cstdlib>

class ListElement
{
public:
    ListElement(int val);
    ListElement();
    int getValue();
    void makeValue(int val);
    void takeNext(ListElement * le);
    ListElement * goToNext();
    void printElement();

private:
    int value;
    ListElement * next = NULL;
};

#endif // LISTELEMENT_H
