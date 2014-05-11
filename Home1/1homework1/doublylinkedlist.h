#include "list.h"
#include "listelement.h"
#pragma once

class DoublyLinkedList : public List
{
    public:
        ~DoublyLinkedList();
        int size();
        void insertToPosition(int pos, int val);
        void deleteOnPosition(int pos);
        void deleteList();
        void printList();
        bool findInList(int val);

    private:
        ListElement * head = new ListElement(-1);
};

