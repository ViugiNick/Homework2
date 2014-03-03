#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
#include "list.h"
#include "listelement.h"

class LinkedList : public List
{

public:
    ~LinkedList();
    int length();
    void insert(int pos, int val);
    void deleteElement(int pos);
    void deleteList();
    void printList();

private:
    ListElement * head = new ListElement(-1);
};

#endif // LINKEDLIST_H
