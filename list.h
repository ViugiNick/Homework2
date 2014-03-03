#ifndef LIST_H
#define LIST_H

#pragma once

class List
{
public:
    virtual ~List(){}
    virtual int length() = 0;
    virtual void insert(int pos, int val) = 0;
    virtual void deleteElement(int pos) = 0;
    virtual void deleteList() = 0;
    virtual void printList() = 0;
};

#endif // LIST_H
