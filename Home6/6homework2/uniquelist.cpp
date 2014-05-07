#include "singlylinkedlist.h"
#include "uniquelisterrors.h"
#include "uniquelist.h"
#include <iostream>

void UniqueList::addElement(int pos, int val) throw (UniqueListErrors::FindEqualVal)
{
    try
    {
        insertToPosition(pos, val);
    }
    catch(UniqueListErrors::FindEqualVal &)
    {
        std::cout << "!!!Value already exists!!!" << std::endl;
    }
}

void UniqueList::deleteElement(int val) throw (UniqueListErrors::NoSuchVal)
{
    //std::cerr << "!!!" << val << std::endl;
    try
    {
        deleteListElement(val);
    }
    catch(UniqueListErrors::NoSuchVal &)
    {
        std::cout << "!!!No such value!!!" << std::endl;
    }
};
