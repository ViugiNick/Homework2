#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "bsorter.h"

class TestBSorter: public QObject
{
    Q_OBJECT

public:
    explicit TestBSorter(QObject *parent = 0) : QObject(parent){}

private slots:
    void reverseTest()
    {
        const int sizeOfArray = 100;
        int * mainArray = new int[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++)
            mainArray[i] = sizeOfArray - i - 1;

        BSorter bSorting;
        bSorting.sort(mainArray,sizeOfArray);

        bool isCorrect = true;

        for (int i = 0; i < sizeOfArray; ++i)
        {
            if(!(mainArray[i] == i))
                isCorrect = false;
        }

           QVERIFY(isCorrect);
           delete[] mainArray;
       }
};
