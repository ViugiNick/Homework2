#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "hashtable.h"
#include <iostream>

class TestHashTable: public QObject
{
    Q_OBJECT

    public:
        explicit TestHashTable(QObject *parent = 0) : QObject(parent){}

    private slots:
        void init()
        {
            const int sizeOfTable = 100;
            main = new HashTable('*', sizeOfTable);
        }

        void testAdding()
        {
            QString tmp = "abacaba";
            main->add(tmp);

            QVERIFY(main->find(tmp));
        }

        void testDeleting()
        {
            QString tmp = "abacaba";
            //std::cerr << "!" << std::endl;
            main->add(tmp);
            main->print();
            //std::cerr << "!" << std::endl;
            main->del(tmp);
            main->print();
            //std::cerr << "!" << std::endl;
            QVERIFY(!main->find(tmp));
            //std::cerr << "!" << std::endl;
        }
    private:
        HashTable * main;
};
