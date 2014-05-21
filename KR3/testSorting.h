#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "sortingcomparator.h"
#include "intsortingcomparator.h"
#include "stringsortingcomparator.h"
#include "bsorter.h"
#include <iostream>
#include <string>
#include <vector>

const int sizeOfArray = 4;

using namespace std;

class TestSorting: public QObject
{
    Q_OBJECT

    public:
        explicit TestSorting(QObject *parent = 0) : QObject(parent){}

    private slots:
        void init()
        {
            main = new BSorter;
        }

        void cleanup()
        {
            delete main;
        }

        void testInt()
        {
            int * arr = new int[sizeOfArray];

            for(int i = 0; i < sizeOfArray; i++)
            {
                arr[i] = i;
                //cerr << i << " ";
            }
            //cerr << endl;

            IntSortingComparator tmpCompare;

            main->sort<int>(arr, sizeOfArray, tmpCompare);
            //for(int i = 0; i < sizeOfArray; i++)
            //{
            //    cerr << arr[i] << " ";
            //}
            //cerr << endl << endl;

            bool flag = true;
            for(int i = 1; i < sizeOfArray; i++)
                if(arr[i - 1] < arr[i])
                    flag = false;

            QVERIFY(flag);
            delete[] arr;
        }

        void testString()
        {
            string arr[] = {"abacaba", "dabacab", "abbcaba", "abacab"};
            vector <string> stringVect;
            stringVect.push_back("abacaba");
            stringVect.push_back("dabacab");
            stringVect.push_back("abbcaba");
            stringVect.push_back("abacab");

            StringSortingComparator tmpCompare;

            main->sort<string>(arr, sizeOfArray, tmpCompare);
            sort(stringVect.begin(), stringVect.end());

            //for(int i = 0; i < sizeOfArray; i++)
            //    cerr << "!" << stringVect[i] << "!" << " " << arr[i] << endl;

            for(int i = 0; i < sizeOfArray; i++)
            {
                QCOMPARE(stringVect[i], arr[i]);
            }
        }
    private:
            BSorter * main;
};
