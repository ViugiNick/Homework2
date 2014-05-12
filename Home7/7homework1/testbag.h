#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "bag.h"
#include "bagerrors.h"

using namespace BagErrors;

class TestBag: public QObject
{
    Q_OBJECT

public:
    explicit TestBag(QObject *parent = 0) : QObject(parent){}

private slots:
    void init()
    {
        main = new Bag<int>();
    }

    void testAdding()
    {
        main->addElement(int(1e9));
        QVERIFY(main->find(int(1e9)));
    }

    void testDoubleAdding()
    {
        main->addElement(int(1e9));
        main->addElement(int(1e9));
        QVERIFY(main->count(int(1e9)) == 2);
    }

    void testDeleting()
    {
        main->addElement(int(1e9));
        main->deleteElement(int(1e9));
        QVERIFY(!main->find(int(1e9)));
    }
    void testDeleting2()
    {
        main->addElement(int(1e9));
        main->addElement(int(1e9));
        main->deleteElement(int(1e9));
        QVERIFY(main->count(int(1e9)) == 1);
    }

    void testDoubleDeleting()
    {
        main->addElement(int(1e9));
        main->deleteElement(int(1e9));

        try
        {
            main->deleteElement(int(1e9));
        }
        catch(NoSuchVal)
        {
            std::cerr << "No such val!!!" << std::endl;
        }
        QVERIFY(main->count(int(1e9)) == 0);
    }

    void cleanup()
    {
        delete main;
    }

private:
    Bag <int> * main;
};
