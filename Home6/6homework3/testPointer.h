#pragma once
#include <QObject>
#include <QTest>
#include "sharedpointer.h"

class TestPointer : public QObject
{
    Q_OBJECT

    public:
        explicit TestPointer(QObject *parent = 0) : QObject(parent) {}

    private slots:
        void init()
        {
            main = new SharedPointer<int>(new int(239));
        }

        void testConstructor1()
        {
            SharedPointer<int> tmp(*main);

            QVERIFY(main->getCnt() == tmp.getCnt());
            QVERIFY(*main->getVal() == *tmp.getVal());
        }

        void testConstructor2()
        {
            SharedPointer<int> tmp(new int(239));
            tmp = *main;

            QVERIFY(main->getCnt() == tmp.getCnt());
            QVERIFY(*main->getVal() == *tmp.getVal());
        }

        void cleanup()
        {
            delete main;
        }

    private:
        SharedPointer<int> *main;
};
