#pragma once

#include <QObject>
#include <QtTest/QTest>
#include <iostream>
#include "tree.h"

class TestTree: public QObject
{
    Q_OBJECT

    public:
        explicit TestTree(QObject *parent = 0) : QObject(parent){}

    private slots:
        void test1()
        {
            Tree tree("(+ 2 5)");
            QCOMPARE(tree.calculateTree(), 7);
            QCOMPARE(tree.printTree(), std::string("(2 + 5)"));
        }

        void test2()
        {
            Tree tree("(- 2 5)");
            QCOMPARE(tree.calculateTree(), -3);
            QCOMPARE(tree.printTree(), std::string("(2 - 5)"));
        }

        void test3()
        {
            Tree tree("(* 2 5)");
            QCOMPARE(tree.calculateTree(), 10);
            QCOMPARE(tree.printTree(), std::string("(2 * 5)"));
        }

        void test4()
        {
            Tree tree("(* (+ 1 1) 2)");
            QCOMPARE(tree.calculateTree(), 4);
            QCOMPARE(tree.printTree(), std::string("((1 + 1) * 2)"));
        }
        void hardTest()
        {
            Tree tree("(* (+ (- 1 2) 3) (+ 1 (- 1 9)))");
            QCOMPARE(tree.calculateTree(), -14);
            QCOMPARE(tree.printTree(), std::string("(((1 - 2) + 3) * (1 + (1 - 9)))"));
        }

        void testNegativeNumbers()
        {
            Tree tree("(- -2 5)");
            QCOMPARE(tree.calculateTree(), -7);
            QCOMPARE(tree.printTree(), std::string("(-2 - 5)"));
        }
};
