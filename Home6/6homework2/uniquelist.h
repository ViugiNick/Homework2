#include "singlylinkedlist.h"
#include "uniquelisterrors.h"

class UniqueList : public singlyLinkedList
{
    public:
        void addElement(int pos, int val) throw (UniqueListErrors::FindEqualVal);
        void deleteElement(int val) throw (UniqueListErrors::NoSuchVal);
};
