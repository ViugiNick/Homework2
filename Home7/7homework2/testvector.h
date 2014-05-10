#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "vector.h"
#include <iostream>

class TestVector: public QObject
{
    Q_OBJECT

public:
    explicit TestVector(QObject *parent = 0) : QObject(parent){}

private slots:

    void init()
    {
        curr.push_back(1);
        curr.push_back(4);
        curr.push_back(4);

        //std::cerr << "!" << std::endl;

        main = new Vector<int, 3, 0>(curr);
        //std::cerr << "!" << std::endl;
    }

    void testCostructor1()
    {
        for (int i = 0; i < sizeOfVector; i++)
            if (main->takeValOnPos(i) != curr[i])
                QVERIFY(false);

        QVERIFY(true);
    }

    void testConstructor2()
    {

        std::cerr << "!!!" << std::endl;
        Vector<int, 3, 0> tmp(*main);
        std::cerr << "!!!" << std::endl;
        for (int i = 0; i < sizeOfVector; i++)
        {
            std::cerr << i << std::endl;
            if (main->takeValOnPos(i) != tmp.takeValOnPos(i))
                QVERIFY(false);
        }
        QVERIFY(true);
    }

    void testSum()
    {
        std::vector<int> tmp;
        tmp.push_back(2);
        tmp.push_back(3);
        tmp.push_back(9);

        Vector<int, 3, 0> tmpVect(tmp);
        Vector<int, 3, 0> result(*main + tmpVect);

        QVERIFY(result.takeValOnPos(0) == 3 &&
                result.takeValOnPos(1) == 7 &&
                result.takeValOnPos(2) == 13);
    }

    void testIsNotZero()
    {
        QVERIFY(!main->isZero());
    }

    void testIsZero()
    {
        for (int i = 0; i < sizeOfVector; ++i)
            main->makeValOnPos(i, 0);
        QVERIFY(main->isZero());
    }

    void cleanup()
    {
        delete main;
    }

private:
    const int sizeOfVector = 3;
    std::vector<int> curr;
    Vector<int, 3, 0> * main;
};
