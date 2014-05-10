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
            main.add(int(1e9));
            QVERIFY(main.sizeOfSet() == 1);
            QVERIFY(main.find(int(1e9)));
            main.clearSet();
        }

        void testBadDeleting()
        {
            main.add(1);
            try
            {
                main.deleteFromSet(2);
            }
            catch(SetErrors::NoSuchVal &)
            {
                std::cout << "!!!No such value!!!" << std::endl;
            }
            main.deleteFromSet(1);
            QVERIFY(main.sizeOfSet() == 0);
            main.clearSet();
        }

        void testDeleting()
        {
            main.add(1);
            main.deleteFromSet(1);
            QVERIFY(main.sizeOfSet() == 0);
        }

        void testIntersection()
        {
            MySet <int> tmp1;
            MySet <int> tmp2;

            tmp1.add(1);
            tmp1.add(2);

            tmp2.add(2);
            tmp2.add(3);

            main.intersectSet(tmp1, tmp2);

            std::cerr << main.sizeOfSet() << std::endl;

            QVERIFY(main.sizeOfSet() == 1);
            QVERIFY(main.find(2));
            main.clearSet();
        }

        void testUnion()
        {
            MySet <int> tmp1;
            MySet <int> tmp2;

            tmp1.add(1);
            tmp1.add(2);

            tmp2.add(2);
            tmp2.add(3);

            main.unionSet(tmp1, tmp2);

            QVERIFY(main.sizeOfSet() == 3);
            QVERIFY(main.find(1));
            QVERIFY(main.find(2));
            QVERIFY(main.find(3));
            main.clearSet();
        }

    private:
        MySet<int> main;
};
