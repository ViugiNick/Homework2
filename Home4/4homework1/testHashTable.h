#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "hashtable.h"
#include "tablerror.h"
#include <iostream>
#include <countinghash.h>

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

        void cleanup()
        {
            delete main;
        }

        void testAdding()
        {
            QString tmp = "abacaba";
            main->add(tmp);

            try
            {
                main->add(tmp);
            }
            catch(TableErrors::FindEqualVal)
            {
                std::cout << "!!!This value is already in hash table!!!" << std::endl;
            }

            QVERIFY(main->find(tmp));
        }

        void testDeleting()
        {
            QString tmp = "abacaba";
            main->add(tmp);
            QVERIFY(main->print() == "99 > abacaba ");
            main->del(tmp);
            try
            {
                main->del(tmp);
            }
            catch(TableErrors::NoSuchVal)
            {
                std::cout << "!!!No such value in hash table!!!" << std::endl;
            }
            QVERIFY(!main->find(tmp));
        }
        void testChangingHash()
        {
            QString tmp = "abacaba";
            main->add(tmp);
            //std::cerr << "!" << main->print().toStdString() << "!" << std::endl;
            QVERIFY(main->print() == "99 > abacaba ");
            int countHash1 = main->getHash(tmp);

            HashFunction *newFunction = new HashFunction('+', 100);

            main->changeHashFunction(newFunction);
            QVERIFY(main->print() == "83 > abacaba ");
            int countHash2 = main->getHash(tmp);

            QVERIFY(countHash1 != countHash2);
        }
    private:
        HashTable * main;
};
