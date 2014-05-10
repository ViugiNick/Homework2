#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "bag.h"

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
    void cleanup()
    {
        delete main;
    }

private:
    Bag <int> * main;
};
