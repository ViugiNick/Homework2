#pragma once

#include <QObject>
#include <QtTest/QTest>
#include "tictactoe.h"
#include <iostream>

class TestTic: public QObject
{
    Q_OBJECT

    public:
        explicit TestTic(QObject *parent = 0) : QObject(parent){}

    private slots:
        void init()
        {
            main = new TicTacToe();
        }
        void test1()
        {
            main->open(0, 0, 'O');
            main->open(1, 1, 'O');
            main->open(2, 2, 'O');

            main->open(0, 1, 'X');
            main->open(1, 0, 'X');

            QVERIFY(main->win('O', 3, 3));
        }
        void test2()
        {
            main->open(0, 2, 'O');
            main->open(1, 1, 'O');
            main->open(2, 0, 'O');

            main->open(0, 1, 'X');
            main->open(1, 2, 'X');

            QVERIFY(main->win('O', 3, 3));
        }
    private:
        TicTacToe * main;
};
