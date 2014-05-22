#include "list.h"
#include "listelement.h"
#include <QString>
#pragma once

class SinglyLinkedList : public List
{
    public:
        ~SinglyLinkedList();
        int size();
        void insertToPosition(int pos, const QString &val);
        void deleteOnPosition(int pos);
        void deleteList();
        QString printList();
        bool findInList(const QString &val);
        int positionInList(const QString &val);
        ListElement * getHead();
    private:
        ListElement * head = new ListElement();
};

/*
virtual int size() = 0;
virtual void insertToPosition(int pos, QString &val) = 0;
virtual void deleteOnPosition(int pos) = 0;
virtual void deleteList() = 0;
virtual void printList() = 0;
virtual bool findInList(QString &val) = 0;
*/

