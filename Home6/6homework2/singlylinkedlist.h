#include "list.h"
#include "listelement.h"
#pragma once

class SinglyLinkedList : public List
{
    public:
        ~SinglyLinkedList();
        int size();
        void insertToPosition(int pos, int val);
        void deleteOnPosition(int pos);

        void deleteListElement(int val);

        void deleteList();
        void printList();
        int positionInList(int val);
        bool findInList(int val);

    private:
        ListElement * head = new ListElement(-1);
};

