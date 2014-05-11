#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "singlylinkedlist.h"

class TestSinglyLinkedLists: public QObject
{
    Q_OBJECT

    public:
        explicit TestSinglyLinkedLists(QObject *parent = 0) : QObject(parent){}

    private slots:
        void init()
        {
            mainList = new SinglyLinkedList();
        }
        void cleanup()
        {
            delete mainList;
        }

        void testDeleting()
        {
            mainList->insertToPosition(0, int(1e9));
            mainList->deleteOnPosition(0);
            QVERIFY(mainList->size() == 0);
        }

        void testInserting()
        {
            const int sizeOfList = 100;

            for (int i = 0; i < sizeOfList; i++)
                mainList->insertToPosition(i, i);

            int currentSize = 0;
            for (int i = 0; i < sizeOfList; i++)
                if (mainList->findInList(i))
                    currentSize++;

            QVERIFY(currentSize == sizeOfList);
        }

    private:
        SinglyLinkedList * mainList;
};
