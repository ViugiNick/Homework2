#include "list.h"
#include "listelement.h"
#include <QString>
#pragma once

class singlyLinkedList : public List
{
    public:
        ~singlyLinkedList();
        int size();
        void insertToPosition(int pos, QString &val);
        void deleteOnPosition(int pos);
        void deleteList();
        void printList();
        bool findInList(QString &val);
        int positionInList(QString &val);
        ListElement * getHead();
    private:
        ListElement * head = new ListElement();
};

