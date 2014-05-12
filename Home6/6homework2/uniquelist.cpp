#include "singlylinkedlist.h"
#include "uniquelisterrors.h"
#include "uniquelist.h"
#include <iostream>

using namespace UniqueListErrors;

void UniqueList::addElement(int pos, int val) throw (FindEqualVal)
{
    if(findInList(val))
    {
        FindEqualVal error;
        throw error;
        return;
    }
    insertToPosition(pos, val);
}

void UniqueList::deleteElement(int val) throw (NoSuchVal)
{
    if(SinglyLinkedList::positionInList(val) == -1)
    {
        NoSuchVal error;
        throw error;
        return;
    }
    deleteListElement(val);
};
