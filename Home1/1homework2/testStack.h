#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "arraystack.h"

class TestStack: public QObject
{
    Q_OBJECT

    public:
        explicit TestStack(QObject *parent = 0) : QObject(parent){}

    private slots:
        void init()
        {
            mainStack = new arrayStack();
        }
        void cleanup()
        {
            delete mainStack;
        }

        void testPushing()
        {
            mainStack->push(1);
            QVERIFY(mainStack->size() == 1);
        }

        void testPoping()
        {
            mainStack->push(1);
            mainStack->pop();
            QVERIFY(mainStack->size() == 0);
        }

        void testInserting()
        {
            const int sizeOfStack = 100;

            for (int i = 0; i < sizeOfStack; i++)
                mainStack->push(i);

            int currentSize = 0;
            for (int i = 0; i < sizeOfStack; i++)
                if (mainStack->findInStack(i))
                    currentSize++;

            QVERIFY(currentSize == sizeOfStack);
        }

    private:
        arrayStack * mainStack;
};
