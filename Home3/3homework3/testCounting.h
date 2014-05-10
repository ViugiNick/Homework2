#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <iostream>
#include "calculator.h"

class TestCounting: public QObject
{
    Q_OBJECT

    public:
        explicit TestCounting(QObject *parent = 0) : QObject(parent){}

    private slots:
        void testSum()
        {
            QVERIFY(calculateValue("1+3", 3) == 4);
        }
        void testNeg()
        {
            QVERIFY(calculateValue("3-1", 3) == 2);
        }

        void testMult()
        {
            QVERIFY(calculateValue("2*3", 3) == 6);
        }

        void testDev()
        {
            QVERIFY(calculateValue("9/3", 3) == 3);
        }
};
