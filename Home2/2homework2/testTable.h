#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "consoleout.h"

class TestTable: public QObject
{
    Q_OBJECT

    public:
        explicit TestTable(QObject *parent = 0) : QObject(parent){}

    private slots:
        void init()
        {
        }
        void cleanup()
        {
        }

        void testing()
        {
            int size = 3;

            int ** inputArray = new int * [size];

            for (int i = 0; i < size; i++)
            {
                inputArray[i] = new int[size];
                for (int j = 0; j < size; ++j)
                    inputArray[i][j] = i * size + j;
            }

            // 0 1 2
            // 3 4 5
            // 6 7 8

            ConsoleWriter toConsole;
            toConsole.write(inputArray, size);
            for (int i = 0; i < size; i++)
                delete[] inputArray[i];

            delete[] inputArray;
        }
};

