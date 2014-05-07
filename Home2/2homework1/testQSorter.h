#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "qsorter.h"
#include "algorithm"
#include <time.h>

class TestQSorter: public QObject
{
    Q_OBJECT

public:
    explicit TestQSorter(QObject *parent = 0) : QObject(parent){}

private slots:
    void reverseTest()
    {
        const int sizeOfArray = 100;
        int * mainArray = new int[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++)
            mainArray[i] = sizeOfArray - i - 1;

        QSorter qSorting;
        qSorting.sort(mainArray,sizeOfArray);

        bool isCorrect = true;

        for (int i = 0; i < sizeOfArray; ++i)
        {
            if(!(mainArray[i] == i))
                isCorrect = false;
        }

           QVERIFY(isCorrect);
           delete[] mainArray;
    }

    void hardTest()
    {
        const int sizeOfArray = 10;
        int * mainArray = new int[sizeOfArray];
        int * ourArray = new int[sizeOfArray];

        srand (time(NULL));

        for (int i = 0; i < sizeOfArray; i++)
        {
            ourArray[i] = rand() % 100 + 1;
            mainArray[i] = ourArray[i];
        }
        QSorter qSorting;
        qSorting.sort(mainArray,sizeOfArray);
        std::sort(ourArray, ourArray + sizeOfArray);

        bool isCorrect = true;

        for (int i = 0; i < sizeOfArray; ++i)
        {
            if(!(mainArray[i] == ourArray[i]))
                isCorrect = false;
        }

           QVERIFY(isCorrect);
           delete[] mainArray;
    }
};
