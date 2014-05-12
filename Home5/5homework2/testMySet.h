#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "myset.h"
#include "iostream"
#include "myseterror.h"

class TestMySet: public QObject
{
    Q_OBJECT

    public:
        explicit TestMySet(QObject *parent = 0) : QObject(parent){}

    private slots:
        void testAdding()
        {
            int tmpVal = (int)1e9;
            main.add(tmpVal);
            QVERIFY(main.sizeOfSet() == 1);
            QVERIFY(main.find(tmpVal));
            main.clearSet();
        }

        void testBadDeleting()
        {
            int tmpVal = 1;
            int tmpVal2 = 2;

            main.add(tmpVal);
            try
            {
                main.deleteFromSet(tmpVal2);
            }
            catch(SetErrors::NoSuchVal &)
            {
                std::cout << "!!!No such value!!!" << std::endl;
            }
            main.deleteFromSet(tmpVal);
            QVERIFY(main.sizeOfSet() == 0);
            main.clearSet();
        }

        void testDeleting()
        {
            int tmpVal = 1;
            main.add(tmpVal);
            main.deleteFromSet(tmpVal);
            QVERIFY(main.sizeOfSet() == 0);
        }

        void testIntersection()
        {
            MySet <int> tmp1;
            MySet <int> tmp2;

            int val1 = 1;
            int val2 = 2;
            int val3 = 3;

            tmp1.add(val1);
            tmp1.add(val2);

            tmp2.add(val2);
            tmp2.add(val3);

            main.intersectSet(tmp1, tmp2);

            std::cerr << main.sizeOfSet() << std::endl;

            QVERIFY(main.sizeOfSet() == 1);
            QVERIFY(main.find(val2));
            main.clearSet();
        }

        void testUnion()
        {
            MySet <int> tmp1;
            MySet <int> tmp2;

            int val1 = 1;
            int val2 = 2;
            int val3 = 3;

            tmp1.add(val1);
            tmp1.add(val2);

            tmp2.add(val2);
            tmp2.add(val3);

            main.unionSet(tmp1, tmp2);

            QVERIFY(main.sizeOfSet() == 3);
            QVERIFY(main.find(val1));
            QVERIFY(main.find(val2));
            QVERIFY(main.find(val3));
            main.clearSet();
        }

    private:
        MySet<int> main;
};
