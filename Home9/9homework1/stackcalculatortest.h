#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "arraystack.h"
#include "pointerstack.h"

class StackCalculatorTest : public QObject
{
    Q_OBJECT

public:    
    explicit StackCalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testArrayIsEpmty()
    {
        QVERIFY(pointerStack->isEmpty());
    }

    void testArrayPopFromEmptyStack()
      {
          QVERIFY(arrayStack->pop() == INT_MIN);
      }

      void testArrayPush()
      {
          arrayStack->push(1);
          QVERIFY(arrayStack->takeTop() == 1);
      }

      void testArrayPop()
      {
          arrayStack->push(2);
          QVERIFY(arrayStack->pop() == 2);
      }

      void testPointerIsEpmty()
      {
          QVERIFY(pointerStack->isEmpty());
      }

      void testPointerPopFromEmptyStack()
        {
            QVERIFY(pointerStack->pop() == INT_MIN);
        }

        void testPointerPush()
        {
            pointerStack->push(1);
            QVERIFY(pointerStack->takeTop() == 1);
        }

        void testPointerPop()
        {
            pointerStack->push(2);
            QVERIFY(pointerStack->pop() == 2);
        }

private:
      Stack *pointerStack = new PointerStack();
      Stack *arrayStack = new ArrayStack();
};