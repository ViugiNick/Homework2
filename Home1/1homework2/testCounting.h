#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "calculator.h"
#include <string>

class TestCounting: public QObject
{
    Q_OBJECT

    public:
        explicit TestCounting(QObject *parent = 0) : QObject(parent){}

    private slots:
        void testSum()
        {
            std::string str = "1+3";
	    QVERIFY(calculate(str, str.size()) ==  4);
        }

        void testNeg()
        {
            std::string str = "1-3";
	    QVERIFY(calculate(str, str.size()) == -2);
        }
	void testMult()
        {
            std::string str = "2*3";
	    QVERIFY(calculate(str, str.size()) == 6);
	}
        void testMult()
        {
            std::string str = "2*3";
	    QVERIFY(calculate(str, str.size()) == 6);
        }

    private:
        arrayStack * mainStack;
};
