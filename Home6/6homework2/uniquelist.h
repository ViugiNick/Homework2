#include "singlylinkedlist.h"
#include "uniquelisterrors.h"

class UniqueList : public singlyLinkedList
{
    public:
        ///Method, to add element in unique list
	void addElement(int pos, int val) throw (UniqueListErrors::FindEqualVal);
        ///Method, to delete element from unique list
	void deleteElement(int val) throw (UniqueListErrors::NoSuchVal);
};
