#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "uniquelist.h"
#include "singlylinkedlist.h"
#include <iostream>

using namespace UniqueListErrors;

class TestUniqueList: public QObject
{
    Q_OBJECT

    public:
        explicit TestUniqueList(QObject *parent = 0) : QObject(parent){}

    private slots:
        void init()
        {
            main = new UniqueList();
        }
        void cleanup()
        {
            delete main;
        }

        void testAdding()
        {
            main->addElement(0, int(1e9));
            try
            {
                main->addElement(0, int(1e9));
            }
            catch(FindEqualVal &)
            {
                std::cerr << "Secondary adding" << std::endl;
            }
            QVERIFY(main->size() == 1);
        }

        void testDeleting()
        {
            main->addElement(0, int(1e9));
            //std::cerr << "!";
            main->deleteElement(int(1e9));
            QVERIFY(main->size() == 0);
        }
        void testDoubleDeleting()
        {
            main->addElement(0, int(1e9));
            //std::cerr << "!";
            main->deleteElement(int(1e9));

            try
            {
                main->deleteElement(int(1e9));
            }
            catch(NoSuchVal &)
            {
                std::cerr << "No such value" << std::endl;
            }
            QVERIFY(main->size() == 0);
        }
    private:
        UniqueList * main;
};
